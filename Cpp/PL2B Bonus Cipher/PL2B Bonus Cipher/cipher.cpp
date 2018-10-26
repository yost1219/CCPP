/*
Author: Yost
Title: PL2B Bonus - Cipher
Date: 9 August 2018
*/

/*
Open a file
Read the file
Pass the file through the encoder
Save the encoded message to a new file
also
Open a file
Read the file
Pass the file through the decoder
Save the decoded message to a new file
*/

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	//open a file
	std::ifstream plain("plain.txt");
	std::ofstream coded("coded.txt");
	std::string line;

	if (plain.is_open()) //make sure file is open
	{
		if (coded.is_open())
		{

			//read the file line by line
			while (plain.good())
			{

				//run through cipher
				std::string word;
				std::string buffer_string;
				std::string output_string;

				plain >> word;
				char buffer_char;
				int word_length = 0;
				word_length = word.length();
				buffer_string = word;

				for (int i = 0; i < word_length; i++)
				{
					buffer_char = buffer_string.at(0);
					output_string.push_back(buffer_char - 17);
					buffer_string = buffer_string.substr(1);
				}
				std::cout << output_string << " "; //outputs each word, run through cipher, separated by a space
				//coded.append(output_string);

				coded << output_string << " "; //write to file

				/*std::ofstream file("coded.txt");
				if (file.is_open)
				{
					file << "boohoo";
					//file << output_string << " ";
					//file.close();
				}*/
			}

		}
		coded.close();
	}
	plain.close();
	/*
	//encode the file (read char by char and shift chars)
	std::string test_string("(bunny");
	std::string buffer_string;
	std::string output_string;
	char buffer_char;
	int string_length = 0;
	string_length = test_string.length();
	buffer_string = test_string; //write input to buffer

	for (int i = 0; i < string_length; i++) //increment through string
	{
		buffer_char = buffer_string.at(0);					//copy first char into buffer
		output_string.push_back(buffer_char - 17);			//transform and write it to output
		buffer_string = buffer_string.substr(1);			//write rest of buffer into buffer

	}
	std::cout << "Message is: " << test_string << std::endl;
	std::cout << "Encoded message is: " << output_string << std::endl;
	*/


	
	//save the file as new file



	//close the files






	while (1);
	return 0;
}