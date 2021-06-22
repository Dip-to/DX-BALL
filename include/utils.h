#ifndef UTILS_H
#define UTILS_H

#include "header.h"


int INITIALIZE(); //utilities
void mainmenu_load(); //mainmenu
SDL_Texture *DISPLAYING_SCORE(char ch[],int a,int make_null); //mainmenu
int levelup_bricks_initialization(int level); //data load
int mainmenu_render(); //mainmenu
void name_write(); //utilities
void option_render(); //mainmenu
void mainmenu_level_renderer(); //utilities
void highscore_render(); //mainmenu
void pause_menu_renderer(); //mainmenu
void help_render(); //mainmenu
void ball_music_and_powerup_load(); //data load
void quit(); //mainmenu
void reset_game(int flag); //utilities
void lbutton(); //utilities
void font_closing(); //utilities
void font_load(); // utilities

#endif