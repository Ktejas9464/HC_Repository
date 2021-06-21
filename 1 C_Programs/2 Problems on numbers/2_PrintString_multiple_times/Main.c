/*
Problem Statement: Accept a number from user and print "Hello World" that many times on screen
*/

//header file for input output
#include<stdio.h>

//definition of function for printing string
void PrintString(int num)
{
	//loop variable
	int i = 0;
	
	//validate input
	if(num<=0)
	{
		printf("Enter non zero positive number\n");
		return;
	}
	
	//for loop to print string
	for(i=0;i<num;i++)
	{
		printf("Hello World\n");
	}
}

int main()
{
	//variable to hold number entered by user
	int num = 0;
	
	//Accept number from user
	printf("Enter number: \n");
	scanf("%d",&num);

	//call to the function
	PrintString(num);
	
	//return from main
	return 0;
}