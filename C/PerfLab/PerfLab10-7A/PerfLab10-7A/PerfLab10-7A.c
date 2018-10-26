/*
Author: Yost
Title: Perf Lab 10-7 A
Date: 24 July 2018

CONDITONAL COMPILATION

Redefine EOF as 66 (without compiler warnings)
Use preprocessor directive(s) to:
Only compile in "release" and only compile if _INC_STDIO is defined
Prints the name of a MACRO and also print the integer value of that MACRO
Use a #else 'fall through' for ease of use and safety
Use your preprocessor directives on FOPEN_MAX, FILENAME_MAX, and EOF

*/

#include <stdio.h>

#ifdef EOF //redefine EOF as 66 whether already defined or not
#undef EOF
#define EOF 66
#else
#define EOF 66
#endif

//#define DEBUG
#ifndef DEBUG
#ifdef _INC_STDIO
#define DEBUG(x) printf(#x " is %d.\n", x);
#else
return 0;
#endif
#endif

int main(void)
{
	DEBUG(EOF);

	while (1);
	return 0;
}