#ifndef LINKEDLISTH
#define LINKEDLISTH

#define LEN 50

#define FALSE 0
#define TRUE !FALSE

#include <stdio.h>
#include <string.h>
#include "MainFunctions.h"


// Frame struct
typedef struct Frame
{
	char name[LEN];
	unsigned int duration;
	char path[LEN];
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;


FrameNode* createFrameNode(char* name, unsigned int duration, char* path);
void add_new_frame(FrameNode** head);
void handleRemoveFrame(FrameNode** head);
void removeFrame(FrameNode** head, char* name);
void handleChangeFrameIndex(FrameNode** head);
void swapNodes(FrameNode** head, FrameNode* node1, FrameNode* node2);
FrameNode* findFrameNodeByIndex(FrameNode* head, int index);
FrameNode* findFrameNodeByName(FrameNode* head, char* name);
void handleChangeFrameDuration(FrameNode* head);
void changeFrameDuration(FrameNode* curr, int duration);
void handleChangeAllFramesDuration(FrameNode* head);
void changeAllDuration(FrameNode* head, int duration);
void list_frames(FrameNode* head);
void freeList(FrameNode** head);

#endif
