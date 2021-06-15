#ifndef UTILS_H
#define UTILS_H

#include "header.h"

#define WINDOW_WIDTH (1800)
#define WINDOW_HEIGHT (980)
#define SCROLL_SPEED (900)
#define POWERUP_SPEED (0)
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define abs(a) (a>=0)?a:-a
// float min(float x, float y);
// float max(float x, float y);



struct bricksStruct
{
	int x,y,dx=100,dy=35,power=0;
	bool powerup=false,show=false,r,g,b1=false,b2=false,b3=false,b4=false,b21=false,b25=false,b26=false,b27=false,b21_1,b31=false,b32=false,b33=false,b34=false,b35=false,b36=false;
};
struct texarray
{
	SDL_Texture* tex=NULL;
};
struct hscoresturct
{
	int score=0;
	char name[12]=" ";	
} ;
struct firesrect
{
	int show=0;
	SDL_Rect rec;
} ;

struct frontball
{
    int x;
    int y;
   
} ;
struct pwrupvar
{
	int hoise=0,type=0;

};
struct pwrupgplay
{
	bool type=0;
};  
extern pwrupvar power_up;
extern firesrect fire_rectarray1[100],fire_rectarray2[100];
extern frontball front[2];
extern pwrupgplay power_up_map[9];
extern texarray gbartex[4],fbartex[4],mbartex[4],mfbartex[4],poweruptex[9],powerup_blurtex[9];
extern hscoresturct highscore_array[20];
extern bricksStruct bricks[150];

extern Uint32 render_flags;
extern SDL_Renderer* rend;
extern SDL_Window* win;
extern SDL_Surface* surface;
extern SDL_Texture* gameover_tex;


extern SDL_Texture *tex,*tex2,*liferend;
extern SDL_Rect background,level_background,ball,powerup_rec,bar;

extern SDL_Texture* background1,*background2,*background3,*level1_back,*level2_back,*level3_back;




int INITIALIZE(); //utilities
void mainmenu_load(); //mainmenu
SDL_Texture *DISPLAYING_SCORE(char ch[],int a,int make_null); //mainmenu
int levelup_bricks_initialization(int level); //utilities
int mainmenu_render(); //mainmenu
void name_write(); //utilities
void option_render(); //mainmenu
void mainmenu_level_renderer(); //mainmenu
void highscore_render(); //mainmenu
void pause_menu_renderer(); //mainmenu
void help_render(); //mainmenu
void ball_music_and_powerup_load(); //utilities
void quit(); //mainmenu
void reset_game(int flag); //utilities
void lbutton(); //utilities
void font_closing(); //utilities


#endif