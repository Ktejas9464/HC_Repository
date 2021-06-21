/*
Problem Statement: Accept on number from user if number is less than 10 then print "Hello" otherwise print "Demo"
*/

//header file for input output
#include<stdio.h>

//function definition
void CheckNumber(int num)
{
	if(num<10)
	{
		printf("Hello\n");
	}
	else
	{
		printf("Demo\n");
	}
}

//entry point function
int main()
{
	int num = 0;
	
	printf("Enter number: \n");
	scanf("%d",&num);
	
	CheckNumber(num);
	
	//return from main
	return 0;
}