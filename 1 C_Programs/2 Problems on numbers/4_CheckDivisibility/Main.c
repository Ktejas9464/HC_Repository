/*
Problem Statement: Accept a number from user. Accept another number from user and display whether first number is divisible by second number
*/

//header file for input output
#include<stdio.h>
//macro definitions
#define TRUE 1
#define FALSE 0
//creation of typedef
typedef int BOOL;

//function definition to check divisibility
BOOL CheckDivisibility(int num1, int num2)
{
	//validate the inputs
	if((num1 == 0) || (num2 == 0))
	{
		printf("Enter non zero numbers\n");
		return -1;
	}
	if(num1%num2 == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//entry point function
int main()
{
	int num1 = 0, num2 = 0;
	BOOL ans = FALSE;
	
	//Accept two numbers from user
	printf("Enter first number: \n");
	scanf("%d",&num1);
	
	printf("Enter second number: \n");
	scanf("%d",&num2);
	
	//function call
	ans = CheckDivisibility(num1,num2);
	if(ans == TRUE)
	{
		printf("%d is divisible by %d\n",num1,num2);
	}
	else if(ans == FALSE)
	{
		printf("%d is not divisible by %d\n",num1,num2);
	}
	
	//return from main
	return 0;
}