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

// 6
void list_frames(FrameNode* head)
{
	printf("Name        Duration    Path\n");
	printf("----------------------------------------\n");

	if (head == NULL)
		return;

	FrameNode* tmp = head;

	while (tmp)
	{
		if (tmp->frame)
		{
			printf("%-12s %-10d ms %s\n", tmp->frame->name, tmp->frame->duration, tmp->frame->path);
		}
		else
		{
			printf("Invalid frame data.\n");
		}

		tmp = tmp->next;
	}
}

// 1
void add_new_frame(FrameNode** head)
{
	// Make The Frame
	char name[LEN] = { 0 };
	int duration = 1;

	printf("Enter Path: ");
	char* path = getPath();

	printf("Enter Frame Duration <Milliseconds>: ");
	duration = getOption();
	while (duration < 0)
	{
		printf("Invalid duration. Please enter a non-negative integer.\n");
		printf("Enter Frame Duration <Milliseconds>: ");
		duration = getOption();
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

FrameNode* findFrameNodeByName(FrameNode* head, char* name)
{
	if (head == NULL || name == NULL)
	{
		printf("The Head And The Name Shouldn't Be Empty!!\n");
		return NULL;
	}

	FrameNode* curr = head;
	while (curr)
	{
		if (curr->frame && strcmp(curr->frame->name, name) == 0)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

FrameNode* findFrameNodeByIndex(FrameNode* head, int index)
{
	if (head == NULL || index < 1)
	{
		printf("Head Is Empty Or Invalid Index!!\n");
		return NULL;
	}

	int currentIndex = 0;
	FrameNode* current = head;

	while (current != NULL)
	{
		if (currentIndex == index)
			return current;

		currentIndex++;
		current = current->next;
	}

	return NULL;
}

// 4 Main Function
void changeFrameDuration(FrameNode* curr, int duration)
{
	curr->frame->duration = duration;
}

// 4
void handleChangeFrameDuration(FrameNode* head)
{
	char name[LEN] = { 0 };
	int duration = 0;

	printf("Enter New Duration For The Frame: ");
	duration = getOption();

	printf("Enter Name Of The Frame: ");
	myFgets(name, LEN);

	FrameNode* curr = findFrameNodeByName(head, name);
	if (!curr)
	{
		printf("The Wanted Frame Wasn't Found!\n");
		return;
	}
	changeFrameDuration(curr, duration);
}

// 5
void handleChangeAllFramesDuration(FrameNode* head)
{
	printf("Enter Duration For All Frames: ");
	int duration = getOption();
	changeAllDuration(head, duration);
}

// 5 Main Function
void changeAllDuration(FrameNode* head, int duration)
{
	FrameNode* curr = head;
	while (curr)
	{
		changeFrameDuration(curr, duration);
		curr = curr->next;
	}
}

// 2
void handleRemoveFrame(FrameNode** head)
{
	char name[LEN] = { 0 };

	printf("Enter The Name Of The Frame: ");
	myFgets(name, LEN);

	FrameNode* curr = findFrameNodeByName(*head, name);
	if (!curr)
	{
		printf("The Wanted Frame Wasn't Found!\n");
		return;
	}
	removeFrame(head, name);
}

void removeFrame(FrameNode** head, char* name)
{
	FrameNode* p = *head;
	FrameNode* dNode = NULL;
	if (*head)
	{
		if (strcmp((*head)->frame->name, name) == 0)
		{
			*head = (*head)->next;
			free(p);
		}
		else
		{
			while (p->next && strcmp(p->next->frame->name, name))
				p = p->next;
			if (p->next)
			{
				dNode = p->next;
				p->next = dNode->next;
				free(dNode);
			}
		}
	}
}

//3
void handleChangeFrameIndex(FrameNode** head)
{
	char name[LEN] = { 0 };
	int index = 0;

	printf("Enter The Name Of The Frame: ");
	myFgets(name, LEN);
	FrameNode* src = findFrameNodeByName(*head, name);

	if (!src)
	{
		printf("Frame not found!\n");
		return;
	}

	printf("Enter The new index in the movie you wish to place the frame: ");
	while(index < 1)
		index = getOption();

	FrameNode* dest = findFrameNodeByIndex(*head, index);
	if (!dest)
	{
		printf("Invalid destination index!\n");
		return;
	}

	swapNodes(head, src, dest);
}

void swapNodes(FrameNode** head, FrameNode* node1, FrameNode* node2)
{
	// If either node is NULL or they are the same node
	if (*head == NULL || node1 == NULL || node2 == NULL || node1 == node2)
		return;

	// Find the previous of both nodes
	FrameNode* prev1 = NULL;
	FrameNode* prev2 = NULL;
	FrameNode* current = *head;

	while (current != NULL && (prev1 == NULL || prev2 == NULL))
	{
		if (current->next == node1)
		{
			prev1 = current;
		}

		if (current->next == node2)
		{
			prev2 = current;
		}

		current = current->next;
	}

	// If any of the nodes is not found in the list -> exit
	if (prev1 == NULL || prev2 == NULL)
		return;


	// Swap nodes
	if (prev1 != NULL)
		prev1->next = node2;

	else
		*head = node2;

	if (prev2 != NULL)
		prev2->next = node1;

	else
		*head = node1;

	FrameNode* temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
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


