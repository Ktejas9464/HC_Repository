/*
Problem Statement: Write a program to divide two numbers
*/

//header file for input output functions
#include<stdio.h>
//macro definitions
#define TRUE 1
#define FALSE 0
//creating a typedef
typedef int BOOL;

//Function definition for dividing two numbers
BOOL DivideNumbers(int num1, int num2, float *answer)
{
	if (num2 == 0)
	{
		printf("Divide by zero error\n");
		return FALSE;
	}
	*answer = (float)num1/(float)num2;
	return TRUE;
}

//main function definition
int main()
{
	//variables to hold two input numbers
	int no1 = 0, no2 = 0;
	//variable to hold result of division
	float ans = 0;
	//boolean variable to handle division by zero situation
	BOOL result = FALSE;
	
	//Accept first number from user
	printf("Enter first number: \n");
	scanf("%d",&no1);
	
	//Accept second number from user
	printf("Enter second number: \n");
	scanf("%d",&no2);
	
	//call to function
	result = DivideNumbers(no1, no2, &ans);
	//print the result upto 2 decimal places
	if(result == TRUE)
	{
		printf("Result of division: %0.2f\n",ans);
	}
	
	//return from main
	return 0;
}