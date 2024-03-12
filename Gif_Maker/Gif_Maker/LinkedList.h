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
void list_frames(FrameNode* head);
void add_new_frame(FrameNode** head);
FrameNode* findFrameNodeByName(FrameNode* head, char* name);
FrameNode* findFrameNodeByIndex(FrameNode* head, int index);
void changeFrameDuration(FrameNode* curr, int duration);
void handleChangeFrameDuration(FrameNode* head);
void handleChangeAllFramesDuration(FrameNode* head);
void handleChangeFrameIndex(FrameNode** head);
void handleRemoveFrame(FrameNode** head);
void changeAllDuration(FrameNode* head, int duration);
void removeFrame(FrameNode** head, char* name);
void swapNodes(FrameNode** head, FrameNode* node1, FrameNode* node2);
void freeList(FrameNode** head);

#endif
