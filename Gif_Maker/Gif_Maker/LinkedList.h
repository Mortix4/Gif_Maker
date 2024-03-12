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
void freeList(FrameNode** head);

#endif
