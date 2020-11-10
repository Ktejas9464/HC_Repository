/*
Header file for customised virtual file system application
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//Macro definitions
#define MAXFILES 100
#define FILESIZE 1024
#define READ 4
#define WRITE 2
#define REGULAR 1
#define SPECIAL 2

//structure declaration for super block
struct SuperBlock
{
	int TotalInodes;
	int FreeInodes;
};

//structure declaration for Inode
struct Inode
{
	int InodeNumber;
	char FileName[50];
	int FileType;
	int FileSize;
	int ActualFileSize;
	int ReferenceCount;
	int LinkCount;
	char *Data;
	struct Inode *Next;
};

//structure declaration for File Table
struct FileTable
{
	int ReadOffset;
	int WriteOffset;
	int Mode;
	int Count;
	struct Inode *iptr;
};

//structure declaration for User File Descriptor Table
struct UFDT
{
	struct FileTable *ftptr[MAXFILES];
};

//Create Super Block function declaration
void CreateSuperBlock();

//Create Inodes function declaration
void CreateInodes();

//Create User File Descriptor Table function declaration
void CreateUFDT();

//Set Environment function declaration
void SetEnvironment();

//DisplayHelp function declaration
void DisplayHelp();

//ManPage function declaration
void ManPage(char *);