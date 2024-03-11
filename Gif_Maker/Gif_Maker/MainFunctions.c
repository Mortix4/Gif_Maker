#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "MainFunctions.h"
#include "view.h"

void printMenu()
{
	printf("What would you like to do?\n");
	printf("  [0] Exit\n  [1] Add New Frame\n  [2] Remove A Frame\n  [3] Change Frame Index\n  [4] Change Frame Duration\n  [5] Change Duration Of All Frames\n  [6] List Frames\n  [7] Play Movie!\n  [8] Save Project\n");
}

int getOption(int* choice)
{
	scanf("%d", &choice);
	getchar();
	return choice;
}

void handleOption(int choice)
{
	switch (choice)
	{
		case 1:
			add_new_frame();
			break;

		case 2:
			remove_frame();
			break;

		case 3:
			change_frame_index();
			break;

		case 4:
			change_frame_duration();
			break;

		case 5:
			change_all_duration();
			break;

		case 6:
			list_frames();
			break;

		case 7:
			play_movie();
			break;

		case 8:
			save_project();
			break;

		default:
			printf("Invalid Choice,Try Again!\n");
			break;
	}
}

// 1
void add_new_frame()
{

}

// 2
void remove_frame()
{

}

// 3
void change_frame_index()
{

}

// 4
void change_frame_duration()
{

}

// 5
void change_all_duration()
{

}

// 6
void list_frames()
{

}

// 7
void play_movie()
{

}

// 8
void save_project()
{

}