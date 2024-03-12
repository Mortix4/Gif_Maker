/*********************************
* Class: MAGSHIMIM Final Project *
* Play function declaration       *
**********************************/

#ifndef VIEWH
#define VIEWH
#define CV_IGNORE_DEBUG_BUILD_GUARD

// Include necessary headers
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2\core\core_c.h>
#include <opencv2\highgui\highgui_c.h>

// Include LinkedList.h to make sure FrameNode is defined
#include "LinkedList.h"

#define GIF_REPEAT 5

void play(struct FrameNode* list);

#endif
