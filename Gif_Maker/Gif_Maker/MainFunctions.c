#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MainFunctions.h"

void myFgets(char* str, int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = '\0';
}

void printMenu()
{
	printf("\nWhat would you like to do?\n");
	printf("  [0] Exit\n  [1] Add New Frame\n  [2] Remove A Frame\n  [3] Change Frame Index\n  [4] Change Frame Duration\n  [5] Change Duration Of All Frames\n  [6] List Frames\n  [7] Play Movie!\n  [8] Save Project\n");
}

void printSplash()
{
	printf("Welcome to Magshimim Movie Maker! What would you like to do?\n");
	printf("  [0] Create A New Project\n  [1] Load Existing Project\n");
}

int getOption()
{
	int choice;
	scanf("%d", &choice);
	getchar();
	return choice;
}

void replaceForwardSlashes(char* str) 
{
    for (size_t i = 0; i < strlen(str); i++) 
    {
        if (str[i] == '/')
            str[i] = '\\';
    }
}

char* getPath()
{
    char path[LEN] = { 0 };
    myFgets(path, LEN);
    replaceForwardSlashes(path);

    // Dynamically allocate memory for the path
    char* dynamicPath = strdup(path);

    if (dynamicPath == NULL)
    {
        // Handle memory allocation failure if needed
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return dynamicPath;
}

void handleSplashOption(FrameNode** head, int choice)
{
	switch (choice)
	{
		case 0:
			CreateProject(head);
			break;

		case 1:
			LoadProject(head);
			break;

		default:
			printf("Invalid Choice, Try Again!\n");
			break;
	}
}

void handleOption(int choice, FrameNode** head)
{
    switch (choice)
    {
    case 1:
        add_new_frame(head);   
        break;

    case 2:
        handleRemoveFrame(head);
        break;

    case 3:
        handleChangeFrameIndex(head);
        break;

    case 4:
    {
        handleChangeFrameDuration(*head);
        break;
    }

    case 5:
    {
        handleChangeAllFramesDuration(*head);
        break;
    }    

    case 6:
        list_frames(*head);
        break;

    case 7:
        play(*head);
        break;

    case 8:
        SaveProject(*head);
        break;

    default:
        printf("Invalid Choice, Try Again!\n");
        break;
    }
}

