#include "header.h"
#include <stdio.h>
#include <string.h>

char *find_the_word(char *sentence_ptr, char *searchWord_ptr, int *errorCode_ptr);

int main(void)
{
	int i = 0;
	int numTestsRun = 0;
	int numTestsPassed = 0;
	int putErrorCodeHere = DEFAULT_ERROR_CODE;
	char *tempReturnValue_ptr = NULL;

	char testInput0[] = { "Good luck to you on this lab.\nI hope you do well." }; // Key: \n
	char testInput1[] = { "Normal test input.  'The' is the search key." }; // Key: The
	char testInput2[] = { "This is also normal input.  The 'bird' is the word." }; // Key: bird
																				   // Two strings that have duplicate keys
	char testInput3[] = { "This string is an example of a string that has two occurrences of the word 'is'." }; // Key: is
	char testInput4[] = { "The word 'the' is very common in the English language." }; // Key: the
																					  // Two strings that have multiple occurrences of the key
	char testInput5[] = { "Many English words are 'loan words', which is defined as 'a word that has been adopted from one language into another'." }; // Key: word
	char testInput6[] = { "The search keys don't have to be letters!  They could be any character or array of characters!  They could even be puntuation!  Maybe even non-printable characters!  Crazy, right?" }; // Key: "!  "
																																																				   // Two NULL strings to pass as sentence_ptr
	char * testInput7 = NULL; // Key: "Doesn't matter"
	char * testInput8 = NULL; // Key: "Don't bother"
							  // Two real strings to pass alongside a NULL searchWord
	char testInput9[] = { "It's a shame to waste a perfectly good sentence." }; // Key:  NULL
	char testInput10[] = { "It's a shame to waste a perfectly good null-terminated string." }; // Key:  NULL
																							   // Two real strings to pass alongside a NULL errorCode
	char testInput11[] = { "At least electrons are free." }; // Key: are
	char testInput12[] = { "Even if they're not free, there is are a plethora of electrons freely available." }; // Key: e
																												 // Two strings that will pass more NULL search keys
	char testInput13[] = { "You can't find a key here!" }; // Key: NULL
	char testInput14[] = { "Take a picture!  It'll last longer." }; // Key: NULL
																	// Two strings to pass long keys
	char testInput15[] = { "Now is the time for all good men to come to the aid of their country." }; // Key: "come to the aid"
	char testInput16[] = { "Sometimes it's hard to play the game the way it was intended to be played instead of following the game's rules as written." }; // Key: "play the game"
																																							// Edge cases that may break find_the_word()
	char testInput17[] = { "I hope you didn't find anything here!" }; // Key: '\0' (0x0)
	char testInput18[BUFF_SIZE] = { 0 }; // Key: "Don't do it!"
	char testInput19[] = { "Not a long string" }; // Key: "long string as a search key"
	char testInput20[] = { "part" }; // Key: "partial"
	char testInput21[BUFF_SIZE] = { 0 }; // Key: '\0' (0x0)
										 // Two strings whose keys are non printable characters
	char testInput22[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x0 }; // Key: 0x8
	char testInput23[] = { 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x0 }; // Key: 0x1C
																									// Two strings that include characters from the extended ASCII codes
	char testInput24[] = { '\n', 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, '\n', 0x7C, '$', '(', '5', ')', '$', 0x7C, '\n', 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, '\n', 0x0 }; // Key: 0xC4
																																												   //	puts(testInput24); // DEBUGGING
	char testInput25[] = { 0xC4, 0x5C, 0x5F, 0x2, 0x5F, 0x2F, 0xC4, 0x0 }; // Key: 0x2F
																		   //	puts(testInput25); // DEBUGGING
	char testInput26[] = { "Sometimes keys are at the beggining of a string." }; // Key: "Sometime"
	char testInput27[] = { "When you lose an item, you always find it in the last place you look." }; // Key: "look."

	char testKey0[] = { 10,0 };
	char testKey17[] = { 0x0, 0x0 };
	char testKey21[1] = { 0x0 };
	char testKey22[] = { 0x8, 0x0 };
	char testKey23[] = { 0x1C, 0x0 };
	char testKey24[] = { 0xC4, 0x0 };
	char testKey25[] = { 0x2F, 0x0 };

	struct FunctionTest test0 = { testInput0, testKey0, &putErrorCodeHere, &testInput0[29], ERROR_CODE_SUCCESS };
	struct FunctionTest test1 = { testInput1, "The", &putErrorCodeHere, &testInput1[21], ERROR_CODE_SUCCESS };
	struct FunctionTest test2 = { testInput2, "bird", &putErrorCodeHere, &testInput2[33], ERROR_CODE_SUCCESS };
	struct FunctionTest test3 = { testInput3, "is", &putErrorCodeHere, &testInput3[2], ERROR_CODE_SUCCESS };
	struct FunctionTest test4 = { testInput4, "the", &putErrorCodeHere, &testInput4[10], ERROR_CODE_SUCCESS };
	struct FunctionTest test5 = { testInput5, "word", &putErrorCodeHere, &testInput5[13], ERROR_CODE_SUCCESS };
	struct FunctionTest test6 = { testInput6, "!  ", &putErrorCodeHere, &testInput6[40], ERROR_CODE_SUCCESS };
	struct FunctionTest test7 = { NULL, "Doesn't matter", &putErrorCodeHere, testInput7, ERROR_NULL_SENTENCE_POINTER };
	struct FunctionTest test8 = { NULL, "Don't bother", &putErrorCodeHere, testInput8, ERROR_NULL_SENTENCE_POINTER };
	struct FunctionTest test9 = { testInput9, NULL, &putErrorCodeHere, NULL, ERROR_NULL_SEARCH_POINTER };
	struct FunctionTest test10 = { testInput10, NULL, &putErrorCodeHere, NULL, ERROR_NULL_SEARCH_POINTER };
	struct FunctionTest test11 = { testInput11, "are", NULL, NULL, DEFAULT_ERROR_CODE };
	struct FunctionTest test12 = { testInput12, "e", NULL, NULL, DEFAULT_ERROR_CODE };
	struct FunctionTest test13 = { testInput13, NULL, &putErrorCodeHere, NULL, ERROR_NULL_SEARCH_POINTER };
	struct FunctionTest test14 = { testInput14, NULL, &putErrorCodeHere, NULL, ERROR_NULL_SEARCH_POINTER };
	struct FunctionTest test15 = { testInput15, "come to the aid", &putErrorCodeHere, &testInput15[36], ERROR_CODE_SUCCESS };
	struct FunctionTest test16 = { testInput16, "play the game", &putErrorCodeHere, &testInput16[23], ERROR_CODE_SUCCESS };
	struct FunctionTest test17 = { testInput17, testKey17, &putErrorCodeHere, NULL, ERROR_SEARCH_NOT_FOUND };
	struct FunctionTest test18 = { testInput18, "Don't do it!", &putErrorCodeHere, NULL, ERROR_SEARCH_NOT_FOUND };
	struct FunctionTest test19 = { testInput19, "long string as a search key", &putErrorCodeHere, NULL, ERROR_SEARCH_NOT_FOUND };
	struct FunctionTest test20 = { testInput20, "partial", &putErrorCodeHere, NULL, ERROR_SEARCH_NOT_FOUND };
	struct FunctionTest test21 = { testInput21, testKey21, &putErrorCodeHere, NULL, ERROR_SEARCH_NOT_FOUND };
	struct FunctionTest test22 = { testInput22, testKey22, &putErrorCodeHere, &testInput22[7], ERROR_CODE_SUCCESS };
	struct FunctionTest test23 = { testInput23, testKey23, &putErrorCodeHere, &testInput23[2], ERROR_CODE_SUCCESS };
	struct FunctionTest test24 = { testInput24, testKey24, &putErrorCodeHere, &testInput24[17], ERROR_CODE_SUCCESS };
	struct FunctionTest test25 = { testInput25, testKey25, &putErrorCodeHere, &testInput25[5], ERROR_CODE_SUCCESS };
	struct FunctionTest test26 = { testInput26, "Sometime", &putErrorCodeHere, &testInput26[0], ERROR_CODE_SUCCESS };
	struct FunctionTest test27 = { testInput27, "look.", &putErrorCodeHere, &testInput27[64], ERROR_CODE_SUCCESS };

	struct FunctionTest testArray[28] = { test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12, test13, test14, test15, test16, test17, test18, test19, test20, test21, test22, test23, test24, test25, test26, test27 };
	
	int numTotalTests = sizeof(testArray) / sizeof(testArray[0]); //calc num of tests
	
	for (i + 0; i < numTotalTests; i++)
	{
		/* 0. TEST HEADER */
		printf("\n");
		printf("************\n");
		printf("* TEST #%02d *\n", i);
		printf("************\n");
		tempReturnValue_ptr = find_the_word((testArray + i)->sentence_ptr, (testArray + i)->searchWord_ptr, (testArray + i)->errorCode_ptr);

		/* 1. TEST RETURN VALUE */
		numTestsRun++;
		printf("\tReturn Value Test:\t");
		if (tempReturnValue_ptr == (testArray + i)->expectedReturn_ptr)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected pointer:\t%p\n", (testArray + i)->expectedReturn_ptr);
			printf("\t\tReceived pointer:\t%d\n", tempReturnValue_ptr);
		}

		/* 2. TEST ERROR CODE */
		numTestsRun++;
		printf("\tError Code Test:\t");
		if (putErrorCodeHere == (testArray + i)->expectedError_ptr)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected error code:\t%d\n", (testArray + i)->expectedError_ptr);
			printf("\t\tReceived error code:\t%d\n", putErrorCodeHere);
			if (putErrorCodeHere == DEFAULT_ERROR_CODE)
			{
				puts("\t\tError code not even updated!");
			}
		}

		putErrorCodeHere = DEFAULT_ERROR_CODE; // Reset error code
	}
	if (numTestsRun)
	{
		printf("\n\n\n*******************************\n");
		printf("Out of the %d tests that ran...\n", numTestsRun);
		printf("%d tests passed.\n", numTestsPassed);
		printf("*******************************\n");
	}
	while (1);
	return 0;
}

