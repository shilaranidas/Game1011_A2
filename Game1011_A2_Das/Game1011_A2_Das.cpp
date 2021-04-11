// Game1011_A2_Das.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ReadAndPrint(const char* filename)
{
	ifstream myFileStream;
	myFileStream.open(filename);

	if (!myFileStream.is_open())
	{
		char errorMessage[256];
		strerror_s(errorMessage, errno);
		cerr << "Failed to open file: " << filename << ": " << errorMessage;
		return -1;
	}

	const int MAX_CHARS_PER_LINE = 256;
	while (!myFileStream.eof())
	{
		char lineContents[MAX_CHARS_PER_LINE];
		myFileStream.getline(lineContents, MAX_CHARS_PER_LINE);

		if (myFileStream.fail())
		{
			cerr << "Error: something went wrong reading line by line in file: " << filename;
			return -2;
		}

		cout << lineContents << endl;
	}

	return 0;
}
int main()
{
	ReadAndPrint("GameStory.txt");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
