#define _CRT_SECURE_NO_WARNINGS
#include "ProjectFunctions.h"



void CreateProject(FrameNode** head)
{
	freeList(head);
	*head = NULL;
	printf("New project created!\n");
}

void LoadProject(FrameNode** head)
{
    char* path = getPath();

    // Open the file for reading
    FILE* file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open the file for reading.\n");
        return;
    }

    // Read data from the file and populate the linked list
    char name[LEN];
    int duration;
    char filePath[LEN];

    // Free the existing linked list if any
    freeList(head);

    while (fscanf(file, "%49[^,],%d,%49[^\n]%*c", name, &duration, filePath) == 3)
    {
        FrameNode* newNode = createFrameNode(name, duration, filePath);
        if (newNode == NULL)
        {
            printf("Error creating frame. Memory allocation failed.\n");
            break;
        }

        // Add the new frame to the linked list
        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            FrameNode* tmp = *head;
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    // Close the file
    fclose(file);

    printf("Project loaded successfully!\n");
}

void SaveProject(FrameNode* head)
{
    printf("Enter the path you wish to save the project in: ");
    char* path = getPath();

    // Open the file for writing
    FILE* file = fopen(path, "w");
    if (file == NULL)
    {
        printf("Error: Unable to open the file for writing.\n");
        return;
    }

    // Iterate through the linked list and write data to the file
    FrameNode* curr = head;
    while (curr != NULL)
    {
        fprintf(file, "%s,%d,%s\n", curr->frame->name, curr->frame->duration, curr->frame->path);
        curr = curr->next;
    }

    // Close the file
    fclose(file);

    printf("Project saved successfully!\n");
}