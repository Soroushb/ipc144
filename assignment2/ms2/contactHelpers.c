//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: Empty function definition goes here:

int getInt(void)
{
	int integer;
	char newLine = 'x';
	while (newLine != '\n')
	{
		scanf("%d%c", &integer, &newLine);
		if (newLine != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return integer;
}

// getIntInRange: Empty function definition goes here:

int getIntInRange(int min, int max)
{
	int valueRange, checkRange = 0;
	while (checkRange == 0)
	{
		valueRange = getInt();

		if (valueRange > max || valueRange < min)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
			
		}
		else {
			checkRange = 1;
		}

		
	} return valueRange;
}

// yes: Empty function definition goes here:

int yes(void)
{
	char character = 'x';
	char newLine = 'x';
	int yes;

	while (newLine != '\n')
	{
		scanf("%c%c", &character, &newLine);
		if (newLine != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (character == 'y' || character == 'Y')
		{
			yes = 1;
		}
		else if (character == 'n' || character == 'N')
		{
			yes = 0;
		}
		else
		{
			newLine = 'x';
		}
	}
	return yes;
}

// menu: Empty function definition goes here:

int menu(void)
{
	int option = 0;

	printf("Contact Management System\n-------------------------\n1. Display contacts\n2. Add a contact\n3. Update a contact\n4. Delete a contact\n5. Search contacts by cell phone number\n6. Sort contacts by cell phone number\n0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	
	return option;
}

// contactManagerSystem: Empty function definition goes here:

void contactManagerSystem(void)
{
	int done = 0;
	int choice;

	while (done == 0)
	{
		choice = menu();

		switch (choice)
		{
		case 1: 
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			done = yes();
			break;
		default:
			break;
		}
		printf("\n");
	}
	printf("Contact Management System: terminated\n");

}
