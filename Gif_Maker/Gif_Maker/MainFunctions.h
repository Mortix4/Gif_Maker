#ifndef MAINFUNCTIONSH
#define MAINFUNCTIONSH
#include "view.h"
#include "LinkedList.h"
#include "ProjectFunctions.h"

typedef struct FrameNode FrameNode;

void myFgets(char* str, int n);
void printMenu();
void printSplash();
int getOption();
void replaceForwardSlashes(char* str);
char* getPath();
void handleSplashOption(FrameNode** head, int choice);
void handleOption(int choice, FrameNode** head);

#endif