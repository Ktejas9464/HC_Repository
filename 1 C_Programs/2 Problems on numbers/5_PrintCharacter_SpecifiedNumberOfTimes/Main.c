/*
Problem Statement: Accept a number from user and print * on screen those many number of times
*/

//header file for input output
#include<stdio.h>

//function definition
void PrintCharacter(int num)
{
	//validate input
	if(num<=0)
	{
		printf("Enter non zero positive number\n");
		return;
	}
	
	int i = 0;
	for(i=0;i<num;i++)
	{
		printf("* ");
	}
	printf("\n");
}

//entry point function
int main()
{
	int num = 0;
	
	//Accept number from user
	printf("Enter number: \n");
	scanf("%d",&num);
	
	//call to function
	PrintCharacter(num);	
	
	//return from main
	return 0;
}