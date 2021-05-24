#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "header.h"


//game var
extern int close,score,pause,gameover ,mainmenu,first_move,firehoise,first_bounce, bar_anim; //gameoverflag;
extern int mbar,gbar,fbar,mfbar; //bar anim
extern float rect_x,pup_x, rect_y,pup_y, x_pos;
//gameplay
extern double dx,dy,BALL_SPEED,theta; //ball speed direction
extern float pspeed,x_vel, y_vel;
extern int life,level,fspeed,sspeed,epaddle,spaddle,totalbricks,ball_move,bricks_showed;
//gameplay


void score_and_life_print(int score,int life); //game_physics
void bricks_and_bar_load(); //game_physics
void firerender(int fbar); //game_physics
int bar_and_bricks_render(int cnt,int l); //game_physics
void powerup_achieve(); //game_physics
void powerup_renderer(int p, int type); //game_physics
void game_physics(); //game_physics
void level_destroy(); //game_physics

#endif