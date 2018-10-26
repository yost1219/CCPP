#include <gmock\gmock.h>
#include <Windows.h>
#include "TestCode.h"
#include "RunCode.h"

#define FILE_NAME "out"

static inline void pasteName(char* buf, int num)
{
	if (NULL == buf)
		return;

	_snprintf(buf, MAX_PATH, "%s%d.txt", FILE_NAME, num);

}

TEST(TestSetThree, TestDecodeFromFile_GeneratedBuffer)
{
	char fname[MAX_PATH + 1] = { 0 };
	PBYTE buf;
	PVOID outBuf;
	unsigned long buflen;
	BYTE key;
	HANDLE hFile;

	pasteName(fname, 0);
	generateBuffer(&key, &buf, &buflen);
	ASSERT_EQ(ERROR_SUCCESS, openFile(&hFile, fname));
	ASSERT_EQ(ERROR_SUCCESS, writeStuffToFile(hFile, buf, buflen, key));
	CloseHandle(hFile);

	ASSERT_EQ(ERROR_SUCCESS, decodeFromFile(fname, buflen, key, &outBuf));
	ASSERT_EQ(ERROR_SUCCESS, strncmp((char*)buf, (char*)outBuf, buflen-1));

	ASSERT_TRUE(freeDecodedBuffer(outBuf));
	ASSERT_TRUE(DeleteFileA(fname));
}

TEST(TestSetThree, TestDecodeFromFile_BadFile)
{
	char fname[MAX_PATH + 1] = { 0 };
	PBYTE buf;
	PVOID outBuf;
	unsigned long buflen;
	BYTE key;
	HANDLE hFile;

	pasteName(fname, 1);
	generateBuffer(&key, &buf, &buflen);
	ASSERT_EQ(ERROR_SUCCESS, openFile(&hFile, fname));

	ASSERT_EQ(ERROR_SUCCESS, writeStuffToFile(hFile, buf, buflen, key));
	ASSERT_EQ(ERROR_OPEN_FAILED, decodeFromFile(fname, buflen, key, &outBuf));
	//ASSERT_TRUE(IsBadReadPtr(outBuf, buflen));

	cleanup(hFile, fname);
}

TEST(TestSetThree, TestDecodeFromFile_BadInput)
{
	char fname[MAX_PATH + 1] = { 0 };
	PBYTE buf = NULL;
	PVOID outBuf = NULL;
	unsigned long buflen;
	BYTE key;
	HANDLE hFile = INVALID_HANDLE_VALUE;

	pasteName(fname, 2);

	generateBuffer(&key, &buf, &buflen);
	ASSERT_EQ(ERROR_SUCCESS, openFile(&hFile, fname));
	ASSERT_EQ(ERROR_SUCCESS, writeStuffToFile(hFile, buf, buflen, key));
	CloseHandle(hFile);
	ASSERT_EQ(ERROR_INVALID_PARAMETER, decodeFromFile(NULL, buflen, key, &outBuf));
	ASSERT_TRUE(IsBadReadPtr(outBuf, buflen));
	ASSERT_EQ(ERROR_INVALID_PARAMETER, decodeFromFile(fname, buflen, key, NULL));
	ASSERT_EQ(ERROR_OPEN_FAILED, decodeFromFile("kajfskd", buflen, key, &outBuf));
	//ASSERT_TRUE(IsBadReadPtr(outBuf, buflen));
	ASSERT_TRUE(DeleteFileA(fname));
}


TEST(TestSetThree, TestDecodeFromFile_BadFree)
{
	ASSERT_FALSE(freeDecodedBuffer(NULL));
}

TEST(TestSetThree, TestDecodeFromFile_LgAlloc)
{
	char fname[MAX_PATH + 1] = { 0 };
	PBYTE buf;
	PVOID outBuf;
	unsigned long buflen;
	BYTE key;
	HANDLE hFile = INVALID_HANDLE_VALUE;

	pasteName(fname, 3);

	generateBuffer(&key, &buf, &buflen);
	ASSERT_EQ(ERROR_SUCCESS, openFile(&hFile, FILE_NAME));
	ASSERT_EQ(ERROR_SUCCESS, writeStuffToFile(hFile, buf, buflen, key));
	CloseHandle(hFile);
	ASSERT_EQ(ERROR_OUTOFMEMORY, decodeFromFile(FILE_NAME, (unsigned long)-1, key, &outBuf));
	//ASSERT_TRUE(IsBadReadPtr(outBuf, buflen));
	ASSERT_TRUE(DeleteFileA(FILE_NAME));
}