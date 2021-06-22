#ifndef UTILS_H
#define UTILS_H

#include "header.h"

//bricks tex
extern SDL_Texture *bricks1 ;
extern SDL_Texture *bricks2 ;
extern SDL_Texture *bricks3 ;
extern SDL_Texture *bricks4 ;
extern SDL_Texture *bricks5 ;
extern SDL_Texture *bricks21 ;
extern SDL_Texture *bricks21_1 ;
extern SDL_Texture *bricks25 ;
extern SDL_Texture *bricks26 ;
extern SDL_Texture *bricks27 ;
extern SDL_Texture *bricks31 ;
extern SDL_Texture *bricks32 ;
extern SDL_Texture *bricks33 ;
extern SDL_Texture *bricks34 ;
extern SDL_Texture *bricks35 ;
extern SDL_Texture *bricks36 ;
extern SDL_Texture* bricks37;
extern SDL_Texture* bricks37_1;

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