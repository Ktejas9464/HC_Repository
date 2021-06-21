/*
Problem Statement: Accept two numbers from user and display first number on screen second number of times
*/

//header file for input output
#include<stdio.h>

//function definition
void DisplayNumber(int num1, int num2)
{
	//counter variable
	int i = 0;
	
	//validate the input
	if(num2<=0)
	{
		printf("Enter positive non zero value for second number\n");
		return;
	}
	
	for(i=0;i<num2;i++)
	{
		printf("%d ",num1);
	}
	printf("\n");
}

//entry point function
int main()
{
	int num1 = 0, num2 = 0;
	
	//Accept numbers from user
	printf("Enter first number: \n");
	scanf("%d",&num1);
	
	printf("Enter second number: \n");
	scanf("%d",&num2);
	
	DisplayNumber(num1,num2);
	
	//return from main
	return 0;
}