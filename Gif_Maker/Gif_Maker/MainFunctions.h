#ifndef MAINFUNCTIONSH
#define MAINFUNCTIONSH

void printMenu();
int getOption(int* choice);
void handleOption(int choice);

void add_new_frame();
void remove_frame();
void change_frame_index();
void change_frame_duration();
void change_all_duration();
void list_frames();
void play_movie();
void save_project();


#endif