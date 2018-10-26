#pragma once

#include <Windows.h>
#include <stdio.h>
#include <map>
#include "TestCode.h"

#define RAND_IN_RANGE(x, minimum) rand() % x + minimum
static CRITICAL_SECTION alLock;
static std::map<DWORD, int> actions;
static volatile long ref = 0;


#ifdef __cplusplus
extern "C" {
#endif

	int getRawString(int index, PBYTE table, int len, PBYTE buffer);
	int generateBuffer(PBYTE key, PBYTE* buffer, PDWORD len);
	int openFile(PHANDLE ph, char* filename);
	int writeStuffToFile(HANDLE hf, PBYTE buffer, DWORD len, BYTE key);
	void cleanup(HANDLE hf, char* name);
	void initListProcessing();
	void finishListProcessing();
	DWORD buildList(PSLIST_HEADER hlist, std::pair<DWORD,DWORD>& stuff);
	void gcList(PSLIST_HEADER hlist);
	int validatePair(DWORD act, int res);

#ifdef __cplusplus
}
#endif