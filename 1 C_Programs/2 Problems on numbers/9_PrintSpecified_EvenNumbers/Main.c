/*
Problem Statement: Write a program which accept one number from user and print that number of even numbers on screen
Input : 7
Output: 2 4 6 8 10 12 14 
*/

//header file for input output
#include<stdio.h>

//Function definition
void PrintEven(int num)
{
	if(num<=0)
	{
		printf("Enter positive non zero number\n");
		return;
	}
	
	int i = 0;
	int j = 2;
	while(i<num)
	{
		printf("%d ",j);
		j = j+2;
		i++;
	}
	printf("\n");
}

//entry point function
int main()
{
	int num = 0;
	
	printf("Enter number: \n");
	scanf("%d",&num);
	
	PrintEven(num);
	
	//return from main
	return 0;
}