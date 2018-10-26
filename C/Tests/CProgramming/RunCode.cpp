#include "RunCode.h"


int getRawString(int index, PBYTE table, int len, PBYTE buffer)
{

	int status = ERROR_SUCCESS;
	PBYTE current = NULL;

	if (NULL == buffer || NULL == table || 0 == len)
		return ERROR_INVALID_PARAMETER;

	current = (PBYTE)table + index;
	
	memcpy(buffer, current, len);

	return status;
}



int generateBuffer(PBYTE key, PBYTE* buffer, PDWORD len)
{
	int status = ERROR_SUCCESS;
	DWORD randomSize;
	DWORD randomKey;
	BYTE val;
	PBYTE localBuf = NULL;

	if (NULL == key || NULL == buffer || NULL == len)
		return ERROR_INVALID_PARAMETER;

	srand(GetTickCount());

	randomSize = RAND_IN_RANGE(1024, 512);
	randomKey = RAND_IN_RANGE(0x7a, 0x41);

	if (NULL == (localBuf = (PBYTE)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, randomSize))) {
		return ERROR_OUTOFMEMORY;
	}


	memset(localBuf, 0x41, randomSize);

	*key = randomKey;
	*buffer = localBuf;
	*len = randomSize;

	return status;
}



int openFile(PHANDLE ph, char* filename)
{
	int status = ERROR_SUCCESS;
	HANDLE tmp;

	if (NULL == ph || NULL == filename)
		return ERROR_INVALID_PARAMETER;

	if (INVALID_HANDLE_VALUE == (tmp = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL))) {
		status = GetLastError();
	}

	*ph = tmp;

	return status;
}


	

int writeStuffToFile(HANDLE hf, PBYTE buffer, DWORD len, BYTE key)
{
	int status = ERROR_SUCCESS;
	DWORD numWritten;
	PBYTE current = NULL;

	if (NULL == buffer || INVALID_HANDLE_VALUE == hf)
		return ERROR_INVALID_PARAMETER;

	if (NULL == (current = (PBYTE)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, len))) {
		return ERROR_OUTOFMEMORY;
	}

	memcpy(current, buffer, len);

	for (int i = 0; i < len; ++i) {
		(BYTE)current[i] ^= key;

	}
	if (!WriteFile(hf, current, len, &numWritten, NULL)) {
		status = GetLastError();
	}

	return status;
}


void cleanup(HANDLE hf, char* name)
{
	if (INVALID_HANDLE_VALUE == hf || NULL == name)
		return;

	CloseHandle(hf);
	DeleteFileA(name);

}


static int addActionToList(DWORD action)
{
	srand(GetTickCount());
	int output = rand();

	EnterCriticalSection(&alLock);
	actions.insert(std::pair<DWORD, int>(action, output));
	LeaveCriticalSection(&alLock);

	return output;
}

static int fptr(DWORD act)
{
	int tmp;
	EnterCriticalSection(&alLock);

	auto i = actions.find(act);
	tmp = i->second;

	LeaveCriticalSection(&alLock);
	return tmp; //0x41;
}


static PCONTAINER generateEntry(PCONTAINER copyEntry)
{
	PCONTAINER tmp = NULL;

	if (NULL == copyEntry) {
		SetLastError(ERROR_INVALID_PARAMETER);
		return NULL;
	}

	if (NULL == (tmp = (PCONTAINER)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(CONTAINER)))) {
		SetLastError(ERROR_OUTOFMEMORY);
		return NULL;
	}

	memcpy(tmp, copyEntry, sizeof(CONTAINER));
	SecureZeroMemory(copyEntry, sizeof(CONTAINER));

	return tmp;
}


static DWORD populateEntry(PCONTAINER cont)
{

	if (NULL == cont) {
		return 0;
	}


	srand(GetTickCount());

	cont->id = rand();
	if (cont->id == (DWORD)-1)
		--cont->id;

	cont->type = (rand() % 2) ? TypeBitmask : TypeFuncPtr;
	if (cont->type == TypeBitmask)
		cont->u.bitmask = rand();
	else
		cont->u.func = fptr;

	return (DWORD)rand();
}


DWORD buildList(PSLIST_HEADER hlist, std::pair<DWORD, DWORD>& stuff)
{
	DWORD len = 0;
	CONTAINER cont = { 0 };
	PCONTAINER tmp = NULL;
	DWORD listAction = 0;
	
	std::pair<PCONTAINER, DWORD> info;

	DWORD numEntries = 0;
	if (NULL == hlist)
		return listAction;

	srand(GetTickCount());
	numEntries = RAND_IN_RANGE(20, 30);

	InitializeSListHead(hlist);
	Sleep(10);
	for (int i = 0; i < numEntries; ++i) {
		if (0 == (listAction = populateEntry(&cont))) {
			break;
		}

		if (NULL == (tmp = generateEntry(&cont))) {
			listAction = 0;
			break;
		}

		InterlockedPushEntrySList(hlist, &tmp->list);
		if (rand() % 2) {
			info.first = tmp;
			info.second = listAction;
		}
		Sleep(10);
	}

	if (NULL == info.first) {
		listAction = populateEntry(&cont);
		info.first = generateEntry(&cont);
		info.second = listAction;
		InterlockedPushEntrySList(hlist, &info.first->list);
	}

	
	if (info.first->type == TypeFuncPtr) {
		addActionToList(info.second);
	}
	else {
		info.first->u.bitmask = info.second;
		int op = addActionToList(info.second);

		info.first->u.bitmask ^= op;
	}

	stuff.first = info.first->id;
	stuff.second = info.second;

	return listAction;
}


int validatePair(DWORD act, int res)
{
	int status = ERROR_SUCCESS;

	EnterCriticalSection(&alLock);

	auto it = actions.find(act);
	if (it == actions.end())
		status = ERROR_NOT_FOUND;
	else if (it->first != act || it->second != res)
		status = ERROR_INVALID_PARAMETER;

	LeaveCriticalSection(&alLock);
	

	return status;
}

void gcList(PSLIST_HEADER hlist)
{

	PCONTAINER tmp = NULL;

	if (NULL == hlist)
		return;

	while (NULL != (tmp = (PCONTAINER)InterlockedPopEntrySList(hlist))) {
		HeapFree(GetProcessHeap(), 0, tmp);
	}

}


void initListProcessing()
{
	if (1 < InterlockedIncrement(&ref))
		return;

	InitializeCriticalSection(&alLock);
}

void finishListProcessing()
{
	if (InterlockedDecrement(&ref))
		return;

	DeleteCriticalSection(&alLock);

}


extern "C" void __declspec(dllexport) WINAPI derp(void)
{
	printf("Herp\n");
}