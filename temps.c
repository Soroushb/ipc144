//==============================================
// Name:           Soroush Bahrami		
// Student Number: 152499182
// Email:          sbahrami7@myseneca.ca
// Section:        NHH
// Workshop:       3 (at_home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include<stdio.h>
#define NUMS 4
int main(void)
{

	int high, low, maxhigh = -40, minlow = 40, lowtotal = 0, hightotal = 0, i = 0, highestday = 0, lowestday = 0;    //declaring integers    
	float avelow = 0.00, avehigh = 0.00, avetotal = 0.00;    //declaring floats
	printf("---=== IPC Temperature Analyzer ===---");    //printing the output
	for (i = 1; i <= NUMS; ++i)     //using for loop for days
	{


		printf("\nEnter the high value for day %d: ", i);    //prompt user for the input
		scanf("%d", &high);    //accept the high input
		printf("\nEnter the low value for day %d: ", i);    //prompt user for the input
		scanf("%d", &low);    //accept the low input

		while (low < -40 || high > 40 || low > high)    //using the while loop for detecting incorrect values and repeating
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &low);

			
		}
		hightotal = (hightotal + high);    //calculating total high
		lowtotal = (lowtotal + low);    //calculating total low

		if (high > maxhigh)
		{
			maxhigh = high;
			highestday = i;

		}
		if (low < minlow)
		{
			minlow = low;
			lowestday = i;

		}
	}avelow = (float)lowtotal / NUMS;
	avehigh = (float)hightotal / NUMS;
	avetotal = (avelow + avehigh) / 2;
	printf("\nThe average (mean) LOW temperature was: %.2f\n", avelow);
	printf("The average (mean) HIGH temperature was: %.2f\n", avehigh);
	printf("The average (mean) temperature was: %.2f\n", avetotal);
	printf("The highest temperature was %d, on day %d\n", maxhigh, highestday);
	printf("The lowest temperature was %d, on day %d\n", minlow, lowestday);


	return 0;

}


