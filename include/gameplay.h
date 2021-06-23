#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "header.h"


extern int level2, level1, level3, enter , uivar , pvar , ovar , hvar , povar , covar , ivar , nvar , evar ,scr_in;
extern int Hscore , Help , Instruction , Controls , Powerup_info , Instruction2 , option , game_sesh , next_button ;

//main menu

extern float pupx_vel ;
extern float pupy_vel ;
extern int var ;
extern int fire_left;

extern SDL_Rect powerup_gameplay_rect;
extern SDL_Texture *score_ttf_tex ;
extern SDL_Texture *firetex ;
extern SDL_Surface *bricks_surface ;


void score_and_life_print(int score,int life); //game_physics
void bricks_and_bar_load(); //game_physics
void firerender(int fbar); //game_physics
int bar_and_bricks_render(int cnt,int l); //game_physics
void powerup_achieve(); //game_physics
void powerup_renderer(int p, int type); //game_physics

void level_destroy(); //game_physics




#endif