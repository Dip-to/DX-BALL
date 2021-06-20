#include "header.h"


void music_load()
{
	main_menu_music = Mix_LoadMUS("res/Music/Ethno_Papa.mp3");
    if(main_menu_music == NULL)
    {
        printf("CANNOT LOAD Mainmenu MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	bar_paddle_collision= Mix_LoadWAV("res/Music/ball_bar_collison.wav");
	if(bar_paddle_collision == NULL)
    {
        printf("CANNOT LOAD bar_paddle_collision MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	ball_bricks_collision=Mix_LoadWAV("res/Music/ball_bricks_collision.wav");
	if(ball_bricks_collision == NULL)
    {
        printf("CANNOT LOAD ball_bricks_collision MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	hardbricks=Mix_LoadWAV("res/Music/hardbricks.wav");
	if(hardbricks == NULL)
    {
        printf("CANNOT LOAD hardbricks MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }

	fire_init=Mix_LoadWAV("res/Music/fire.wav");
	if(fire_init == NULL)
    {
        printf("CANNOT LOAD Fire MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	powerup_init_music=Mix_LoadWAV("res/Music/powerup_music/powerup_starting.wav");
	if(powerup_init_music == NULL)
    {
        printf("CANNOT LOAD powerup init MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	game_over_music=Mix_LoadWAV("res/Music/powerup_music/kill_paddle.wav");
	if(game_over_music == NULL)
    {
        printf("CANNOT LOAD game_over_music MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	expand_paddle_music=Mix_LoadWAV("res/Music/powerup_music/expand_paddle.wav");
	if(expand_paddle_music == NULL)
    {
        printf("CANNOT LOAD expand_paddle_music MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	shrink_paddle_music=Mix_LoadWAV("res/Music/powerup_music/shrink_paddle.wav");
	if(shrink_paddle_music == NULL)
    {
        printf("CANNOT LOAD shrink_paddle_music MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	fast_ball_music=Mix_LoadWAV("res/Music/powerup_music/fast_ball.wav");
	if(fast_ball_music == NULL)
    {
        printf("CANNOT LOAD fast_ball_music MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	slow_ball_music=Mix_LoadWAV("res/Music/powerup_music/slow_ball.wav");
	if(slow_ball_music == NULL)
    {
        printf("CANNOT LOAD slow_ball_music MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	life_laser_grab_music=Mix_LoadWAV("res/Music/powerup_music/extra_life.wav");
	if(life_laser_grab_music == NULL)
    {
        printf("CANNOT LOAD life_laser_grab_music MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	score_double=Mix_LoadWAV("res/Music/powerup_music/score_double.wav");
	if(score_double == NULL)
    {
        printf("CANNOT LOAD score_double MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }

	level_up=Mix_LoadWAV("res/Music/level_up.wav");
	if(level_up == NULL)
    {
        printf("CANNOT LOAD level_up MUSIC %s\n",Mix_GetError());
		quit();
        return ;
    }
	
}

void ball_music_and_powerup_load()
{
	//load background
	surface = IMG_Load("res/Background/background1.jpg");
 	if (!surface)
	{
 		printf("Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    background1 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
 	if(!background1)
	 {
 		printf("background1 Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
	surface = IMG_Load("res/Background/background2.jpg");
 	if (!surface)
	{
 		printf("Background2 Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    background2 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;

	surface = IMG_Load("res/Background/level2.jpg");
 	if (!surface)
	{
 		printf("Background2 Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    level2_back = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	 
 	if(!level2_back)
	 {
 		printf("level2 background Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
	surface = IMG_Load("res/Background/background3.jpg");
 	if (!surface)
	{
 		printf("Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    background3 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	
 	if(!background3)
	 {
 		printf("background1 Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}

	 surface = IMG_Load("res/Background/level3.jpg");
 	if (!surface)
	{
 		printf("level3 Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    level3_back = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	
 	if(!level3_back)
	 {
 		printf("level3 background Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}

	 surface = IMG_Load("res/Background/level1.jpg");
 	if (!surface)
	{
 		printf("level1 Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    level1_back = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	
 	if(!level3_back)
	 {
 		printf("level3 background Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
	background.h=WINDOW_HEIGHT-35,background.w=WINDOW_WIDTH;
	background.x=background.y=0;

	level_background.h=WINDOW_HEIGHT,level_background.w=WINDOW_WIDTH;
	level_background.x=level_background.y=0;
    //load bar  
    surface = IMG_Load("res/gnrl_bar/gbar1.jpg");
 	if (!surface)
	{
 		printf("Gamebar Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    tex = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
 	if(!tex)
	 {
 		printf("Gamebar Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
 	SDL_QueryTexture(tex, NULL, NULL, &bar.w, &bar.h);
 	bar.w = 200;
 	bar.h = 30;
 	bar.x = (int) (WINDOW_WIDTH-bar.w)/2;
 	bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
    //bar

 	//load ball
 	surface = IMG_Load("res/Ball_n.jpg");
 	if (!surface)
    {
 		printf("Ball Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
 	tex2 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
 	if(!tex2)
    {
 		printf("Ball Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
 	ball.w=16;
 	ball.h =16;
    //bar.x = (int) (WINDOW_WIDTH-bar.w)/2;
 	//bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
 	ball.x = (int) bar.x+50;
 	ball.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
    // rect_x = ball.x;
    rect_y = ball.y;
    x_pos = bar.x;	
	//score digit load
	
	SDL_Surface* surf2=NULL;
	surf2=IMG_Load("res/life.jpg");
	if (!surf2)
	{
		printf("life Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	liferend=SDL_CreateTextureFromSurface(rend,surf2);
	SDL_FreeSurface(surf2);
	surf2=NULL;
	
	char pwrup[10][100]={"res/Power_up/Laser_paddle.jpg","res/Power_up/grab_paddle.jpg","res/Power_up/double_points.jpg","res/Power_up/shrink _paddle.jpg",
			"res/Power_up/expand_paddle.jpg","res/Power_up/kill_paddle.jpg","res/Power_up/extra_life.jpg","res/Power_up/fast_ball.jpg","res/Power_up/slow_ball.jpg"};
    powerup_rec.h=65,powerup_rec.w=80;
	for(int i=0; i<9; i++)
	{
		surf2=IMG_Load(pwrup[i]);
		if(!surf2)
		{
			printf("power_up %d Surface Error: %s\n",i,IMG_GetError());
			quit();
			return ;
		}
		poweruptex[i].tex=SDL_CreateTextureFromSurface(rend,surf2);
		SDL_FreeSurface(surf2);
		surf2=NULL;
	}
	char blurpwrup[10][100]={"res/blur_powerup/Laser_paddle.jpg","res/blur_powerup/grab_paddle.jpg","res/blur_powerup/double_points.jpg","res/blur_powerup/shrink _paddle.jpg",
			"res/blur_powerup/expand_paddle.jpg","res/blur_powerup/kill_paddle.jpg","res/blur_powerup/extra_life.jpg","res/blur_powerup/fast_ball.jpg","res/blur_powerup/slow_ball.jpg"};
	for(int i=0; i<9; i++)
	{
		if(i==5 or i==6) continue;
		surf2=IMG_Load(blurpwrup[i]);
		if(!surf2)
		{
			printf("blur power_up %d Surface Error: %s\n",i,IMG_GetError());
			quit();
			return ;
		}
		powerup_blurtex[i].tex=SDL_CreateTextureFromSurface(rend,surf2);
		SDL_FreeSurface(surf2);
		surf2=NULL;
	}
 	font_load();
}