//==============================================
// Name:           Soroush Bahrami		
// Student Number: 152499182
// Email:         sbahrami7@myseneca.ca
// Section:        NHH
// Workshop:       2 (at_home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>    //for printf, scanf

int main(void)    //program startup
{

	int loonies, quarters, loonies2, quarters2, dimes, nickles, pennies;    //declare loonies and quarters as integers
	double cost, balance_owing1, GST, total;    //declare cost, balance_owing1 and balance_owing2 as doubles
	printf("Please enter the amount to be paid: $");    //prompt the user for input   
	scanf("%lf", &cost);    //accept input for cost from the user
	
	loonies = (int)cost;    //expression and casting
	balance_owing1 = cost - loonies;    //Expression to calculate balance_owing_1
	
	quarters = balance_owing1 / 0.25;    //Expression to calculate the quarters
	balance_owing1 = balance_owing1 - (quarters * 0.25);    //Expression to calculate balance_owing_2
	
	GST = (cost * 0.13) + 0.005;    //Calculate GST
	printf("GST: %.2lf\n", GST);    //copy GST to standard output
	total = cost + GST;    //Calculate Balance Owing
	printf("Balance owing: $%.2lf\n", total);    //copy total to standard output
	loonies2 = (int)total;    //Calculate loonies, casting
	balance_owing1 = total - loonies2;    //Calculate balance owing for loonies 
	balance_owing1 = (balance_owing1 * 100);    //Multiplying 
	printf("Loonies required: %d, balance owing $%1.2f\n", loonies2, (float)balance_owing1 / 100);    //copy to standard output
	quarters2 = (balance_owing1 / 25);    //Calculate quarters
    balance_owing1 = ((int)balance_owing1 % 25);    //Calculate balance owing for quarters
	printf("Quarters required: %d, balance owing $%1.2lf\n", quarters2, (float)balance_owing1 / 100);   //copy to standard output
	dimes = (int)balance_owing1 / 10;    //Calculate dimes, casting
    balance_owing1 = ((int)balance_owing1 % 10);    //Calculate balance owing for dimes 
	printf("Dimes required: %d, balance owing $%1.2lf\n", dimes, (float)balance_owing1 / 100);    //copy to standard output
	nickles = (int)balance_owing1 / 5;    //Calculate nickles
	balance_owing1 = ((int)balance_owing1 % 5);    //Calculate balance owing for nickles
	printf("Nickels required: %d, balance owing $%1.2lf\n", nickles, (float)balance_owing1 / 100);    //copy to standard output
	pennies = (int)balance_owing1 / 1;    //Calculate pennies
	balance_owing1 = ((int)balance_owing1 % 1);    //Calculate balance owing for pennies
	printf("Pennies required: %d, balance owing $%1.2lf\n", pennies, (float)balance_owing1 / 100);    //copy to standard output
	
	













	return 0;
}
