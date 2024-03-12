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

void handleSplashOption(int choice)
{
	switch (choice)
	{
		case 0:
			CreateProject();
			break;

		case 1:
			LoadProject();
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
        if (*head != NULL)
        {
            FrameNode* tmp = *head;
            printf("head Frame: %s - %s - %d\n", tmp->frame->name, tmp->frame->path, tmp->frame->duration);
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            printf("Added Frame: %s - %s - %d\n", tmp->frame->name, tmp->frame->path, tmp->frame->duration);
        }
        else
        {
            printf("Error: Frame not added successfully.\n");
        }
        break;

    case 2:
        // Add logic for option 2
        break;

    case 3:
        // Add logic for option 3
        break;

    case 4:
        // Add logic for option 4
        break;

    case 5:
        // Add logic for option 5
        break;

    case 6:
        list_frames(*head);
        break;

    case 7:
        // Add logic for option 7
        break;

    case 8:
        // Add logic for option 8
        break;

    default:
        printf("Invalid Choice, Try Again!\n");
        break;
    }
}

