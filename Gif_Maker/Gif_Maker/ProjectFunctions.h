#ifndef PROJECTFUNCTIONSH
#define PROJECTFUNCTIONSH
#include "stdio.h"
#include "stdlib.h"
#include "LinkedList.h"
#include "MainFunctions.h"

typedef struct FrameNode FrameNode;

void CreateProject(FrameNode** head);
void LoadProject(FrameNode** head);
void SaveProject(FrameNode* head);


#endif