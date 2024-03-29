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
#include<string.h>
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
 {
	

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	


	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}
	else {
		name->middleInitial[0] = '\0';
	}

	printf("Please enter the contact's last name: ");
	scanf("%36[^\n]", name->lastName);
	clearKeyboard();

}


// getAddress:
void getAddress(struct Address* address)
{
	char option = 0;
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();

	while (address->streetNumber < 0)
	{
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		scanf("%d", &address->streetNumber);
		clearKeyboard();
	}


	printf("Please enter the contact's street name: ");
	scanf("%41[^\n]", address->street);
	clearKeyboard();


	printf("Do you want to enter an apartment number? (y or n): ");
	option = yes();

	if (option == 1)
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		while (address->apartmentNumber < 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			scanf("%d", &address->apartmentNumber);
			clearKeyboard();
		}
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	clearKeyboard();


	printf("Please enter the contact's city: ");
	scanf("%41[^\n]", address->city);
	clearKeyboard();

}
// getNumbers:
void getNumbers(struct Numbers* numbers)
{
	char option = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();
	if (option == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else {
		strcpy(numbers->home, "\0");
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();

	if (option == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
	{
		strcpy(numbers->business, "\0");
	}
}
// getContact:

void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}