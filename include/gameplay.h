#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "header.h"

//gameplay
extern double dx,dy,BALL_SPEED,theta; //ball speed direction
extern float pspeed,x_vel, y_vel;
extern int life,level,fspeed,sspeed,epaddle,spaddle,totalbricks,ball_move,bricks_showed;
extern int scr_in;
//gameplay
extern int level2, level1, level3, enter , uivar , pvar , ovar , hvar , povar , covar , ivar , nvar , evar ,scr_in;
extern int Hscore , Help , Instruction , Controls , Powerup_info , Instruction2 , option , game_sesh , next_button ;
//main menu


void score_and_life_print(int score,int life); //game_physics
void bricks_and_bar_load(); //game_physics
void firerender(int fbar); //game_physics
int bar_and_bricks_render(int cnt,int l); //game_physics
void powerup_achieve(); //game_physics
void powerup_renderer(int p, int type); //game_physics
void game_physics(); //game_physics
void level_destroy(); //game_physics
void collision(); //game_physics
void ball_fall_paddle_collision(); //game_physics


#endif