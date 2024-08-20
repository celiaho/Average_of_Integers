// Description: This lab takes the average of all numbers in a file chosen by the user. Learning 
// outcomes include:
//		establishing a connection to an input file,
//		reading data from that file,
//		calculating the mathematically correct average of the first two integers ONLY (regardless of
//		how many numbers are in the file--if there are more numbers in the file, you do NOT have to
//		do anything with them),
// 
//		asking the user to enter the file name,
//		validating that the user entered the correct file name, and
// 
//		reading ALL the integers from the file and showing the mathematically correct average.
// Title: Average of Integers
// Programmer: C. Ho
// Last Modified: Wednesday, Nov. 1, 2023 @ 4:30 PM

// PREPROCESSOR DIRECTIVE SECTION
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// FUNCTION DECLARATION SECTION - N/A IN THIS LAB

// MAIN SECTION
int main()
{
	// SET UP SECTION
	// System call to edit title of cmp window
	system("title .     Average of Integers     by C. Ho");

	// System function call to customize colors of cmp window
	system("color E1");

	// WYSIWYG banner
	cout << "\n"
		<< "\t\t\t Average of Integers \n"
		<< "\t\t\t       Lab #5        \n"
		<< "\t\t\t      By C. Ho       \n\n";

	// VARIABLE DECLARATION SECTION
	string userInputFile;
	ifstream inputFileStream;	// Declare input file stream.
	int 
		number,					// To store integers read from the file
		sum = 0,				// To hold the sum of the numbers
		numberOfNumbers = 0;	// counter to track the number of numbers	

	// INPUT SECTION
	// Prompt the user for the file name.
	cout << "What is the name of the file that contains the integers to average? ";
	// Get the file name from the user and store it.
	getline(cin, userInputFile);

	// Open the file.
	inputFileStream.open(userInputFile);

	// Validate that the file opened correctly.
	// If the file failed to open, show error message and re-prompt user input...
	while (inputFileStream.fail())
	{
		cout << '\a'
			<< "\n   Failed to open \"" << userInputFile << "\".\n"
			<< "   Please check the file name (including path and extension) and try again: ";
		getline(cin, userInputFile);

		// Open the newly-entered file.
		inputFileStream.open(userInputFile);
	}
	// ...if the file successfully opened, show success message and process it.
	cout << "\n   Reading data from the file.\n   ";

	// PROCESSING SECTION
	while (inputFileStream >> number)
	{
		// inputFileStream >> number;	// Read number from the file.
		cout << number << " ";		// Display number.

		sum += number;				// Add the number to the sum.
		numberOfNumbers++;			// Accumulator to count the number of numbers
	}

	// Close the file.
	inputFileStream.close();

	// OUTPUT SECTION
	// Display the average of the numbers.
	cout << "\n   The average of these numbers is: " << sum / static_cast<float>(numberOfNumbers) << ".\n\n";

	// CLEAN UP SECTION
	system("pause");			// Hold screen so user sees final message.
	return 0;					// End program.
	// Main ends
}