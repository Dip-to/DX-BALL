#include "header.h"

float pupx_vel = 0;
float pupy_vel = 0;
int var=0;

SDL_Rect powerup_gameplay_rect;
SDL_Texture* score_ttf_tex=NULL;
SDL_Texture* firetex=NULL;
SDL_Surface* bricks_surface=NULL;
//bricks tex
SDL_Texture* bricks1=NULL;
SDL_Texture* bricks2=NULL;
SDL_Texture* bricks3=NULL;
SDL_Texture* bricks4=NULL;
SDL_Texture* bricks5=NULL;
SDL_Texture* bricks21=NULL;
SDL_Texture* bricks21_1=NULL;
SDL_Texture* bricks25=NULL;
SDL_Texture* bricks26=NULL;
SDL_Texture* bricks27=NULL;
SDL_Texture* bricks31=NULL;
SDL_Texture* bricks32=NULL;
SDL_Texture* bricks33=NULL;
SDL_Texture* bricks34=NULL;
SDL_Texture* bricks35=NULL;
SDL_Texture* bricks36=NULL;

void score_and_life_print(int score,int life)
{    
			
			SDL_Rect scr,lif;
			scr.w=250;
			scr.h=75;
			scr.x=scr.y=0;
			int sc1=score/1000,sc2=(score/100)%10,sc3=(score/10)%10,sc4=score%10;		
			char score_str[11]={"Score:"};
			score_str[6]=sc1+'0';
			score_str[7]=sc2+'0';
			score_str[8]=sc3+'0';
			score_str[9]=sc4+'0';
			score_str[10]='\0';
			score_ttf_tex=DISPLAYING_SCORE(score_str,0,1);
			SDL_RenderCopy(rend,score_ttf_tex,NULL,&scr);
			//life
			lif.h=20,lif.w=80;
			lif.x=1700,lif.y=2;
			for(int sho=0; sho<life; sho++)
			{
				SDL_RenderCopy(rend, liferend, NULL, &lif);
				lif.x-=90;
			}
			powerup_gameplay_rect.w=60;
			powerup_gameplay_rect.h=45;
			powerup_gameplay_rect.x=680;
			powerup_gameplay_rect.y=0;
			for(int i=0; i<9; i++)
			{
				if(i==5 or i==6) continue;
				if(power_up_map[i].type) SDL_RenderCopy(rend,poweruptex[i].tex,NULL,&powerup_gameplay_rect);
				else SDL_RenderCopy(rend,powerup_blurtex[i].tex,NULL,&powerup_gameplay_rect);
				powerup_gameplay_rect.x+=63;
			}


}
void firerender(int fbar)
{
	if(fbar==1)
	{
		for(int i=0; i<50; i++)
		{
			if(fire_rectarray1[i].show or fire_rectarray2[i].show)
			{
				if(fire_rectarray1[i].show)
				SDL_RenderCopy(rend,firetex,NULL,&fire_rectarray1[i].rec);
				if(fire_rectarray2[i].show)
				SDL_RenderCopy(rend,firetex,NULL,&fire_rectarray2[i].rec);
				fire_rectarray1[i].rec.y-=25;
				fire_rectarray2[i].rec.y-=25;
				if(fire_rectarray1[i].rec.y<=0) fire_rectarray1[i].show=0;
				if(fire_rectarray2[i].rec.y<=0) fire_rectarray2[i].show=0;
			}
		}
	}
}

