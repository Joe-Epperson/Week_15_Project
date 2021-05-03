// Joe Epperson, IV
// jee4cf@umsystem.edu
// 05/03/2021
// Lab 15

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

// Declaring the functions at the top
void fillList(list<char>& listName, string usrInput);

void printList(list<char> listName, ofstream& outputFile);

void removeCharacter(list<char>& listName, char usrChar);

int main()
{
	list<string> listOfStrings;
	ifstream inputFile;
	ofstream outputFile;

	// Iterating through the input file until all strings are output into the list
	inputFile.open("input.txt");
	while (!inputFile.eof())
	{
		if (inputFile.good())
		{
			string tempString;
			getline(inputFile, tempString);

			if (tempString != "END")
			{
				listOfStrings.push_back(tempString);
			}
			else
			{
				break;
			}
		}
	}
	inputFile.close();

	outputFile.open("output.txt");
	
	// Iterating through the list of strings and performing the proper operations to uotput the correct values to the output.txt file
	list<string>::iterator listIterator;
	for (listIterator = listOfStrings.begin(); listIterator != listOfStrings.end(); ++listIterator)
	{
		list<char> tempList;

		fillList(tempList, *listIterator);
		removeCharacter(tempList, 'a');
		removeCharacter(tempList, 'e');
		removeCharacter(tempList, 'i');
		removeCharacter(tempList, 'o');
		removeCharacter(tempList, 'u');
		printList(tempList, outputFile);

	}
	outputFile.close();

	return 1;
}

void fillList(list<char>& listName, string usrInput)
{
	string::iterator stringIter;

	// Iterating through the string and putting each value into the list until the entire string has been searched
	for (stringIter = usrInput.begin(); stringIter != usrInput.end(); ++stringIter)
	{
		listName.push_back(*stringIter);
	}
}

void printList(list<char> listName, ofstream& outputFile)
{
	list<char>::iterator listIter;

	// Iterating through the list and outputting each value in order to the output.txt file derived from the OutputFile variable
	for (listIter = listName.begin(); listIter != listName.end(); ++listIter)
	{
		outputFile << "[" << (*listIter) << "] -> ";
	}
	outputFile << "0" << endl;
	outputFile << endl;
}

void removeCharacter(list<char>& listName, char usrChar)
{
	// Declaring new variables so that both the lowercase and uppercase are accounted for
	char upperChar = toupper(usrChar);
	char lowerChar = tolower(usrChar);

	// Removing both the upper case and lower case of the inputted character from the list
	listName.remove(lowerChar);
	listName.remove(upperChar);
}
