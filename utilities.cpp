#include "header.h"

// float min(float x, float y)
// {
// 	if(x<y) return x;
// 	return y;
// }
// float max(float x, float y)
// {
// 	if(x>y) return x;
// 	return y;
// }

int gameover_page=0,fire_count=0;
SDL_Texture* convert=NULL;
TTF_Font *Name_and_Score = NULL;
SDL_Texture* background1=NULL;
SDL_Texture* background2=NULL;
SDL_Texture* background3=NULL;
SDL_Texture* level1_back=NULL;
SDL_Texture* level2_back=NULL;
SDL_Texture* level3_back=NULL;

int INITIALIZE()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
    {
		printf("video and timer: %s\n",SDL_GetError());
	}
	
	if(TTF_Init()==-1)
	{
		printf("CANNOT INITIALIAZE TTF %s\n",TTF_GetError());
		return false;
	}
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
	{
		printf("CANNOT INITIALIAZE MIXER %s\n",Mix_GetError());
		return false;
	}
	win = SDL_CreateWindow("DX-BALL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!win)
    {
 		printf("window: %s\n",SDL_GetError());
 		SDL_Quit();
		return 0;
    }
    render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend)
	{
 		printf("renderer: %s\n",SDL_GetError());
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 0;
 	}
    return 1;
}

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

SDL_Texture *DISPLAYING_SCORE(char ch[],int a,int make_null)
{

	if(convert!=NULL and make_null)
	{
		SDL_DestroyTexture(convert);
		convert=NULL;
	}
	
    SDL_Surface *temp;
    

    SDL_Color font_color1 = {0,0,0}; //black
    SDL_Color font_color2 = {255,229,204}; //white

    if(a==0) temp = TTF_RenderText_Solid(Name_and_Score,ch,font_color2);
	else if(a==1) temp=TTF_RenderText_Solid(Name_and_Score,ch,font_color1);
    if(temp == NULL)
    {
        printf("CANNOT CREATE SURFACE FOR TTF %s\n",TTF_GetError());
    }
    else
    {
        convert= SDL_CreateTextureFromSurface(rend,temp);
        if(convert == NULL)
        {
            printf("CANNOT CREATE TEXTURE FOR TTF %s\n",TTF_GetError());
            SDL_FreeSurface(temp);
        }
        else
        {
            SDL_FreeSurface(temp);
        }
    }
	
    return convert;
}

void font_closing()
{
	TTF_CloseFont(Name_and_Score);
}

