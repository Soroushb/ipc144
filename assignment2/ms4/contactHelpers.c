//==============================================
// Name:           Soroush Bahrami
// Student Number: 152499182
// Email:          sbahrami7@myseneca.ca
// Section:        NHH
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard

void clearKeyboard(void)
{

	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:

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


// getIntInRange:

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


// yes:

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


// menu:

int menu(void)
{
	int option = 0;

	printf("Contact Management System\n-------------------------\n1. Display contacts\n2. Add a contact\n3. Update a contact\n4. Delete a contact\n5. Search contacts by cell phone number\n6. Sort contacts by cell phone number\n0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);

	return option;
}


// contactManagerSystem:

void contactManagerSystem(void) {
	int option;
	int done = 0;
	struct Contact contacts[MAXCONTACTS] = { { { "Rick",{"\0"}, "Grimes" },
											   { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
											   { "4161112222", "4162223333", "4163334444" } },
											 {
												 { "Maggie", "R.", "Greene" },
												 { 55, "Hightop House", 0, "A9A 3K3", "Bolton"},
												 { "9051112222", "9052223333", "9053334444" } },
											 {
												 { "Morgan", "A.", "Jones" },
												 { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
												 { "7051112222", "7052223333", "7053334444" } },
											 {
												 { "Sasha", {"\0"}, "Williams" },
												 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												 { "9052223333", "9052223333", "9054445555" } },
	};
	while (!done) {
		option = menu();
		printf("\n");
		switch (option) {
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		default:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1) {
				printf("\nContact Management System: terminated");
				done = 1;
			}
			printf("\n");
		}
	}
}




// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:

void getTenDigitPhone(char phoneNum[])
{
	int i = 0;
	int size = 10;
	int needInput = 1;
	do
	{

		scanf("%s", phoneNum);
		clearKeyboard();

		if (strlen(phoneNum) != size)
		{
			printf("Enter a 10-digit phone number: ");
		}
		else if (strlen(phoneNum) == size)
		{
			for (i = 0; i < size; i++)
			{

				if (isdigit(phoneNum[i]))
				{

					needInput = 0;

				}
				else {
					printf("Enter a 10-digit phone number: ");
					needInput = 1;
					i = size;
				}
			}
		}
	} while (needInput == 1);
}



// findContactIndex:

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;
	int find = -1;
	for (i = 0; i < size && find == -1; i++)
	{
		if (strcmp(contacts->numbers.cell, cellNum) == 0)
		{
			find = i;
		}
		else
		{
			contacts++;
		}
	}
	return find;
}


// displayContactHeader

void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter

void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", count);
	printf("\n");
}

// displayContact:

void displayContact(const struct Contact* contact)
{
	printf(" %s", contact->name.firstName);
	if (*contact->name.middleInitial == 0)
	{
		printf(" ");
	}
	else {
		printf(" %s ", contact->name.middleInitial);
	}

	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber != 0)
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}



// displayContacts:

void displayContacts(const struct Contact contacts[], int size)
{
	int i = 0;
	int count = 0;

	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].name.firstName) != 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);

}

// searchContacts:

void searchContacts(const struct Contact contacts[], int size)

{
	int position;
	char number[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	position = findContactIndex(contacts, size, number);
	if (position != -1)
	{
		printf("\n");
		displayContact(&contacts[position]);
		
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
		
	}
}


// addContact:

void addContact(struct Contact contacts[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].name.firstName) == 0) {
			getContact(&contacts[i]);
			printf("--- New contact added! ---\n");
			printf("\n");
			break;
		}
		else if (i == size - 1)
		{
			printf("*** ERROR: The contact list is full! ***\n");
			printf("\n");
			break;
		}
	}
}

// updateContact:

void updateContact(struct Contact contacts[], int size)
{
	int position;
	char number[11];
	char option;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	position = findContactIndex(contacts, size, number);
	if (position != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[position]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		option = yes();
		if (option == 1)
		{
			getName(&contacts[position].name);
		}
		printf("Do you want to update the address? (y or n): ");
		option = yes();
		if (option == 1)
		{
			getAddress(&contacts[position].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		option = yes();
		if (option == 1)
		{
			getNumbers(&contacts[position].numbers);
		}
		printf("--- Contact Updated! ---\n");
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
}


// deleteContact:

void deleteContact(struct Contact contacts[], int size)
{
	{
		struct Contact temp = { { "\0" } };
		int position;
		char number[11];
		char option;

		printf("Enter the cell number for the contact: ");
		getTenDigitPhone(number);
		position = findContactIndex(contacts, size, number);
		if (position != -1) {
			printf("\nContact found:\n");
			displayContact(&contacts[position]);
			printf("\n");
			printf("CONFIRM: Delete this contact? (y or n): ");
			option = yes();

			if (option == 1) {
				contacts[position] = temp;
				printf("--- Contact deleted! ---\n");
			}
		}
		else {
			printf("*** Contact NOT FOUND ***\n");
		}
	}
}

void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	struct Contact temp = { {{'\0'}} };

	for ( i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1
		].numbers.cell) > 0)
			{
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
	printf("\n");
}
