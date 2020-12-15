//==============================================
// Name:           Soroush Bahrami		
// Student Number: 152499182
// Email:         sbahrami7@myseneca.ca
// Section:        NHH
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>    //for printf, scanf

int main(void)    //program startup
{

	int loonies, quarters;    //declare loonies and quarters as integers
	double cost, balance_owing1, balance_owing2;    //declare cost, balance_owing1 and balance_owing2 as doubles

	printf("Please enter the amount to be paid: $");    //prompt the user for input   
	scanf("%lf", &cost);    //accept input for cost from the user

	loonies = (int)cost;    //expression and casting
	balance_owing1 = cost - loonies;    //Expression to calculate balance_owing_1
	
	quarters = balance_owing1 / 0.25;    //Expression to calculate the quarters
	balance_owing2 = balance_owing1 - (quarters * 0.25);    //Expression to calculate balance_owing_2
	
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance_owing1);    //copy loonies and balance_owing1 to standard output
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, balance_owing2);   //copy quarters and balance_owing2 to standard output


 


		

	
	








	return 0;
}
