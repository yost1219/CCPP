/*
Author: Yost
Title: PL3A
Date: 10 August 2018
*/

/*

Inside of **person.h **design a class Person, that has private data members for first name, last name, age and gender.
Implement public functions to get and set the values of these private data members(example : std::string getFname(), void setName(std::string fName), as well as your constructor(s) and destructor.
	Inside of main.cpp, you will find the function, **generate_roster() **that you will need to write.This funciton will recieve user input to populate an array of Person objects, with each person being an individual in the class roster.Return the number of students recorded.
	You will also find a function called **log_roster(). **Write this function to print each user out to roster.txt.
	Compile person.h and roster.cpp into an executable to test your work.
	If you are lost, please reach out for help.
	
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "person.h"

using namespace std;

int log_roster(std::vector<Person>&, std::ofstream&);
int generate_roster(std::vector<Person>&);

int main()
{
	std::ofstream outfile("roster.txt"); //opens file
	std::vector<Person> roster; //sets up class

	int roster_size = generate_roster(roster);
	int logged_count = log_roster(roster, outfile);


	if (roster_size == logged_count) //makes sure log_roster and generate_roster are on the same page
	{
		std::cout << "Roster logged successfully";
	}

	else
	{
		std::cout << "Roster size and logged count mismatch. Error!" << std::endl;
	}
	roster.clear();

	while (1);
	return 0;

}

//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic

int log_roster(std::vector<Person>& roster, std::ofstream& outfile) //takes in Person info and writes it to the log "roster.txt"
{
	int log_count = 0;
	while (!roster.empty())
	{
		outfile << roster.back().fName() << "\t" << roster.back().lName() << "\t" << roster.back().a() << "\t" << roster.back().g() << std::endl;
		roster.pop_back(); //if you don't pop back then the loop will never close and it will just keep printing the line over and over
	}
	log_count++;
	return log_count;
}


//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 


int generate_roster(std::vector<Person>& roster)
{
	// declare variables
	std::string first_name, last_name;
	int age = 0;
	std::string gender;
	int roster_count = 0;
	int exit = 0;
	std::string input;

	Person person(first_name, last_name, age, gender); //put that data into the class

	while (exit == 0) //opens the loop to collect data
	{												   
		std::cout << "What is the member's first name?" << std::endl; //gets first name
		std::getline(std::cin, first_name); //just leaving this as std::cin >> first_name won't work as it will then skip the last name section
		person.get_fName(first_name);

		std::cout << "What is their last name?" << std::endl; //gets last name
		std::getline(std::cin, last_name);
		person.get_lName(last_name);

		while (true) //gets age
		{
			std::cout << "What is the member's age in years?" << std::endl;
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if (myStream >> age); //makes sure the input is a number and puts it in age
			{
				person.get_age(age);
				break; //break the loop
			}
			std::cout << "Please enter a valid age." << std::endl; //error message
		}

		std::cout << "What is their gender?" << std::endl; //gets gender
		std::getline(std::cin, gender);
		person.get_gender(gender);

		while (true) //checks to see if user wants to put in another person
		{
			std::cout << "Would you like to enter another person?  0 for yes.  1 for no." << std::endl;  //prompts user for input
			std::getline(std::cin, input);  //gets input from user
			std::stringstream myStream(input); 
			if (myStream >> exit) //makes sure the input is a number and puts it in exit
			{
				break;  //break the loop
			}
			std::cout << "Please enter a valid choice." << std::endl;

		}
		roster.push_back(person); //store the class data in the roster
	}						 
	roster_count++;
	return roster_count;
}
