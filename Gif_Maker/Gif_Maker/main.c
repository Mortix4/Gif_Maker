#define CV_IGNORE_DEBUG_BUILD_GUARD
#define _CRT_SECURE_NO_WARNINGS

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <stdio.h>
#include <stdbool.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>

#include "MainFunctions.h"
#include "view.h"
#include "LinkedList.h"

int main(int argc, char** argv)
{
	int choice = 0;
	bool running = true;

	while (running)
	{
		printMenu();
		choice = getOption(&choice);
		(choice == 0) ? running = false : handleOption(choice);
	}

	return 0;
}