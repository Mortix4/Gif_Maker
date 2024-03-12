#define CV_IGNORE_DEBUG_BUILD_GUARD
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>

#include "MainFunctions.h"
#include "view.h"
#include "LinkedList.h"

int main()
{
	int choice = 0;
	bool running = true;
	FrameNode* head = NULL;

	while (true)
	{
		printSplash();
		choice = getOption();
		if (choice == 0 || choice == 1)
		{
			handleSplashOption(choice);
			break;
		}
	}

	while (running)
	{
		printMenu();
		choice = getOption();
		(choice == 0) ? running = false : handleOption(choice, &head);
	}
	freeList(&head);
	return 0;
}