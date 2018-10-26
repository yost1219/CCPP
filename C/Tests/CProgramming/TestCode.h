#pragma once

#include <Windows.h>
#include <stdio.h>

typedef enum {
	TypeBitmask,
	TypeFuncPtr,
} StructType;

typedef struct {
	SLIST_ENTRY			list; // This is a Microsoft provided data structure containing a single item: a pointer to "Next"
	unsigned long		id;
	StructType			type;
	union {
		unsigned long	bitmask;
		int(*func)(unsigned long param);
	} u;
} CONTAINER, *PCONTAINER;

#ifdef __cplusplus
extern "C" {
#endif
	// Task One
	int deleteWord(char* sentence, char* deleteMe);
	// Task Three
	int decodeFromFile(char* filename, unsigned int sizeOfData, unsigned char key, void** buffPtr);
	BOOL freeDecodedBuffer(void* buffer);

#ifdef __cplusplus
}
#endif