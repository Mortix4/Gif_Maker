#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"
#include "MainFunctions.h"
#include <string.h>


FrameNode* createFrameNode(char* name, unsigned int duration, char* path)
{
    FrameNode* fn = (FrameNode*)malloc(sizeof(FrameNode));

    if (fn == NULL) 
        return NULL;

    fn->frame = (Frame*)malloc(sizeof(Frame));

    if (fn->frame == NULL) 
    {
        free(fn);
        return NULL;
    }

    strncpy(fn->frame->name, name, LEN - 1);
    fn->frame->name[LEN - 1] = '\0';
	//puts(fn->frame->name);

    strncpy(fn->frame->path, path, LEN - 1);
    fn->frame->path[LEN - 1] = '\0';
	//puts(fn->frame->path);

    fn->frame->duration = duration;
	//printf("%d", fn->frame->duration);

    fn->next = NULL;
	//printf("\nFrame Was Added Successfully!\n");
    return fn;
}

void list_frames(FrameNode* head)
{
	printf("Name        Duration    Path\n");
	printf("----------------------------------------\n");

	FrameNode* tmp = head;

	while (tmp)
	{
		if (tmp->frame)
		{
			printf("%-12s %-10d %s\n", tmp->frame->name, tmp->frame->duration, tmp->frame->path);
		}
		else
		{
			printf("Invalid frame data.\n");
		}

		tmp = tmp->next;
	}
}

void add_new_frame(FrameNode** head)
{
	// Make The Frame
	char path[LEN] = { 0 };
	char name[LEN] = { 0 };
	int duration = 1;

	printf("Enter Frame Path: ");
	myFgets(path, LEN);

	printf("Enter Frame Duration <Milliseconds>: ");
	duration = getOption();
	while (duration < 0)
	{
		printf("Invalid duration. Please enter a non-negative integer.\n");
		printf("Enter Frame Duration <Milliseconds>: ");
	}

	printf("Enter Frame Name: ");
	myFgets(name, LEN);

	FrameNode* curr = createFrameNode(name, duration, path);
	//printf("%s - %s - %d", curr->frame->name, curr->frame->path, curr->frame->duration);

	// Add it to the tail of LinkedList
	if (*head == NULL)
	{
		*head = curr;
	}
	else
	{
		FrameNode* tmp = *head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}

		// Check if tmp or tmp->next is null before accessing
		if (tmp == NULL)
		{
			printf("Error: Invalid pointer detected.\n");
			return;
		}

		tmp->next = curr;
	}

	if (curr == NULL)
	{
		printf("Error creating frame. Memory allocation failed.\n");
	}
}


void freeList(FrameNode** head)
{
	FrameNode* curr = *head;
	FrameNode* temp = NULL;

	while (curr)
	{
		temp = curr->next;

		// Free for Frame
		if (curr->frame)
		{
			free(curr->frame);
		}

		// Free for FrameNode
		free(curr);

		curr = temp;
	}

	*head = NULL;
}
