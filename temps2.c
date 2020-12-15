//==============================================
// Name:           Soroush Bahrami
// Student Number: 152499182
// Email:          sbahrami7@myseneca.ca
// Section:        NHH
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#define NUMS 10
#include<stdio.h>
int main(void)
{

	int n = 0, i = 0, high[NUMS], low[NUMS], highest = -0, lowest = 0, highday = 0, lowday = 0, days = 0, totalhigh = 0, totallow = 0, total = 0;
	;    //declaring. "n" is the number of days
	float average = 0;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");    //printing output

	printf("Please enter the number of days, between 3 and 10, inclusive: ");    //prompt user to enter the input
	scanf("%d", &n);    //accept the input for n(days)

	while (n < 3 || n > 10)    ////using the while loop for detecting incorrect values and repeating
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &n);
	}
	printf("\n");    //printing a new line
	for (i = 0; i < n; ++i)    //using for loop to accept input from the user 
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);    //accept and store the input in the array
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);    //accept and store the input in the array

		while (high[i] > highest)
		{
			highest = high[i];
			highday = i + 1;
		}
		while (low[i] < lowest)
		{
			lowest = low[i];
			lowday = i + 1;
		}
		
	}
	printf("\nDay  Hi  Low\n");
	for (i = 0; i < n; i++)     //use for loop for parallel arrays
	{

		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}

	printf("\nThe highest temperature was %d, on day %d", highest, highday);
	printf("\nThe lowest temperature was %d, on day %d\n", lowest, lowday);

	do
	{
		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &days);
		if (days >= 0)
		{
			while (days < 1 || days > 5)
			{
				printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
				scanf("%d", &days);

			}
			for (i = 0; i < days; i++)
			{
				totalhigh = totalhigh + high[i];
				totallow = totallow + low[i];
				total = totalhigh + totallow;

			}

			average = (float)total / (days * 2);
			printf("\nThe average temperature up to day %d is: %.2f\n", i, average);
			totalhigh = 0;
			totallow = 0;
			total = 0;
		}
		
	} while (days >= 1);
	
	printf("\nGoodbye!\n");
		
	





	return 0;

}