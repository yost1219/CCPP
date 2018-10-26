/*
Author: Yost
Title: PL 2A
Date: 08 August 2018
*/

/*
Provided a text file, use the STL to read from it and count each occurrence of each word. 
Once complete, output to **stdout **each word, and the number of times it occurred. 
Sort the output by words that occured the most to words that occured the least.

The instructional goal of this lab is to give you practice using the STL. 
Use STL containers, algorithms, and iterators where they would be helpful.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main()
{
	std::map<std::string, int>word_search;	//first column of map is the word, second is the number
	std::ifstream file("lyrics.txt");		//opens text file
	if (file.is_open())						//if file opens successfully
	{
		while (file.good())
		{
			std::string word_buffer;		//make holding place for next word (only 1 string because I said so)					
			file >> word_buffer;			//put next word from file into buffer (only looks at 1 string because word_buffer can only hold a string)
			if (word_search.find(word_buffer) == word_search.end())	//if the word is unique to map...
			{
				word_search[word_buffer] = 1;						//add it to the map
			}
			else													//if the word is not unique to the map (aka has already been entered)...
			{
				word_search[word_buffer]++;							//then add to the number
			}
		}
	}
	else //can't find/open file
	{
		std::cout << "Unable to open file…";
	}

	for (std::map<std::string, int>::iterator i = word_search.begin(); i != word_search.end(); i++) //print the map
	{
		std::cout << i->first << " - " << i->second << '\n';
	}

	while (1);
	return 0;
}
