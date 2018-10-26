////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Performance Lab 8-1 /////////////////////////////
///////////////////////////////////// "Healthy Substitutions" //////////////////////
//////////////////////////////////// EASY STUDENT TEMPLATE ///////////////////////////
////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <string.h>
#define ERR_NULL_POINTER -1		                // Error:  Pointer passed was NULL
#define ERR_NONE_FOUND 0		                // Error:  Character not found
#define ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
#define ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable

/*

int replace_char(char * buffer, char findChar, char replaceChar);
int clearInput();

int main(void)
{
	/* FUNCTION INPUT ARRAYS 
	char beforeString1[] = { "If debugging is the process of removing software bugs, then programming must be the process of putting them in.  -Edsger Dijkstra" }; // No newlines
	char * beforeStringArray[] = { beforeString1 };

	char userChar = 0; // Character to replace
	char replaceChar = 0; // Character replacing userChar
	int tempResults = 0;

	printf("Program: Healthy Substitutions. Press enter to continue!");
	clearInput();
	printf("What character would you like replaced?\n");
	userChar = getchar();
	printf("What character would you like to replace character %c with?\n", userChar);
	clearInput();
	replaceChar = getchar();

	// Implement for loop here for multiple strings
	tempResults = replace_char(beforeStringArray[0], userChar, replaceChar);

	// Check for errors
	if (tempResults > 0)
	{
		printf("\n\n\nThe new string is: \n");
		printf("%s\n", beforeStringArray[0]);
		printf("There were %d instances of %c replaced with %c.\n", tempResults, userChar, replaceChar);
	}
	else if (tempResults == ERR_NULL_POINTER)
	{
		printf("The string was empty");
	}
	else if (tempResults == ERR_NONE_FOUND)
	{
		printf("There were no instances of that character");
	}
	else if (tempResults == ERR_FIND_EQUALS_REPLACE)
	{
		printf("The character to replace was the same as the replace character");
	}
	else
	{
		printf("One of the characters entered were not printable");
	}

	while (1);
	return 0;
}

/*
* FUNCTION:   int replace_char(char * buffer, char findChar, char replaceChar)
*
* ARGUMENTS:  -buffer is a pointer to a null-terminated string
*              The string is passed by reference and modified in place
*              -findChar is a char to be found in the string
*              -replaceChar is the char to replace the findChar
*
* RETURNS:	   Number of characers replaced
*             ERR_NULL_POINTER if buffer == NULL
*             ERR_NONE_FOUND if no newlines are found
*             ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
*             ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable
*
* NOTES:      This function replaces instances of a userinputted character with another user inputted char

int replace_char(char * buffer, char findChar, char replaceChar)
{
	int count = 0;
	if (buffer)
	{
		size_t bufferLength = 0;
		int i = 0;

		bufferLength = strlen(buffer);
		for (i = 0; i < bufferLength; i++)
		{
			if (*buffer == findChar)
			{
				count++;
				*buffer = replaceChar;
			}
			buffer++;
		}

	}
	else
	{
		return ERR_NULL_POINTER;
	}

	if (count)
	{
		return count;
	}
	else
	{
		return ERR_NONE_FOUND;
	}
}


// This is an awesome function and useful if you need to clear the input buffer
int clearInput()
{
	while (getchar() != '\n');
}

*/

int replaceChar(*buffer, oldChar, newChar);
int clearInput();

int main(void)
{
	char beforeString1[] = { "Sometimes I feel I've got to run away, I've got to get away, from the pain you drive into the heart of me." }
	char * beforeStringArray[] = { beforeString1 };

	char oldChar;
	char newChar;
	int temp;

	printf("What letter would you like to replace?\n");
	oldChar = getchar();

	printf("What letter would you like to replace it with?\n");
	newChar = getchar();



}