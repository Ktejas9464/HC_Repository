/*
Helper file for customised virtual file system application
*/

#include"Header.h"

//Global pointer of Inode
struct Inode *Head = NULL;

struct SuperBlock SB_Obj;
void CreateSuperBlock()
{
	SB_Obj.TotalInodes = MAXFILES;
	SB_Obj.FreeInodes = MAXFILES;
	printf("Super Block created successfully\n");
}

struct Inode Inode_Obj;
void CreateInodes()
{
	//loop counter
	int i = 1;
	//variable to hold address of new node
	struct Inode *newn = NULL;
	//variable to point to latest added node
	struct Inode *temp = NULL;
	
	for(i=1;i<=MAXFILES;i++)
	{
		//create new node
		newn = (struct Inode*) malloc(sizeof(struct Inode));
		//Initialise new node
		newn->InodeNumber = i;
		newn->FileType = 0;
		newn->FileSize = 0;
		newn->ActualFileSize = 0;
		newn->ReferenceCount = 0;
		newn->LinkCount = 0;
		newn->Data = NULL;
		newn->Next = NULL;
		
		//Create first node
		if(Head == NULL)
		{
			Head = newn;
			temp = newn;
		}
		//create second node onwards
		else
		{
			temp->Next = newn;
			temp = temp->Next;
		}
	}
	printf("DILB created successfilly\n");
}

struct UFDT UFDT_Obj;
void CreateUFDT()
{
	int i = 1;
	for(i=1;i<=MAXFILES;i++)
	{
		UFDT_Obj.ftptr[i] = NULL;
	}
	printf("UFDT initialised successfully\n");
}

void SetEnvironment()
{
	CreateSuperBlock();
	CreateInodes();
	CreateUFDT();
	printf("Environment set successfully\n");
}

//function to display help
void DisplayHelp()
{
	printf("-----------------------------------------------------------\n");
	printf("create: It is used to create new regular file\n");
	printf("open: It is used to open the existing file\n");
	printf("close: It is used to close the existing file\n");
	printf("read: It is used to read the contents of file\n");
	printf("write: It is used to write the data to file\n");
	printf("lseek: It is used to change the offset of file\n");
	printf("stat: It is used to display information of file\n");
	printf("fstat: It is used to display information of opened file\n");
	printf("ls: It is used to display names of all files\n");
	printf("rm: It is used to delete regular file\n");
	printf("-----------------------------------------------------------\n");
}

//function for man page
void ManPage(char *str)
{
	if(str == NULL)
	{
		return;
	}
	else if(strcmp(str,"create") == 0)
	{
		printf("Description: It is used to create a new file\n");
		printf("Usage: creat File_name Permission");
	}
	else if(strcmp(str,"read") == 0)
	{
		printf("Description: It is used to read data from an existing file\n");
		printf("Usage: read File_name\n");
	}
	else if(strcmp(str,"write") == 0)
	{
		printf("Description: It is used to write data to an existing file\n");
		printf("Usage: write File_Name data\n");
		printf("After command please enter the data\n");
	}
	else if(strcmp(str,"ls") == 0)
	{
		printf("Description: It is used to list names of all the file\n");
		printf("Usage: ls\n");
	}
	else if(strcmp(str,"stat") == 0)
	{
		printf("Description: It is used to display information of an existing file\n");
		printf("Usage: stat File_name\n");
	}
	else if(strcmp(str,"fstat") == 0)
	{
		printf("Description: It is used to display information of an existing file using its file descriptor\n");
		printf("Usage: fstat file_descriptor\n");
	}
	else if(strcmp(str,"truncate") == 0)
	{
		printf("Description: It is used to delete contents of existing file\n");
		printf("Usage: truncate File_name\n");
	}
	else if(strcmp(str,"open") == 0)
	{
		printf("Description: It is used to open an existing file\n");
		printf("Usage: open File_name Mode\n");
	}
	else if(strcmp(str,"close") == 0)
	{
		printf("Description: It is used to close an existing file\n");
		printf("Usage: close File_name\n");
	}
	else if(strcmp(str,"closeall") == 0)
	{
		printf("Description: It is used to close all existing files\n");
		printf("Usage: closeall\n");
	}
	else if(strcmp(str,"lseek") == 0)
	{
		printf("Description: It is used to change file offset\n");
		printf("Usage: lseek file_descriptor offset offset_position\n");
	}
	else if(strcmp(str,"rm") == 0)
	{
		printf("Description: It is used to delete an existing file\n");
		printf("Usage: rm File_name\n");
	}
	
	else
	{
		printf("Man page not found\n");
	}
}