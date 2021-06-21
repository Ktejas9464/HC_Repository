/*
Problem Statement: Accept a positive number from user and print numbers starting from that number till 1
*/

//header file for input output
#include<stdio.h>

//function definition
void PrintNumbersInReverseOrder(int num)
{
	//loop variable
	int i = 0;
	
	//validate input
	if(num<=0)
	{
		printf("Enter non zero positive number\n");
		return;
	}
	
	for(i=num;i>=1;i--)
	{
		printf("%d ",i);
	}
	printf("\n");
}

//entry point function
int main()
{
	//variable to hold a number
	int num = 0;
	
	//Accept the number from user
	printf("Enter a number:\n");
	scanf("%d",&num);
	
	//call to function
	PrintNumbersInReverseOrder(num);
	
	//return from main
	return 0;
}