void name_write()
{
	gameover_page=0;
	SDL_Rect size_name,gameover_rect,texrect;
	gameover_rect.x=gameover_rect.y=0;
	gameover_rect.w=WINDOW_WIDTH;
	gameover_rect.h=WINDOW_HEIGHT;
	size_name.x=WINDOW_WIDTH/2-40;
	size_name.y=WINDOW_HEIGHT/2+25;
	size_name.w=0;
	size_name.h=120;
	texrect.x=WINDOW_WIDTH/2-280;
	texrect.y=WINDOW_HEIGHT/2-100;
	texrect.w=500;
	texrect.h=120;

	char name[20]=" ";
	char t[100]="Please Enter Your Name: ";
	char u[100]="your score is: ";
	u[15]=score/1000+'0';
	u[16]=(score/100)%10+'0';
	u[17]=(score/10)%10+'0';
	u[18]=score%10+'0';
	u[19]='\0';

	int k=1;
	bool hobe=true;
	SDL_StartTextInput();
	FILE *fptr_write;
	fptr_write=fopen("res/Files/name.txt","w");
	while(hobe)
	{
		
		SDL_Event ch;
		while(SDL_PollEvent(&ch))
		{
			if(ch.type==SDL_QUIT) 
			{
				hobe=false;
				close=1;
			}
			else if(ch.type==SDL_TEXTINPUT)
			{
				if(k<=10)
				{
					name[k++]=ch.text.text[0];
					name[k]='\0';
				}
			}
			else if(ch.type==SDL_KEYDOWN)
			{
				
				if(ch.key.keysym.sym==SDLK_BACKSPACE) 
				{
					if(k>1) name[--k]='\0';
				}
				else if(ch.key.keysym.scancode == SDL_SCANCODE_RETURN)
				{
					gameover_page=1;
					fprintf(fptr_write,"%s",name);
					fclose(fptr_write);
				}
			}
		}
		size_name.x=WINDOW_WIDTH/2-40-k*20;
		size_name.w=k*40;
		SDL_Texture* name_print=DISPLAYING_SCORE(name,0,1);
		SDL_Texture* text=DISPLAYING_SCORE(t,0,0);
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend,gameover_tex,NULL,&gameover_rect);
		
		if(gameover_page==0)
		{
			SDL_RenderCopy(rend,text,NULL,&texrect);
			SDL_RenderCopy(rend,name_print,NULL,&size_name);
			SDL_RenderPresent(rend);
		}
		else if(gameover_page==1)
		{
			FILE *fptr_read;
			fptr_read=fopen("res/Files/name.txt","r");
			char tmpname[20];
			fgets(tmpname,15,fptr_read);
			int len=strlen(tmpname);
			SDL_Rect print_rec;
			print_rec.w=len*40;
			print_rec.h=120;
			print_rec.x=550;
			print_rec.y=texrect.y;
			texrect.x=len*40+20+print_rec.x;
			SDL_Texture *ttt=DISPLAYING_SCORE(u,0,0);
			SDL_Texture *tmp_name=DISPLAYING_SCORE(tmpname,0,0);
			SDL_RenderCopy(rend,tmp_name,NULL,&print_rec);
			SDL_RenderCopy(rend,ttt,NULL,&texrect);
			SDL_RenderPresent(rend);
			SDL_Delay(5000);
			SDL_DestroyTexture(ttt);
			SDL_DestroyTexture(tmp_name);
			hobe=false;
			fclose(fptr_read);
		}		
		SDL_DestroyTexture(name_print);
		SDL_DestroyTexture(text);
	}
	SDL_StopTextInput();
	if(score>highscore_array[19].score)
	{
		highscore_array[19].score=score;
		int len=strlen(name);
		for(int i=1; i<12; i++)
		{
			//highscore_array[19].name[i]='\0';
			if(i<len)
			{
				highscore_array[19].name[i-1]=name[i];
				highscore_array[19].name[i]='\0';
			}
		}
		int i=18;
		while (i>=0 and highscore_array[i].score<score)
		{
			char t1[12]=" ";
			strcpy(t1, highscore_array[i].name);
			strcpy(highscore_array[i].name,highscore_array[i+1].name);
			strcpy(highscore_array[i+1].name,t1);
			int t=highscore_array[i].score;
			highscore_array[i].score=highscore_array[i+1].score;
			highscore_array[i+1].score=t;
			i--;
		}
		FILE *fp=NULL;
		fp=fopen("res/Files/highscore.txt","w");
		for(int i=0; i<20; i++)
		{
			fprintf(fp,"%d %s\n",highscore_array[i].score,highscore_array[i].name);
		}
		fclose(fp);
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
 	Name_and_Score = TTF_OpenFont("res/TTF FILE.ttf",72);
    if(Name_and_Score==NULL)
    {
        printf("CANNOT OPEN TTF FILE %s\n",TTF_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
        return ;
    }
}

int levelup_bricks_initialization(int level)
{	
	int cnt=0,bricks_type;
	FILE *fptr;
	for(int i=0; i<150; i++) 
	{
		bricks[i].show=false;
		bricks[i].b1=false;
		bricks[i].b2=false;
		bricks[i].b3=false;
		bricks[i].b4=false;
		bricks[i].b21=false;
		bricks[i].b25=false;
		bricks[i].b27=false;
		bricks[i].b26=false;
		bricks[cnt].b31=true;
		bricks[cnt].b32=true;
		bricks[cnt].b33=true;
		bricks[cnt].b34=true;
		bricks[cnt].b35=true;
		bricks[cnt].b36=true;
		bricks[cnt].b37=true;
		bricks[i].power=0;

	}
	if(level==1)
	{
		fptr=fopen("res/Level_layout/level1.txt","r");
		int sumx=0,sumy=90;
		for(int i=0; i<126; i++)
		{
			fscanf(fptr, "%d" ,&bricks_type);
			bricks[cnt].show=true;
			if(bricks_type==1) bricks[cnt].b1=true;
			else if(bricks_type==2) bricks[cnt].b2=true;
			else if(bricks_type==3) bricks[cnt].b3=true;
			else if(bricks_type==4) bricks[cnt].b4=true;
			bricks[cnt].x=sumx;
			bricks[cnt].y=sumy;
			cnt++;
			sumx+=100;
			if(sumx>=1800)
			{
				sumx=0;
				sumy+=35;
				
			}
		}
	}
	else if(level==2)
	{
		fptr=fopen("res/Level_layout/level2.txt","r");
		int sumx=0,sumy=90;
		for(int i=0; i<144; i++)
		{
			fscanf(fptr, "%d" ,&bricks_type);
			if(bricks_type!=0)
			{
				if(bricks_type==21) bricks[cnt].b21=true,bricks[cnt].power=1;
				else if(bricks_type==25) bricks[cnt].b25=true;
				else if(bricks_type==26) bricks[cnt].b26=true;
				else if(bricks_type==27) bricks[cnt].b27=true;
				bricks[cnt].x=sumx;
				bricks[cnt].y=sumy;
				bricks[cnt].show=true;
				cnt++;
			}
			sumx+=100;
			if(sumx>=1800)
			{
				sumx=0;
				sumy+=35;
				
			}
		}
	}
	else if(level==3)
	{
		fptr=fopen("res/Level_layout/level3.txt","r");
		int sumx=0,sumy=90;
		for(int i=0; i<198; i++)
		{
			fscanf(fptr, "%d" ,&bricks_type);
			if(bricks_type!=0)
			{
				bricks[cnt].show=true;
				if(bricks_type==31) bricks[cnt].b31=true;
				else if(bricks_type==32) bricks[cnt].b32=true;
				else if(bricks_type==33) bricks[cnt].b33=true;
				else if(bricks_type==34) bricks[cnt].b34=true;
				else if(bricks_type==35) bricks[cnt].b35=true;
				else if(bricks_type==36) bricks[cnt].b36=true;
				else if(bricks_type==37) bricks[cnt].b37=true,bricks[cnt].power=1;
				else if(bricks_type==1) bricks[cnt].b1=true;
				else if(bricks_type==2) bricks[cnt].b2=true;
				else if(bricks_type==3) bricks[cnt].b3=true;
				else if(bricks_type==4) bricks[cnt].b4=true;
				bricks[cnt].x=sumx;
				bricks[cnt].y=sumy;
				cnt++;
			}
			sumx+=100;
			if(sumx>=1800)
			{
				sumx=0;
				sumy+=35;
				
			}
			
		}
	}
	fclose(fptr);
	return cnt;

}

void reset_game(int flag)
{
		gameover = 0;
		ball_move=0;
		first_bounce=0;
		bar.w=200;
		pspeed=1.0;
		bar.x = (int) (WINDOW_WIDTH-bar.w)/2;
		bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
		ball.x = (int) bar.x+50;
		ball.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05)+ball.h;
		rect_x =  ball.x;
		rect_y =  ball.y;
		x_pos=bar.x;
		x_vel = BALL_SPEED;
		y_vel = BALL_SPEED*-1;
		gbar=mfbar=fbar=0;
		mbar=1;
		mainmenu=1;
		music_run=1;

		

		for(int i=0; i<50; i++)
		{
			fire_rectarray1[i].show=fire_rectarray2[i].show=0;
			if(i<9) power_up_map[i].type=0;
		}

		if(flag==1) //1 means mainmenut
		{
			first_move=1;
			mainmenu=0;
			life=3;
			level=1;

		}
		else if(flag==2) //2 means bricks zero or level up reeset
		{
			first_move=1;
			rect_y = WINDOW_HEIGHT;
			y_vel = 0;
			x_vel = 0;
			theta=30;
			dx=BALL_SPEED*sin(theta*acos(-1)/180);
			dy=BALL_SPEED*cos(theta*acos(-1)/180);
			mainmenu=0;
			power_up.hoise=0;
		}
		else if(flag==3)
		{
			Mix_HaltMusic();
			music_run=1;
			score=0;
			mainmenu=1-mainmenu;
			mbar=1;
			gbar=fbar=mfbar=0;
			ball_move=0;
			gameover = 0;
			first_move=1;
			ball_move=0;
			bar.x = (int) (WINDOW_WIDTH-bar.w)/2;
			bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
			ball.x = (int) bar.x+50;
			ball.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05)+ball.h;
			rect_x =  ball.x;
			rect_y =  ball.y;
			x_pos=bar.x;
			x_vel = BALL_SPEED;
			y_vel = BALL_SPEED*-1;
			for(int i=0; i<50; i++)
			{
				fire_rectarray1[i].show=fire_rectarray2[i].show=0;
			}
			life=3;
			level=1;
			bricks_showed=levelup_bricks_initialization(level);
		}
}

