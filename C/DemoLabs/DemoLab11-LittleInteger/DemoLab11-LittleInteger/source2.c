/*
Author: Yost
Title: Demo Lab 11 - LittleInteger
Date: 25 July 2018
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// DEMONSTRATION LAB I.5.A-3 ////////////////////////////////////////////
////////////////////////////////////////////////// ADDRESS ARITHMETIC ///////////////////////////////////////////////
///////////////////////////////////////////// "The Little Integer That Could" ///////////////////////////////////////
////////////////////////////////////////////////// Instructor Solution //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// For the purposes of this lab, "natural number" is defined as:
//     A whole, positive integer greater than zero [1,2,3,4...]
// Define find_smallest_natural_number() as follows:
//     Return Value
//         int pointer to the smallest natural number found in the array at intArray_ptr
//         NULL if intArray_ptr is NULL
//         NULL if arraySize is unrealistic (less than 1)
//     Parameters -
//         intArray_ptr - Pointer to an array of integers...
//         arraySize - ...of this dimension
//     Purpose - Find the smallest natural number in the array found at intArray_ptr
//     Requirements - Only address arithmetic (AKA pointer math) is permitted to traverse the elements
//         of the int array found at intArray_ptr
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#define BUFFSIZE 255 //define constant

/*
* FUNCTION:   int * find_smallest_natural_number(int * intArray_ptr, int arraySize)
*
* ARGUMENTS:  intArray_ptr is an integer pointer to an integer array
*             arraySize represents the dimension of the integer array found at intArray_ptr
*
* RETURNS:	  integer pointer to the smallest natural number on success
*             NULL if intArray_ptr is NULL
*             NULL if arraySize is unrealistic (less than 1)
*
* NOTES:      This function must be defined entirely using address arithmetic (AKA pointer math)
*             No brackets [] may be used to reference data found within the array found at
*                 intArray_ptr
*/

int * find_smallest_natural_number(int * intArray_ptr, int arraySize); //prototype your seeking function

int main(void)

{
	int numberArray[BUFFSIZE] = { 5, 4, 3, 2, 1, 0, -1 };
	int * littlest_ptr = 0;
	littlest_ptr = *find_smallest_natural_number(numberArray, (int) BUFFSIZE);

	if (littlest_ptr) //if a natural number is returned, display it
	{
		printf("The smallest natural number in the array is %d.\n", littlest_ptr);
	}
	else //if no natural number is found, error
	{
		printf("Oops.  No value could be returned.\n");
	}
	while (1);
	return 0;
}

int * find_smallest_natural_number(int * intArray_ptr, int arraySize)
{
	int * return_ptr = 0; //return value
	int * temp_ptr = 0; //placeholder
	int i = 0; //incrementor

	if (!intArray_ptr) //return NULL if pointer is NULL
	{
		return_ptr = 0;
	}
	else if (arraySize < 1) //return NULL if arraySize is less than 1
	{
		return_ptr = 0;
	}
	else //else, return smallest natural number
	{
		temp_ptr = intArray_ptr; //initialize temp_ptr to first value in array

		for (i = 0; i < arraySize; i++)
		{
			if (*(intArray_ptr + i) < *(temp_ptr) && *(intArray_ptr + i) > 0) //if value is smaller than last placeholder AND greater than 0
			{
				temp_ptr = (intArray_ptr + i); //set temp equal to current value
			}			
		}
		return_ptr = temp_ptr; //overwrite smallest pointer with new smallest pointer
	}
	return return_ptr;
}
