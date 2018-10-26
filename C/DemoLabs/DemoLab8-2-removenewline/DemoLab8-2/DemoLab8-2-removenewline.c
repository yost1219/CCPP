/*
Author: Yost
Title: Demo Lab 8.2
Date: 18 July 2018

*/

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// DEMONSTRATION LAB I.3.A-1 /////////////////////////////
///////////////////////////////////// "Newline Records" //////////////////////////////////
//////////////////////////////////// Instructor Solution /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// Do not modify main()
// Write the code body for the following function prototype:
//     int remove_newline(char * buffer);
// This function takes a pointer to a null-terminated string as a parameter
// This function must replace all newline characters with spaces
// The return value should represent the number of newline characters that were changed
//     with the following exceptions:
//         Return ERR_NULL_POINTER if the pointer to the string (buffer) is NULL
//         Return ERR_NONE_FOUND if no newlines are found
// Do not process a NULL string pointer (buffer)
//////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>
#define ERR_NULL_POINTER -1		// Error:  Pointer passed was NULL
#define ERR_NONE_FOUND 0		// Error:  Didn't find any newlines


int remove_newline(char * buffer);



int main(void)
{
	/* FUNCTION INPUT ARRAYS */
	char beforeString1[] = { "If debugging is the process of removing software bugs, then programming must be the process of putting them in.  -Edsger Dijkstra" }; // No newlines
	char beforeString2[] = { "Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live.\n-Martin Golding" }; // One newline
	char beforeString3[] = { "Debugging is twice as hard as writing the code in the first place.\nTherefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.\n-Brian W. Kernighan" }; // Two newlines
	char beforeString4[] = { "C makes it easy to shoot yourself in the foot;\nC++ makes it harder, but when you do,\nit blows away your whole leg.\n-Bjarne Stroustrup\n" }; // Four newlines
	char beforeString5[] = { "Talk\nis\ncheap.\nShow\nme\nthe\ncode.\n-Linus\nTorvalds\n" }; // Multiple newlines
	char * beforeString6 = NULL; // NULL Pointer
	char * beforeStringArray[] = { beforeString1, beforeString2, beforeString3, beforeString4, beforeString5, beforeString6 };

	/* FUNCTION OUTPUT COMPARISON */
	char afterString1[] = { "If debugging is the process of removing software bugs, then programming must be the process of putting them in.  -Edsger Dijkstra" }; // No newlines
	char afterString2[] = { "Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live. -Martin Golding" }; // One newline
	char afterString3[] = { "Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it. -Brian W. Kernighan" }; // Two newlines
	char afterString4[] = { "C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do, it blows away your whole leg. -Bjarne Stroustrup " }; // Four newlines
	char afterString5[] = { "Talk is cheap. Show me the code. -Linus Torvalds " }; // Multiple newlines
	char * afterString6 = NULL;
	char * afterStringArray[] = { afterString1, afterString2, afterString3, afterString4, afterString5, afterString6 };

	/* STRCMP FUNCTION EXPECTED RESULTS */
	int expectedFunctionResults[] = { ERR_NONE_FOUND, 1, 2, 4, 9, ERR_NULL_POINTER }; // Parallel array which holds expected return values of remove_newline() for given input

	int i = 0; // Iterating variable
	int tempResults = 0; // Temporarily holds function results until comparison can be done

						 /* TEST RUNS */
	for (i = 0; i < sizeof(beforeStringArray) / sizeof(*beforeStringArray); i++)
	{
		/* Test Run Header */
		printf("\nTEST #%d \n", i + 1);
		printf("__________________________________________________\n");

		/* Simultaneously modifies the strings and temporarily stores the return value */
		tempResults = remove_newline(beforeStringArray[i]);

		/* Verifies the return value of remove_newline() */
		printf("\tReturn Results:  ");
		if (expectedFunctionResults[i] == tempResults)
		{
			printf("\tPASS\n");
		}
		else
		{
			printf("\tFAIL\n");
		}

		/* Verifies remove_newline() performed adequately */
		printf("\tComparison Results:  ", tempResults);
		if (beforeStringArray[i]) // strcmp() doesn't like NULL pointers
		{
			/* Temporarily stores the retun value of strcmp() */
			tempResults = strcmp(beforeStringArray[i], afterStringArray[i]);
			if (!tempResults) // strcmp() returns 0 if the two strings match
			{
				printf("\tPASS\n"); // 0
			}
			else
			{
				printf("\tFAIL\n"); // 1
			}
		}
		else
		{
			printf("\tNo string present.\n"); // strcmp() doesn't like NULL pointers.  No comparison necessary.
		}
	}

	return 0;
}

/*
* FUNCTION:   int remove_newline(char * buffer)
*
* ARGUMENTS:  buffer is a pointer to a null-terminated string
*             The string is passed by reference and modified in place
*
* RETURNS:	   Number of newline characters that were replaced
*             ERR_NULL_POINTER if buffer == NULL
*             ERR_NONE_FOUND if no newlines are found
*
* NOTES:      This function replaces all newlines with spaces
*/




int remove_newline(char * buffer)
{
	int count = 0; // Number of newlines removed
	if (buffer)
	{
		/* LOCAL VARIABLE DECLARATION */
		size_t bufferLength = 0;
		int i = 0;

		/* FUNCTION ALGORITHM */
		bufferLength = strlen(buffer);			// Calculate length of input buffer
		for (i = 0; i < bufferLength; i++)		// Iterates through entire buffer
		{
			if (*buffer == '\n')				// Checks for newline characters
			{
				count++;						// Increment the number of newlines removed
				*buffer = ' ';					// Changes character to a space
			}
			buffer++;							// Increments to the next element in the string
		}
	}
	else
	{
		return ERR_NULL_POINTER;				// Because buffer is a NULL pointer
	}

	/* DYNAMIC RETURN VALUES */
	if (count)
	{
		return count;
	}
	else
	{
		return ERR_NONE_FOUND;					// Because the function found no newline characters
	}
	while (1);
	return 0;
}	