void lbutton()
{
	if(first_move)
	{
		first_move=0;
		ball_move=1;
		gbar=1;
		mbar=0;
		dx=BALL_SPEED*sin(theta*acos(-1)/180),dy=BALL_SPEED*cos(theta*acos(-1)/180);
	}
	else ball_move=1;
	if((mfbar or fbar) and ball_move and fire_left>0)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,fire_init,0);
		fire_rectarray1[fire_count].rec.h=25;
		fire_rectarray1[fire_count].rec.w=6;
		fire_rectarray1[fire_count].rec.x=x_pos+9;
		fire_rectarray1[fire_count].rec.y=bar.y-25;
		fire_rectarray2[fire_count].rec.h=25;
		fire_rectarray2[fire_count].rec.w=6;
		fire_rectarray2[fire_count].rec.x=x_pos+bar.w-16;
		fire_rectarray2[fire_count].rec.y=bar.y-25;
		fire_rectarray1[fire_count].show=1;
		fire_rectarray2[fire_count].show=1;
		fire_count++;
		fire_left--;
		if(fire_left<=0)
		{
			for(int i=0; i<50; i++)
			{
				fire_rectarray1[i].show=fire_rectarray2[i].show=0;
			}
			power_up_map[0].type = 0;
			if(mfbar)
			{
				mfbar=0;
				mbar=1;
			}
			else if(fbar)
			{
				fbar=0;
				gbar=1;
			}
		}
		if(fire_count>=50) fire_count=0;
	}
}