char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
{
	char testChar1 = 0; // DEBUGGING
	char testChar2 = 0; // DEBUGGING
	char * expectedReturn_ptr = NULL;
	int sentenceLength = 0;
	int searchWordLength = 0;
	int i = 0;
	int j = 0;

	if (!sentence_ptr)
	{
		expectedReturn_ptr = NULL;
		*errorCode_ptr = ERROR_NULL_SENTENCE_POINTER;
	}
	else if (!searchWord_ptr)
	{
		expectedReturn_ptr = NULL;
		*errorCode_ptr = ERROR_NULL_SEARCH_POINTER;
	}
	else if (!errorCode_ptr)
	{
		expectedReturn_ptr = NULL;
	}
	else
	{
		sentenceLength = strlen(sentence_ptr);
		searchWordLength = strlen(searchWord_ptr);
		// If it's longer... it obvs ain't found. 
		if (searchWordLength > sentenceLength)
		{
			expectedReturn_ptr = NULL;
			*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
		}
		else
		{
			*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
			for (i = 0; i <= (sentenceLength - searchWordLength); i++)
			{
				testChar1 = *(sentence_ptr + i);
				testChar2 = *(searchWord_ptr);
				if (*(sentence_ptr + i) == *(searchWord_ptr)) // If the first letter of the Key matches the current value...
				{
					if (searchWordLength == 1)
					{
						expectedReturn_ptr = (sentence_ptr + i);
						*errorCode_ptr = ERROR_CODE_SUCCESS;
						return expectedReturn_ptr;
					}
					else
					{
						for (j = 1; j < searchWordLength; j++) // ...check for the rest of the Key
						{
							if (*(sentence_ptr + i + j) != *(searchWord_ptr + j))
							{
								break; // No match
							}
							// Check last characters
							else if (j == (searchWordLength - 1))
							{
								expectedReturn_ptr = (sentence_ptr + i);
								*errorCode_ptr = ERROR_CODE_SUCCESS;
								return expectedReturn_ptr;
							}
						}
					}
				}
			}
		}
	}

	return expectedReturn_ptr;
}

/*
char *sentence_ptr;
char *searchWord_ptr;
int *errorCode_ptr;
char *expectedReturn_ptr;
int expectedError_ptr;
*/