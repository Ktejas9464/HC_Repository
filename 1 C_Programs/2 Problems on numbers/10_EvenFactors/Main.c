/*
Problem Statement: Write a program which accept number from user and print even factors of that number
Input : 24
Output: 2 4 6 8 12
*/

#include<stdio.h>

//function definition
void PrintEvenFactors(int num)
{
	int i = 0;
	if(num<0)
	{
		num = -num;
	}
	for(i=2;i<=num/2;i++)
	{
		if(i%2==0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}

//entry point function
int main()
{
	int num = 0;
	
	printf("Enter number: \n");
	scanf("%d",&num);
	
	PrintEvenFactors(num);
	
	return 0;
}