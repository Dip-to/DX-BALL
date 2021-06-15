#include "header.h"

//
float x_vel = BALL_SPEED;
float y_vel = BALL_SPEED;
int ball_move = 0, bricks_showed = 126;
int fire_left=0;

int bar_anim = 0;
double dx = 0, dy = 0; //ball speed direction
float pspeed = 1.0;
int life = 3, level = 1, fspeed = 0, sspeed = 0, epaddle = 0, spaddle = 0;

int mbar = 1, gbar = 0, fbar = 0, mfbar = 0;
int gameover = 0, mainmenu = 1, first_move = 0, firehoise = 0, first_bounce = 0; //gameoverflag
float rect_x, pup_x, rect_y, pup_y, x_pos;
SDL_Rect background, level_background, ball, powerup_rec, bar;
SDL_Texture *liferend = NULL;
int close = 0, sound = 1, music_run = 1, gamesound = 1, score = 0, pause = 0;
double BALL_SPEED = 20, theta = 30;
int totalbricks = 126;
pwrupvar power_up;
firesrect fire_rectarray1[100], fire_rectarray2[100];
frontball front[2];
pwrupgplay power_up_map[9];
texarray gbartex[4], fbartex[4], mbartex[4], mfbartex[4], poweruptex[9], powerup_blurtex[9];
hscoresturct highscore_array[20];
bricksStruct bricks[150];
Uint32 render_flags;
SDL_Renderer *rend = NULL;
SDL_Window *win = NULL;
SDL_Surface *surface = NULL;
SDL_Texture *tex = NULL;
SDL_Texture *tex2 = NULL;
//kaj sesh

Mix_Music *main_menu_music = NULL; //music
Mix_Chunk *bar_paddle_collision = NULL;
Mix_Chunk *ball_bricks_collision = NULL;
Mix_Chunk *hardbricks = NULL;
Mix_Chunk *fire_init = NULL;
Mix_Chunk *game_over_music = NULL;
Mix_Chunk *powerup_init_music = NULL;
Mix_Chunk *expand_paddle_music = NULL;
Mix_Chunk *shrink_paddle_music = NULL;
Mix_Chunk *slow_ball_music = NULL;
Mix_Chunk *fast_ball_music = NULL;
Mix_Chunk *life_laser_grab_music = NULL;
Mix_Chunk *score_double = NULL;
Mix_Chunk *level_up = NULL;

int main(int agr, char *args[])
{
	if (INITIALIZE())
		printf("Initialization Complete.\n");
	else
	{
		printf("Initialize Error\n");
		quit();
		return 0;
	}
	mainmenu_load();
	ball_music_and_powerup_load();
	bricks_and_bar_load();
	music_load();
	SDL_FreeSurface(surface);
	int mousex = bar.x, mousey = bar.y, prevx = bar.x, prevy = bar.y;
	int tym = 0;
	score = 0;
	while (!close)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			int buttons = SDL_GetGlobalMouseState(&mousex, &mousey);
			if (prevx > mousex)
				x_pos = max(0, x_pos - (SCROLL_SPEED / 25));
			else if (prevx < mousex)
				x_pos = min(WINDOW_WIDTH - bar.w, x_pos + (SCROLL_SPEED / 25));
			prevx = mousex;
			prevy = mousey;
			switch (event.type)
			{
			case SDL_QUIT:
				close = 1;
				break;
			case SDL_MOUSEBUTTONDOWN:
				lbutton();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_LEFT:
					x_pos = max(0, x_pos - (SCROLL_SPEED) / 5);
					break;
				case SDL_SCANCODE_RIGHT:
					x_pos = min(WINDOW_WIDTH - bar.w, x_pos + (SCROLL_SPEED) / 5);
					break;
				case SDL_SCANCODE_0:
					gbar = 1;
					mfbar = fbar = mbar = 0;
					break;
				case SDL_SCANCODE_1:
					mfbar = 1;
					gbar = fbar = mbar = 0;
					break;
				case SDL_SCANCODE_2:
					fbar = 1;
					gbar = mbar = mfbar = 0;
					break;
				case SDL_SCANCODE_3:
					mbar = 1;
					mfbar = fbar = gbar = 0;
					break;
				case SDL_SCANCODE_6:
					mainmenu = 1 - mainmenu;
					break;
				case SDL_SCANCODE_ESCAPE:
					pause = 1 - pause;
					break;
				case SDL_SCANCODE_SPACE:
					lbutton();
					break;
				}
			}
		}
		mainmenu_level_renderer();
	}
	quit();
	return 0;
}
