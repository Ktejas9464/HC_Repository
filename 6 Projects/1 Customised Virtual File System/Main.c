/*
Customised Virtual File System application
*/

#include"Header.h"

int main()
{
	//variable declarations
	char str[80];
	char command[4][50];
	int count = 0;
	
	printf("Customised Virtual File System Application\n");
	//Call function to set environment
	SetEnvironment();
	
	while(1)
	{
		printf("VFS :>");
		fgets(str,80,stdin);
		fflush(stdin);
		
		count = sscanf(str,"%s%s%s%s",command[0],command[1],command[2],command[3]);
		if(count == 1)
		{
			if(strcmp(command[0],"help") == 0)
			{
				DisplayHelp();
			}
			else if(strcmp(command[0],"cls") == 0)
			{
				system("cls");
			}
			else if(strcmp(command[0],"exit") == 0)
			{
				printf("Thanks for using customised VFS!\n");
				break;
			}
			else
			{
				printf("Command not found\n");
			}
		}
		else if(count == 2)
		{
			
		}
		else if(count == 3)
		{
			
		}
		else if(count == 4)
		{
			
		}
		else
		{
			printf("Bad command\n");
		}
		
	}
	
	return 0;
}