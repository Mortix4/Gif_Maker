#ifndef PROJECTFUNCTIONSH
#define PROJECTFUNCTIONSH
#include "stdio.h"
#include "stdlib.h"
#include "LinkedList.h"
#include "MainFunctions.h"
// Check OS
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

typedef struct FrameNode FrameNode;

void CreateProject(FrameNode** head);
void LoadProject(FrameNode** head);
void SaveProject(FrameNode* head);
int checkValidPaths(FrameNode* head);
int isValidPath(const char* path);

#endif