/*
Author: Yost
Title: PL2B Towers of Hanoi
Date: 9 August 2018
*/

/*

You are given a _struct disc, with an int variable. You are also given three stack<disc> towers, source, temp dest. _
Read in an int n from the user, and create n number of discs, with each one's int variable numbered [0 - n]. Load these in descending order to source.
Your goal is to move the discs from source to dest, noting that you cannot stack a larger number disc on top of a smaller number disc and you can only move the top disc of a tower.
I provided you the function Hanoi(). Try and think of an implementation of this function, and use the STL stack functions. When you are done, print the number of steps to solve to stdout.
Try your solution out with different values of n. Then try and determine the max number of discs.

*/


#include <iostream>
#include <stack>
#include <vector>
//#include <string>

int Setup(std::stack<int>& tower, int n);
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n);
void display(std::stack<int> tower);
static int numMoves = 0;

int main()
{
	std::stack<int> TowerA;
	std::stack<int> TowerB;
	std::stack<int> TowerC;

	int n = 0;      //Number of discs 


	std::cout << "How many discs do you want to start with?" << std::endl; //ask user
	std::cin >> n; //store user input for n discs
	
	n = Setup(TowerA, n); 
	Hanoi(TowerA, TowerC, TowerB, n); //source, destination, temp, number of discs
	std::cout << "Displaying contents of tower A: " << std::endl;
	display(TowerA);
	std::cout << "Displaying contents of tower B: " << std::endl;
	display(TowerB);
	std::cout << "Displaying contents of tower C: " << std::endl;
	display(TowerC);
	std::cout << "Number of steps to solve: " << numMoves << std::endl;

	while (1);
	return 0;

}

//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 
//           int n - a number that represents the number of discs to load on to the tower stack
//Return     the number of discs that were loaded on to the tower 
//Functionality: Load a number of discs in ascending order on to the stack 

//really, all this needs to do is take an input of how many rings you want (n) and stack them in descending order onto the tower

int Setup(std::stack<int>& tower, int n)
{
	for (int i = n; i > 0; i--) //count down so it places the largest discs at the bottom of the stack
	{
		tower.emplace(i); //puts down biggest disc first (value equal to n - i)
	}
	return n;
}

//Arguments: std::stack<int>& source - the tower that discs will be moved from
//           std::stack<int>& dest - the twoer that discs will be moved to 
//           std::stack<int>& temp - a tower that can hold discs 
//           int n - the number of discs on the source tower
//Return     none
//Functionality: Move a tower from source to another tower. 

//from source, to dest, via temp if needed; just trying to move from source to another tower
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n)
{
	if (n == 1) //if only one item is on the source then it can be moved directly to the dest
	{
		dest.emplace(source.top()); //copy the top item from source onto dest
		source.pop(); //remove the top item from source
		numMoves++;
		return;
	}
	else //otherwise, you have to move through an intermediary and recall the function to do this again
	{
		Hanoi(source, temp, dest, n - 1); //recall the original function if n > 1, reduce value of n by 1
		dest.emplace(source.top()); //copy from source to dest
		source.pop(); //remove from source
		numMoves++;
		Hanoi(temp, dest, source, n - 1); //recall again, args in diff order
	}
}

//Arguments: std::stack<int>& tower - a tower that has discs to dispay
//Return     none
//Functionality: Display the contents of a tower
void display(std::stack<int> tower)
{
	while (!tower.empty()) //while tower not empty
	{
		std::cout << tower.top() << " "; //print top value of tower
		tower.pop(); //remove top value of tower and repeat until done
	}
	std::cout << std::endl;
}