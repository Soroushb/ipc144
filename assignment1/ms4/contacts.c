//==============================================
// Name:           Soroush Bahrami
// Student Number: 152499182
// Email:          sbahrami@myseneca.ca
// Section:        NHH
// Date:           
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void clear()
{
	while (getchar() != '\n');
		
}
void getName(struct Name* name)
{
	char option = 0;

	printf("Please enter the contact's first name: ");
	scanf("%36[^\n]", name->firstName);
	clear();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%c", &option);
	clear();

	if (option == 'y' || option == 'Y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%7[^\n]", name->middleInitial);
		clear();
	}

	printf("Please enter the contact's last name: ");
	scanf("%36[^\n]", name->lastName);
	clear();
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

void getAddress(struct Address* address)
{
	char option = 0;
	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);
	clear();
	while (address->streetNumber < 1)
	{
		printf("Invalid value. Please enter the contact's street number: ");
		scanf("%d", &address->streetNumber);
		clear();
	}

	printf("Please enter the contact's street name: ");
	scanf("%41[^\n]", address->street);
	clear();

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c", &option);
	clear();
	if (option == 'y' || option == 'Y')
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
		clear();
	}

	printf("Please enter the contact's postal code: ");
	scanf("%8[^\n]", address->postalCode);
	clear();

	printf("Please enter the contact's city: ");
	scanf("%41[^\n]", address->city);
	clear();
}


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

void getNumbers(struct Numbers* numbers)
{
	char option = 0;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%c", &option);
	clear();
	if (option == 'y' || option == 'Y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%11[^\n]", numbers->cell);
		clear();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%c", &option);
	clear();

	if (option == 'y' || option == 'Y');
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%11[^\n]", numbers->home);
		clear();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%c", &option);
	clear();

	if (option == 'y' || option == 'Y');
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%11[^\n]", numbers->business);
		clear();
	}
}