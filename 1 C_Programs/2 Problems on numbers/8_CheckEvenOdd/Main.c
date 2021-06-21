/*
Problem Statement: Accept number from user and check whether number is even or odd
*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

//function definition
BOOL CheckEven(int num)
{
	if(num%2 == 0)
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
	int num = 0;
	BOOL result = FALSE;
	
	//Accept user input
	printf("Enter number: \n");
	scanf("%d",&num);

	//Call function
	result = CheckEven(num);
	//print the result (return value of the function)
	if(result == TRUE)
	{
		printf("%d is even\n",num);
	}
	else
	{
		printf("%d is odd\n",num);
	}
	
	//return from main
	return 0;
}