void bricks_and_bar_load()
{
	//bar
	char gnrlbar[4][100]={"res/gnrl_bar/gbar1.jpg","res/gnrl_bar/gbar2.jpg",
						"res/gnrl_bar/gbar3.jpg","res/gnrl_bar/gbar4.jpg"};
	char magfirebar[4][100]={"res/magfire_bar/mfbar1.jpg","res/magfire_bar/mfbar2.jpg",
							"res/magfire_bar/mfbar3.jpg","res/magfire_bar/mfbar4.jpg"};
	char firebar[4][100]={"res/fire_bar/fbar1.jpg","res/fire_bar/fbar2.jpg",
							"res/fire_bar/fbar3.jpg","res/fire_bar/fbar4.jpg"};
	char magneticbar[4][100]={"res/magnet_bar/mbar1.jpg","res/magnet_bar/mbar2.jpg",
							"res/magnet_bar/mbar3.jpg","res/magnet_bar/mbar4.jpg"};
	SDL_Surface* tmp1=NULL;
	SDL_Surface* tmp2=NULL;
	SDL_Surface* tmp3=NULL;
	SDL_Surface* tmp4=NULL;

	for(int i=0; i<4; i++)
	{
		tmp1=IMG_Load(gnrlbar[i]);
		tmp2=IMG_Load(magneticbar[i]);
		tmp3=IMG_Load(magfirebar[i]);
		tmp4=IMG_Load(firebar[i]);
		if (!tmp1 || !tmp2 || !tmp3 || !tmp4)
		{
			printf("Bar load %d Surface Error: %s\n",i,IMG_GetError());
			SDL_DestroyRenderer(rend);
			SDL_DestroyWindow(win);
			SDL_Quit();
			return ;
		}
		gbartex[i].tex=SDL_CreateTextureFromSurface(rend,tmp1);
		mbartex[i].tex=SDL_CreateTextureFromSurface(rend,tmp2);
		mfbartex[i].tex=SDL_CreateTextureFromSurface(rend,tmp3);
		fbartex[i].tex=SDL_CreateTextureFromSurface(rend,tmp4);
		SDL_FreeSurface(tmp1);
		SDL_FreeSurface(tmp2);
		SDL_FreeSurface(tmp3);
		SDL_FreeSurface(tmp4);

	}
	
	//bricks_intialize
	bricks_surface=IMG_Load("res/Bricks/tile1.jpg");
	if (!bricks_surface)
	{
		printf("bricks1 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks1=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile2.jpg");
	if (!bricks_surface)
	{
		printf("bricks2 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks2=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile3.jpg");
	if (!bricks_surface)
	{
		printf("bricks3 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks3=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile4.jpg");
	if (!bricks_surface)
	{
		printf("bricks4 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks4=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile21.jpg");
	if (!bricks_surface)
	{
		printf("bricks21 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks21=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile21_1.jpg");
	if (!bricks_surface)
	{
		printf("bricks21_1 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks21_1=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile25.jpg");
	if (!bricks_surface)
	{
		printf("bricks25 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks25=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile26.jpg");
	if (!bricks_surface)
	{
		printf("bricks26 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks26=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	
	bricks_surface=IMG_Load("res/Bricks/tile27.jpg");
	if (!bricks_surface)
	{
		printf("bricks27 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks27=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile31.jpg");
	if (!bricks_surface)
	{
		printf("bricks31 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks31=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile32.jpg");
	if (!bricks_surface)
	{
		printf("bricks32 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks32=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile33.jpg");
	if (!bricks_surface)
	{
		printf("bricks33 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks33=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface=IMG_Load("res/Bricks/tile34.jpg");
	if (!bricks_surface)
	{
		printf("bricks34 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks34=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile35.jpg");
	if (!bricks_surface)
	{
		printf("bricks35 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks35=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile36.jpg");
	if (!bricks_surface)
	{
		printf("bricks36 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks36=SDL_CreateTextureFromSurface(rend,bricks_surface);
	SDL_FreeSurface(bricks_surface);

	
	//fire load
	tmp1=IMG_Load("res/fire.jpg");
	if (!tmp1)
	{
		printf("Fire load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	firetex=SDL_CreateTextureFromSurface(rend,tmp1);
	SDL_FreeSurface(tmp1);
}

int bar_and_bricks_render(int cnt,int l)
{
	//bar
	if(cnt%1==0)
	{
		if(gbar==1)
		{
			bar.h=25;
			bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05)+17;
			if(cnt<=5)
			{
				SDL_RenderCopy(rend, gbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=10)
			{
				SDL_RenderCopy(rend, gbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=15)
			{
				SDL_RenderCopy(rend, gbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=20)
			{
				SDL_RenderCopy(rend, gbartex[3].tex, NULL, &bar);
				if(cnt==20) cnt=0;
				else cnt++;
			}
		}
		else if(mbar==1)
		{
			
			bar.h=40;
			bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
			if(cnt<=5)
			{
				SDL_RenderCopy(rend, mbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=10)
			{
				SDL_RenderCopy(rend, mbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=15)
			{
				SDL_RenderCopy(rend, mbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=20)
			{
				SDL_RenderCopy(rend, mbartex[3].tex, NULL, &bar);
				if(cnt==20) cnt=0;
				else cnt++;
			}
		}
		else if(fbar==1)
		{
			
			bar.h=40;
			bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
			if(cnt<=5)
			{
				SDL_RenderCopy(rend, fbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=10)
			{
				SDL_RenderCopy(rend, fbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=15)
			{
				SDL_RenderCopy(rend, fbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=20)
			{
				SDL_RenderCopy(rend, fbartex[3].tex, NULL, &bar);;
				if(cnt==20) cnt=0;
					else cnt++;
			}
		}
		else if(mfbar==1)
		{
			
			bar.h=40;
			bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
			if(cnt<=5)
			{
				SDL_RenderCopy(rend, mfbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=10)
			{
				SDL_RenderCopy(rend, mfbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=15)
			{
				SDL_RenderCopy(rend, mfbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if(cnt<=20)
			{
				SDL_RenderCopy(rend, mfbartex[3].tex, NULL, &bar);
				if(cnt==20) cnt=0;
				else cnt++;
			}
			
		}
		
	}
	else cnt++;
	//bricks
	if(l==1)
	{
		for(int i=0; i<126; i++)
		{
			SDL_Rect br;
			if(bricks[i].show)
			{
				
				br.w=bricks[i].dx;
				br.h=bricks[i].dy;
				br.x=bricks[i].x;
				br.y=bricks[i].y;
				if(bricks[i].b1)
				{
					SDL_RenderCopy(rend, bricks1, NULL, &br);
				}
				else if(bricks[i].b2)
				{
					SDL_RenderCopy(rend, bricks2, NULL, &br);
				}
				else if(bricks[i].b3)
				{
					SDL_RenderCopy(rend, bricks3, NULL, &br);
				}
				else if(bricks[i].b4)
				{
					SDL_RenderCopy(rend, bricks4, NULL, &br);
				}
				
				
			}
		}
	}
	else if(l==2)
	{
		for(int i=0; i<totalbricks; i++)
		{
			SDL_Rect br;
			if(bricks[i].show)
			{
				
				br.w=bricks[i].dx;
				br.h=bricks[i].dy;
				br.x=bricks[i].x;
				br.y=bricks[i].y;
				if(bricks[i].b21)
				{
					SDL_RenderCopy(rend, bricks21, NULL, &br);
				}
				else if(bricks[i].b25)
				{
					SDL_RenderCopy(rend, bricks25, NULL, &br);
				}
				else if(bricks[i].b26)
				{
					SDL_RenderCopy(rend, bricks26, NULL, &br);
				}
				else if(bricks[i].b27)
				{
					SDL_RenderCopy(rend, bricks27, NULL, &br);
				}	
				else if(bricks[i].b21_1)
				{
					SDL_RenderCopy(rend, bricks21_1, NULL, &br);
				}
			}
		}

	}
	else if(l==3)
	{
		for(int i=0; i<totalbricks; i++)
		{
			SDL_Rect br;
			if(bricks[i].show)
			{
				br.w=bricks[i].dx;
				br.h=bricks[i].dy;
				br.x=bricks[i].x;
				br.y=bricks[i].y;
				if(bricks[i].b31)
				{
					SDL_RenderCopy(rend, bricks31, NULL, &br);
				}
				else if(bricks[i].b32)
				{
					SDL_RenderCopy(rend, bricks32, NULL, &br);
				}
				else if(bricks[i].b33)
				{
					SDL_RenderCopy(rend, bricks33, NULL, &br);
				}
				else if(bricks[i].b34)
				{
					SDL_RenderCopy(rend, bricks34, NULL, &br);
				}	
				else if(bricks[i].b35)
				{
					SDL_RenderCopy(rend, bricks35, NULL, &br);
				}
				else if(bricks[i].b36)
				{
					SDL_RenderCopy(rend, bricks36, NULL, &br);
				}	
				else if(bricks[i].b1)
				{
					SDL_RenderCopy(rend, bricks1, NULL, &br);
				}
				else if(bricks[i].b2)
				{
					SDL_RenderCopy(rend, bricks2, NULL, &br);
				}	
				else if(bricks[i].b3)
				{
					SDL_RenderCopy(rend, bricks3, NULL, &br);
				}
				else if(bricks[i].b4)
				{
					SDL_RenderCopy(rend, bricks4, NULL, &br);
				}	
			}
		}
	}

	return cnt;
}
void powerup_achieve()
{
	power_up.hoise=0;
	if(power_up.type==0 )
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,life_laser_grab_music,0);
		score+=5;
		power_up_map[power_up.type].type=1;
		if(mbar==1 or mfbar==1) //fire
		{
			mfbar=1;
			gbar=mbar=fbar=0;
		}
		else 
		{
			fbar=1;
			gbar=mfbar=mbar=0;
		}
		
	}
	else if(power_up.type==1)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,life_laser_grab_music,0);
		score+=5;
		power_up_map[power_up.type].type=1;
		if(fbar==1 or mfbar==1) //magnet
		{
			mfbar=1;
			gbar=mbar=fbar=0;
		}
		else 
		{
			mbar=1;
			gbar=mfbar=fbar=0;
		}
		
	}
	else if(power_up.type==2)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,score_double,0);
		score+=5;
		power_up_map[power_up.type].type=1;
		//scoredouble incomplete
		
	}
	else if(power_up.type==3)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,shrink_paddle_music,0);
		score+=5;
		spaddle=1;
		power_up_map[power_up.type].type=1;
		if(epaddle)
		{
			epaddle=spaddle=0;
			power_up_map[4].type=0;
			power_up_map[power_up.type].type=0;
		} 
		bar.w=max(100,bar.w/2); //shrink paddle		
	}
	else if(power_up.type==4)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,expand_paddle_music,0);
		score+=5;
		epaddle=1;
		power_up_map[power_up.type].type=1;
		if(spaddle) 
		{
			epaddle=spaddle=0;
			power_up_map[3].type=0;
			power_up_map[power_up.type].type=0;
		}
		bar.w=min(400,bar.w*2);
		
	}
	else if(power_up.type==5 )
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,game_over_music,0);
		score+=5;
		power_up_map[power_up.type].type=1;
		//gameover
	}
	else if(power_up.type==6)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,life_laser_grab_music,0);
		score+=5;
		power_up_map[power_up.type].type=1;
		life++; //life		
	}
	else if(power_up.type==7)
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,fast_ball_music,0);
		score+=5;
		power_up_map[power_up.type].type=1;
		//BALL_SPEED=min(BALL_SPEED*2,30); //fast ball
		if(pspeed<1.0) pspeed=1.0;
		else if(pspeed==1.0) pspeed=2.0;
		else pspeed=2.0;
		if(!fspeed)	dx*=pspeed,dy*=pspeed;
		printf("%f\n",pspeed);
		// dx/=2;
		fspeed=1;
		sspeed=0;
		
	}
	else if(power_up.type==8)
	{
		score+=5;
		if(gamesound==1)
		Mix_PlayChannel(-1,slow_ball_music,0);
		power_up_map[power_up.type].type=1;
		if(pspeed<=0.500000) pspeed=0.5;
		else if(pspeed<=1.000000) pspeed=0.5;
		else if(pspeed>1.000000) pspeed=1.0;
		printf("%f\n",pspeed);
		if(!sspeed)	dx*=pspeed,dy*=pspeed;
		// dx/=2;
		sspeed=1;
		fspeed=0;
	}

}

void powerup_renderer(int p, int type)
{	
	if(p)
	{
		SDL_RenderCopy(rend,poweruptex[type].tex,NULL,&powerup_rec);
	}
}
void game_physics()
{
		if(ball_move==0 and first_move)
		{
			bar.x = (int) x_pos;
			ball.x = (int) bar.x+50;
			ball.y = (int) rect_y;
			rect_x=ball.x;
			rect_y=bar.y;
			dx=0;
			dy=0;
		}
		else if(first_move==0 and (mbar==1 or mfbar==1) and !ball_move)
		{
			
			bar.x = (int) x_pos;
			ball.x = (int) bar.x+var;
			ball.y = (int) rect_y;
			rect_x=ball.x;
			rect_y=ball.y;
			dx=0;
			dy=0;
		}
		else
		{
			bar.x = (int) x_pos;
			ball.x = (int) rect_x;
			ball.y = (int) rect_y;
			//dx=BALL_SPEED*sin(theta*acos(-1)/180),dy=BALL_SPEED*cos(theta*acos(-1)/180);
		}
		//power up
	if(power_up.hoise==1)
	{
		pup_x+=pupx_vel;
		pup_y+=pupy_vel;
		if(pup_x<=0)
		{
			pup_x=0;
			pupx_vel=-pupx_vel;
		}
		if(pup_y<=0)
		{
			pup_y = 0;
			pupy_vel = -pupy_vel;
		}
		if(pup_x>=(WINDOW_WIDTH-powerup_rec.w))
		{
			pup_x = WINDOW_WIDTH-powerup_rec.w;
			pupx_vel = -pupx_vel;
		}
		if(pup_y+powerup_rec.h>=(WINDOW_HEIGHT))
		{
			power_up.hoise=0;
			pupx_vel=0;
			pupy_vel=0;
		}
		powerup_rec.x=pup_x;
		powerup_rec.y=pup_y;
		// char pwrup[10][100]={
		// 0"res/Power_up/double_points.jpg",1"res/Power_up/expand_paddle.jpg",
		// 2"res/Power_up/extra_life.jpg","3res/Power_up/fast_ball.jpg",
		// 4"res/Power_up/grab_paddle.jpg",5"res/Power_up/kill_paddle.jpg",
		// 6"res/Power_up/Laser_paddle.jpg",7"res/Power_up/shrink _paddle.jpg",
		// 8"res/Power_up/slow_ball.jpg"};
		if(gbar==1)
		{
			if(pup_y+powerup_rec.h >= (bar.y) && pup_x>=(bar.x-powerup_rec.w) && pup_x<=(bar.x+bar.w))
			{
				powerup_achieve();
			}
		}
		else
		{
			if( pup_y+powerup_rec.h >= (bar.y) && pup_x>=(bar.x-powerup_rec.w) && pup_x<=(bar.x+bar.w))
			{
				powerup_achieve();
			}
		}


	}
	rect_x +=dx;
	rect_y += dy;	
	if(rect_x<=0)
	{
		rect_x = 0;
		x_vel = -x_vel;
		dx=-dx;
	}
	if(rect_y<=0)
	{
		rect_y = 0;
		y_vel = -y_vel;
		dy=-dy;
	}
	if(rect_x>=(WINDOW_WIDTH-ball.w))
	{
		rect_x = WINDOW_WIDTH-ball.w;
		x_vel = -x_vel;
		dx=-dx;
	}
	//dead
	if(rect_y+ball.h>=(WINDOW_HEIGHT))
	{
		if(gamesound==1)
		Mix_PlayChannel(-1,game_over_music,0);
		rect_y = WINDOW_HEIGHT;
		first_bounce=0;
		y_vel = 0;
		x_vel = 0;
		fspeed=0;
		sspeed=0;
		theta=30;
		pspeed=1.0;
		dx=BALL_SPEED*sin(theta*acos(-1)/180);
		dy=BALL_SPEED*cos(theta*acos(-1)/180);
		first_move=1;
		gameover = 0;
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
		life-=1;
		if(life==0)
		{
			gameover=1;
			
		}
		gbar=mfbar=fbar=0;
		mbar=1;
		for(int i=0; i<50; i++)
		{
			fire_rectarray1[i].show=fire_rectarray2[i].show=0;
			if(i<9) power_up_map[i].type=0;
		}
		bar.w=200;
	}
	//collision
	int rball=ball.w/2;
	int colided=false;
	//printf("%d\n",bricks_showed);
	for(int i=0;i<150;i++)
	{
			int col=false;
			
			if(bricks_showed<=0)
			{
				
				if(bricks_showed<=2 and colided)
				{
					int ccc=0;
					colided=false;
					for(int i=0; i<150; i++)
					{
						if(bricks[i].show)
						{
							ccc++;
						}
					}
					if(ccc>0)
					{
						bricks_showed=ccc;
					}
				}
				if(bricks_showed>0)
				{
					break;
				}
				level++;
				if(level==4)
				{
					gameover=1;
					break;
				}
				bricks_showed=levelup_bricks_initialization(level);
				totalbricks=bricks_showed;
				reset_game(2);
				break;

			}

			if(bricks[i].show==true)
			{
				if((rect_x>=bricks[i].x&&rect_x<=bricks[i].x+bricks[i].dx)&&rect_y>=bricks[i].y-ball.h && rect_y<=bricks[i].y-ball.h+bricks[i].dy)//from top (rect_y>=bricks[i].y&&rect_y<=bricks[i].y+bricks[i].dy)
				{
					colided=true;
					if(score%120==0 and score and !power_up.hoise )
					{
						if(gamesound==1)
						Mix_PlayChannel(-1,powerup_init_music,0);
						srand(time(0));
						power_up.type=rand()%9;
						if(power_up.type==8 and fspeed) power_up.type=6;
						else if(power_up.type==7 and sspeed) power_up.type=5;

						powerup_rec.x=rect_x;
						powerup_rec.y=rect_y;
						pup_x=rect_x;
						pup_y=rect_y;
						pupx_vel=BALL_SPEED-10;
						pupy_vel=-BALL_SPEED-10;
						power_up.hoise=1;
					}
					dy*=(-1);
					bricks[i].show=false;
					rect_y+=ball.h; 
					score+=5; 
					bricks_showed--; 
					if(bricks[i].power)
					{
						if(gamesound==1) Mix_PlayChannel(-1,hardbricks,0);
						bricks[i].power--;
						bricks[i].show=true;
						bricks[i].b21_1=true;
						bricks[i].b21=false;
						bricks_showed++;
					}
					else 
					{
						if(gamesound==1) Mix_PlayChannel(-1,ball_bricks_collision,0);
					}
					break;
										
				}
				else if((rect_x>=bricks[i].x&&rect_x<=bricks[i].x+bricks[i].dx)&& rect_y>=bricks[i].y && rect_y<=bricks[i].y+bricks[i].dy)//from below (rect_y>=bricks[i].y&&rect_y<=bricks[i].y+bricks[i].dy)
				{
					colided=true;
					if(score%120==0 and score and !power_up.hoise )
					{
						if(gamesound==1)
						Mix_PlayChannel(-1,powerup_init_music,0);
						srand(time(0));
						power_up.type=rand()%9;
						if(power_up.type==8 and fspeed) power_up.type=6;
						else if(power_up.type==7 and sspeed) power_up.type=5;
						powerup_rec.x=rect_x;
						powerup_rec.y=rect_y;
						pup_x=rect_x;
						pup_y=rect_y;
						pupx_vel=BALL_SPEED-10;
						pupy_vel=-BALL_SPEED-10;
						power_up.hoise=1;
					}
					dy*=(-1);
					bricks[i].show=false;
					//rect_y=bricks[i].y;
					//rect_y-=ball.h;
					//SDL_Delay(2000);
					bricks_showed--; 
					score+=5; 
					if(bricks[i].power)
					{
						if(gamesound==1) Mix_PlayChannel(-1,hardbricks,0);
						bricks[i].power--;
						bricks[i].show=true;
						bricks[i].b21_1=true;
						bricks[i].b21=false;
						bricks_showed++;
					}
					else 
					{
						if(gamesound==1) Mix_PlayChannel(-1,ball_bricks_collision,0);
					}
					break;
				
				}
				else if((rect_x>=bricks[i].x&&rect_x<=bricks[i].x+bricks[i].dx)&&(rect_y+ball.h>=bricks[i].y&&rect_y<=bricks[i].y+bricks[i].dy))//from right
				{
					colided=true;
					if(score%120==0 and score and !power_up.hoise)
					{
						if(gamesound==1)
						Mix_PlayChannel(-1,powerup_init_music,0);
						srand(time(0));
						power_up.type=rand()%9;
						if(power_up.type==8 and fspeed) power_up.type=6;
						else if(power_up.type==7 and sspeed) power_up.type=5;
						powerup_rec.x=rect_x;
						powerup_rec.y=rect_y;
						pup_x=rect_x;
						pup_y=rect_y;
						pupx_vel=BALL_SPEED-10;
						pupy_vel=-BALL_SPEED-10;
						power_up.hoise=1;
					}
					dx*=(-1);
					bricks[i].show=false;
					//rect_x=bricks[i].x-rball;
					score+=5; 
					bricks_showed--; 
					if(bricks[i].power)
					{
						if(gamesound==1) Mix_PlayChannel(-1,hardbricks,0);
						bricks[i].power--;
						bricks[i].show=true;
						bricks[i].b21_1=true;
						bricks[i].b21=false;
						bricks_showed++;
					}
					else 
					{
						if(gamesound==1) Mix_PlayChannel(-1,ball_bricks_collision,0);
					}
					break;
				
				}
				else if((rect_x+ball.w>=bricks[i].x&&rect_x<=bricks[i].x+bricks[i].dx)&&(rect_y+ball.h>=bricks[i].y&&rect_y<=bricks[i].y+bricks[i].dy))//from left
				{

					colided=true;
					if(score%120==0 and score and !power_up.hoise )
					{
						if(gamesound==1)
						Mix_PlayChannel(-1,powerup_init_music,0);
						srand(time(0));
						power_up.type=rand()%9;
						if(power_up.type==8 and fspeed) power_up.type=6;
						else if(power_up.type==7 and sspeed) power_up.type=5;
						powerup_rec.x=rect_x;
						powerup_rec.y=rect_y;
						pup_x=rect_x;
						pup_y=rect_y;

						pupx_vel=BALL_SPEED-10;
						pupy_vel=-BALL_SPEED-10;
						power_up.hoise=1;
					}
					dx*=(-1);
					bricks[i].show=false;
					//rect_x=bricks[i].x+bricks[i].dx+rball;
					score+=5; 
					bricks_showed--; 
					//SDL_Delay(2000);
					if(bricks[i].power)
					{
						if(gamesound==1) Mix_PlayChannel(-1,hardbricks,0);
						bricks[i].power--;
						bricks[i].show=true;
						bricks[i].b21_1=true;
						bricks[i].b21=false;
						bricks_showed++;
					}
					else 
					{
						if(gamesound==1) Mix_PlayChannel(-1,ball_bricks_collision,0);
					}
					break;
				
				}
				if((fbar==1 || mfbar==1))
				{
					
					for(int j=0; j<50; j++)
					{
						if(fire_rectarray1[j].show or fire_rectarray2[j].show)
						{
							if(fire_rectarray1[j].rec.x>=bricks[i].x and fire_rectarray1[j].rec.x<=bricks[i].x+bricks[i].dx and fire_rectarray1[j].rec.y<= bricks[i].y+bricks[i].dy)
							{
								colided=true;
								if(score%120==0 and score and !power_up.hoise)
								{
									if(gamesound==1)
									Mix_PlayChannel(-1,powerup_init_music,0);
									srand(time(0));
									power_up.type=rand()%9;
									if(power_up.type==8 and fspeed) power_up.type=6;
									else if(power_up.type==7 and sspeed) power_up.type=5;
									powerup_rec.x=bricks[i].x;
									powerup_rec.y=bricks[i].y;
									pup_x=bricks[i].x;
									pup_y=bricks[i].y;
									pupx_vel=BALL_SPEED-10;
									pupy_vel=-BALL_SPEED-10;
									power_up.hoise=1;
								}
								bricks[i].show=false;
								score+=5;
								fire_rectarray1[j].show=0;
								fire_rectarray1[j].rec.h=0;
								fire_rectarray1[j].rec.y=1900;
								fire_rectarray1[j].rec.x=1900;
								fire_rectarray1[j].rec.w=0;
								bricks_showed--; 
								if(bricks[i].power)
								{
									if(gamesound==1) Mix_PlayChannel(-1,hardbricks,0);
									bricks[i].power--;
									bricks[i].show=true;
									bricks[i].b21_1=true;
									bricks[i].b21=false;
									bricks_showed++;
									
								}
								else 
								{
									if(gamesound==1) Mix_PlayChannel(-1,ball_bricks_collision,0);
								}
								col=true;
							}
							if(fire_rectarray2[j].rec.x>=bricks[i].x and fire_rectarray2[j].rec.x<=bricks[i].x+bricks[i].dx and fire_rectarray2[j].rec.y<= bricks[i].y+bricks[i].dy)
							{
								colided=true;
								if(score%120==0 and score and !power_up.hoise)
								{
									if(gamesound==1)
									Mix_PlayChannel(-1,powerup_init_music,0);
									srand(time(0));
									power_up.type=rand()%9;
									if(power_up.type==8 and fspeed) power_up.type=6;
									else if(power_up.type==7 and sspeed) power_up.type=5;
									powerup_rec.x=bricks[i].x;
									powerup_rec.y=bricks[i].y;
									pup_x=bricks[i].x;
									pup_y=bricks[i].y;
									pupx_vel=BALL_SPEED-10;
									pupy_vel=-BALL_SPEED-10;
									power_up.hoise=1;
								}
								bricks[i].show=false;
								score+=5;
								fire_rectarray2[j].show=0;
								bricks_showed--;
								fire_rectarray2[j].rec.h=0;
								fire_rectarray2[j].rec.y=1900;
								fire_rectarray2[j].rec.x=1900;
								fire_rectarray2[j].rec.w=0; 
								if(bricks[i].power)
								{
									if(gamesound==1) Mix_PlayChannel(-1,hardbricks,0);
									bricks[i].power--;
									bricks[i].show=true;
									bricks[i].b21_1=true;
									bricks[i].b21=false;
									bricks_showed++;

								}
								else 
								{
									if(gamesound==1) Mix_PlayChannel(-1,ball_bricks_collision,0);
								}
								col=true;
							}
						}
						if(col) true;
					}
				}
				if(col) true;			
			}
	}
	

	if(gbar==1)
	{
		if(rect_y+ball.h >= (bar.y) && rect_x>=(bar.x-ball.w) && rect_x<=(bar.x+bar.w))
		{
			if(first_bounce && gamesound==1)  Mix_PlayChannel(-1,bar_paddle_collision,0);
			first_bounce=1;
			rect_y = bar.y-ball.h;
			y_vel = -y_vel;
			dy=-dy;
			theta=(bar.w-(rect_x-bar.x))/(bar.w/2)*90;
			dx=BALL_SPEED*cos(theta*acos(-1)/180),dy=BALL_SPEED*sin(theta*acos(-1)/180)*(-1);
			dx*=pspeed;
			//rect_y=bar.y-ball.h;
		}
	}
	else
	{
		if( rect_y >= (bar.y) && rect_x>=(bar.x-ball.w) && rect_x<=(bar.x+bar.w))
		{
			//rect_y = bar.y;
			//dy=-dy;
			if(ball_move and !first_move and gamesound==1) Mix_PlayChannel(-1,bar_paddle_collision,0);
			theta=(bar.w-(rect_x-bar.x))/(bar.w/2)*90;
			dx=BALL_SPEED*cos(theta*acos(-1)/180),dy=BALL_SPEED*sin(theta*acos(-1)/180)*(-1);
			dx*=pspeed;
			rect_y = bar.y;
			if((mbar==1 or mfbar==1) && ball_move)
			{
				ball_move=0;
				var=ball.x-bar.x;
				x_vel=0;
				y_vel=0;
			}
		}
	}
	//printf("ball x %d ball y%d\n bar x %d bar x2 %d y %d\n\n",ball.x,ball.y,bar.x,bar.x+bar.w,bar.y);
	if((abs(dy))<=0.7999999)
	{
		double sign=dy/(abs(dy));
		dy=0.8*sign;
	//	printf("baal %lf\n",dy);
	}

}

void level_destroy()
{
	SDL_DestroyTexture(bricks1);
	SDL_DestroyTexture(bricks2);
	SDL_DestroyTexture(bricks3);
	SDL_DestroyTexture(bricks4);
	SDL_DestroyTexture(bricks5);
	SDL_DestroyTexture(bricks31);
	SDL_DestroyTexture(bricks32);
	SDL_DestroyTexture(bricks33);
	SDL_DestroyTexture(bricks34);
	SDL_DestroyTexture(bricks35);
	SDL_DestroyTexture(bricks36);
	SDL_DestroyTexture(firetex);
	SDL_DestroyTexture(score_ttf_tex);
	bricks1=NULL;
	bricks2=NULL;
	bricks3=NULL;
	bricks4=NULL;
	bricks5=NULL;
	firetex=NULL;
	score_ttf_tex=NULL;
}

