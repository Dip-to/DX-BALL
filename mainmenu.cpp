#include "header.h"

int level2,level1,level3,enter=0,uivar=0,pvar=0,ovar=0,hvar=0,povar=0,covar=0,ivar=0,nvar=0,evar=0;
int Hscore=0,Help=0,Instruction=0,Controls=0,Powerup_info=0,Instruction2=0,option=0,game_sesh=0,next_button=0;
//main menu
SDL_Rect instruction,controls,powerup_info,high_up,high_body,next,control_body,powerup_info_body,instruction_body;
SDL_Rect background_main_menu, dxball, laser, slowball, extralife, doublepoint, killpaddle, fastball_1, New_game;
SDL_Rect fastball_2, shrinkpaddle, expandpaddle, New_game2, help, help2, high_score, high_score2, exit2;
SDL_Rect exi,front_ball,grabpaddle,r_u_sure,yes,no,exit_back,options,options_back,sound_on,sound_off,back,sound_font,sound_on2,sound_off2,game_sound,gamesound_on,gamesound_off,gamesound_on2,gamesound_off2;
//main menu
//main menu texture
SDL_Texture* gameover_tex=NULL;
SDL_Texture* mainback_tex=NULL;
SDL_Texture* New_game_tex=NULL;
SDL_Texture* help_tex=NULL;
SDL_Texture* high_score_tex=NULL;
SDL_Texture* exit_tex=NULL;
SDL_Texture* r_u_sure_tex=NULL;
SDL_Texture* yes_tex=NULL;
SDL_Texture* no_tex=NULL;
SDL_Texture* exit_back_tex=NULL;
SDL_Texture* yes_tex2=NULL;
SDL_Texture* no_tex2=NULL;
SDL_Texture* options_tex=NULL;
SDL_Texture* options_back_tex=NULL;
SDL_Texture* sound_on_tex=NULL;
SDL_Texture* sound_off_tex=NULL;
SDL_Texture* sound_on2_tex=NULL;
SDL_Texture* sound_off2_tex=NULL;
SDL_Texture* back_tex=NULL;
SDL_Texture* back2_tex=NULL;
SDL_Texture* sound_font_tex=NULL;
SDL_Texture* gamesound_on_tex=NULL;
SDL_Texture* gamesound_off_tex=NULL;
SDL_Texture* gamesound_on2_tex=NULL;
SDL_Texture* gamesound_off2_tex=NULL;
SDL_Texture* game_sound_tex=NULL;
SDL_Texture* instruction_tex=NULL;
SDL_Texture* controls_tex=NULL;
SDL_Texture* powerup_info_tex=NULL;
SDL_Texture* instruction2_tex=NULL;
SDL_Texture* controls2_tex=NULL;
SDL_Texture* powerup_info2_tex=NULL;
SDL_Texture* high_up_tex=NULL;
SDL_Texture* high_body_tex=NULL;
SDL_Texture* next_tex=NULL;
SDL_Texture* next2_tex=NULL;
SDL_Texture* help_back_tex=NULL;
SDL_Texture* control_body_tex=NULL;
SDL_Texture* powerup_info_body_tex=NULL;
SDL_Texture* instruction_body_tex=NULL;
SDL_Texture* instruction2_body_tex=NULL;
SDL_Texture* pause_back_tex=NULL;
SDL_Texture* instruction_back_tex=NULL;
SDL_Texture* continue_tex=NULL;

//main menu texture
void mainmenu_load()
{
	surface=IMG_Load("res/frontpage_data/gv.jpg");
	if(!surface)
	{
		printf("gameover Error\n");
	    quit();
		return;
	}
	gameover_tex=SDL_CreateTextureFromSurface(rend,surface);
	SDL_FreeSurface(surface);
	surface=NULL;
    background_main_menu.w=1800;
    background_main_menu.h=980;
    background_main_menu.x=0;
    background_main_menu.y=0;
    surface=IMG_Load("res/frontpage_data/mainmenu_background.jpg");
	if (!surface)
    {
 		printf("Mainmenu Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    mainback_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL; 
   
    surface=IMG_Load("res/frontpage_data/pause_back.jpg");
	if (!surface)
    {
 		printf("pause_back Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    pause_back_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL; 

    New_game.w=500;
    New_game.h=80;
    New_game.x=200;
    New_game.y=350;
    surface=IMG_Load("res/frontpage_data/new game_2.jpg");
	if (!surface)
    {
 		printf("Mainmenu newgame icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    New_game_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	surface=IMG_Load("res/frontpage_data/continue2.jpg");
	if (!surface)
    {
 		printf("Mainmenu continue icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    continue_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	

    
    help.w=500;
    help.h=80;
    help.x=720;
    help.y=430;
    surface=IMG_Load("res/frontpage_data/help2.jpg");
	if (!surface)
    {
 		printf("Mainmenu help icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    help_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;


	
    high_score.w=500;
    high_score.h=80;
    high_score.x=720;
    high_score.y=350;
    surface=IMG_Load("res/frontpage_data/high_score2.jpg");
	if (!surface)
    {
 		printf("Mainmenu highscore icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    high_score_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

   
    exi.w=500;
    exi.h=80;
    exi.x=480;
    exi.y=520;
    surface=IMG_Load("res/frontpage_data/exit_2.jpg");
	if (!surface)
    {
 		printf("Mainmenu exit icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    exit_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;


	options.w=500;
    options.h=80;
    options.x=200;
    options.y=430;
    surface=IMG_Load("res/frontpage_data/options2.jpg");
	if (!surface)
    {
 		printf("Mainmenu options icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    options_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;


	exit_back.w=1800;
    exit_back.h=980;
    exit_back.x=0;
    exit_back.y=0;
    surface=IMG_Load("res/frontpage_data/exit_back3.jpg");
	if (!surface)
    {
 		printf("Mainmenu exit_back icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    exit_back_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	r_u_sure.w=600;
    r_u_sure.h=150;
    r_u_sure.x=520;
    r_u_sure.y=420;
    surface=IMG_Load("res/frontpage_data/r_usure.jpg");
	if (!surface)
    {
 		printf("Mainmenu r_u_sure icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    r_u_sure_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	yes.w=230;
    yes.h=100;
    yes.x=470;
    yes.y=620;
    surface=IMG_Load("res/frontpage_data/yes.jpg");
	if (!surface)
    {
 		printf("Mainmenu yes icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    yes_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	no.w=230;
    no.h=100;
    no.x=970;
    no.y=620;
    surface=IMG_Load("res/frontpage_data/no.jpg");
	if (!surface)
    {
 		printf("Mainmenu no icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    no_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;
	
	surface=IMG_Load("res/frontpage_data/no2.jpg");
	if (!surface)
    {
 		printf("Mainmenu no2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    no_tex2=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	surface=IMG_Load("res/frontpage_data/yes2.jpg");
	if (!surface)
    {
 		printf("Mainmenu yes2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    yes_tex2=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

    options_back.w=1800;
    options_back.h=980;
    options_back.x=0;
    options_back.y=0;
    surface=IMG_Load("res/frontpage_data/front_back5.jpg");
	if (!surface)
    {
 		printf("Options Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    options_back_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL; 

	surface=IMG_Load("res/frontpage_data/front_back2.jpg");
	if (!surface)
    {
 		printf("Options Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    help_back_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	sound_font.w=500;
    sound_font.h=80;
    sound_font.x=0;
    sound_font.y=100;
    surface=IMG_Load("res/frontpage_data/sound_font.jpg");
	if (!surface)
    {
 		printf("sound font icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    sound_font_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	sound_on.w=200;
    sound_on.h=80;
    sound_on.x=500;
    sound_on.y=100;
    surface=IMG_Load("res/frontpage_data/sound_on.jpg");
	if (!surface)
    {
 		printf("sound on icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    sound_on_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	sound_off.w=200;
    sound_off.h=80;
    sound_off.x=720;
    sound_off.y=100;
    surface=IMG_Load("res/frontpage_data/sound_off.jpg");
	if (!surface)
    {
 		printf("sound off icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    sound_off_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	sound_on2.w=170;
    sound_on2.h=60;
    sound_on2.x=500;
    sound_on2.y=105;
    surface=IMG_Load("res/frontpage_data/sound_on2.jpg");
	if (!surface)
    {
 		printf("sound on2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    sound_on2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	sound_off2.w=170;
    sound_off2.h=60;
    sound_off2.x=720;
    sound_off2.y=105;
    surface=IMG_Load("res/frontpage_data/sound_off2.jpg");
	if (!surface)
    {
 		printf("sound off2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    sound_off2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	back.w=500;
    back.h=80;
    back.x=1300;
    back.y=900;
    surface=IMG_Load("res/frontpage_data/back.jpg");
	if (!surface)
    {
 		printf("sound font icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    back_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

    surface=IMG_Load("res/frontpage_data/back_2.jpg");
	if (!surface)
    {
 		printf("back icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    back2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;


	game_sound.w=500;
    game_sound.h=80;
    game_sound.x=0;
    game_sound.y=200;
    surface=IMG_Load("res/frontpage_data/music_font.jpg");
	if (!surface)
    {
 		printf("game sound font icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    game_sound_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	gamesound_on.w=200;
    gamesound_on.h=80;
    gamesound_on.x=500;
    gamesound_on.y=200;
    surface=IMG_Load("res/frontpage_data/music_on.jpg");
	if (!surface)
    {
 		printf("gamesound on icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    gamesound_on_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	gamesound_off.w=200;
    gamesound_off.h=80;
    gamesound_off.x=720;
    gamesound_off.y=200;
    surface=IMG_Load("res/frontpage_data/music_off.jpg");
	if (!surface)
    {
 		printf("gamesound off icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    gamesound_off_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	gamesound_on2.w=170;
    gamesound_on2.h=60;
    gamesound_on2.x=500;
    gamesound_on2.y=205;
    surface=IMG_Load("res/frontpage_data/music_on2.jpg");
	if (!surface)
    {
 		printf("gamesound on2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    gamesound_on2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	gamesound_off2.w=170;
    gamesound_off2.h=60;
    gamesound_off2.x=720;
    gamesound_off2.y=205;
    surface=IMG_Load("res/frontpage_data/music_off2.jpg");
	if (!surface)
    {
 		printf("gamesound off2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    gamesound_off2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;
	high_up.w=1000;
    high_up.h=130;
    high_up.x=400;
    high_up.y=20;
    surface=IMG_Load("res/frontpage_data/highscore_font.jpg");
	if (!surface)
    {
 		printf("Mainmenu high up icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    high_up_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

    
    high_body.w=1000;
    high_body.h=850;
    high_body.x=500;
    high_body.y=150;
    surface=IMG_Load("res/frontpage_data/high_body.jpg");
	if (!surface)
    {
 		printf("Mainmenu high_body icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    high_body_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;


	
    next.w=500;
    next.h=80;
    next.x=1300;
    next.y=880;
    surface=IMG_Load("res/frontpage_data/next.jpg");
	if (!surface)
    {
 		printf("Mainmenu highscore next icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    next2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;
	
	surface=IMG_Load("res/frontpage_data/next2.jpg");
	if (!surface)
    {
 		printf("Mainmenu highscore next2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
	next_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	instruction.w=700;
    instruction.h=130;
    instruction.x=600;
    instruction.y=300;
    surface=IMG_Load("res/frontpage_data/instruction.jpg");
	if (!surface)
    {
 		printf("Mainmenu instruction icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    instruction_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;
	
	surface=IMG_Load("res/frontpage_data/instruction2.jpg");
	if (!surface)
    {
 		printf("Mainmenu instruction2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
	instruction2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	controls.w=700;
    controls.h=130;
    controls.x=250;
    controls.y=560;
    surface=IMG_Load("res/frontpage_data/controls.jpg");
	if (!surface)
    {
 		printf("Mainmenu controls icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    controls_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;
	
	surface=IMG_Load("res/frontpage_data/controls2.jpg");
	if (!surface)
    {
 		printf("Mainmenu controls2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
	controls2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	powerup_info.w=700;
    powerup_info.h=130;
    powerup_info.x=950;
    powerup_info.y=560;
    surface=IMG_Load("res/frontpage_data/powerup_font.jpg");
	if (!surface)
    {
 		printf("Mainmenu powerup_info icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    powerup_info_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;
	
	surface=IMG_Load("res/frontpage_data/powerup_font2.jpg");
	if (!surface)
    {
 		printf("Mainmenu powerup_info2 icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
	powerup_info2_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	control_body.w=1800;
    control_body.h=980;
    control_body.x=0;
    control_body.y=0;
    surface=IMG_Load("res/frontpage_data/control_body.jpg");
	if (!surface)
    {
 		printf("Mainmenu control_body icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    control_body_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	powerup_info_body.w=1800;
    powerup_info_body.h=980;
    powerup_info_body.x=0;
    powerup_info_body.y=0;
    surface=IMG_Load("res/frontpage_data/powerup_help_body.jpg");
	if (!surface)
    {
 		printf("Mainmenu powerup_info_body icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    powerup_info_body_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	instruction_body.w=1300;
    instruction_body.h=850;
    instruction_body.x=250;
    instruction_body.y=65;
    surface=IMG_Load("res/frontpage_data/instruction_body.jpg");
	if (!surface)
    {
 		printf("Mainmenu instruction_body icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    instruction_body_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	surface=IMG_Load("res/frontpage_data/instruction2 _body.jpg");
	if (!surface)
    {
 		printf("Mainmenu instruction2_body icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    instruction2_body_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	surface=IMG_Load("res/frontpage_data/instruction_back.jpg");
	if (!surface)
    {
 		printf("Mainmenu instruction_back icon Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
    instruction_back_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
	surface=NULL;

	FILE *fptr=fopen("res/Files/highscore.txt","r");
	for(int i=0; i<20; i++)
	{
		fscanf(fptr,"%d %s",&highscore_array[i].score,highscore_array[i].name);
	}
	fclose(fptr);
}

int mainmenu_render()
{
	if(sound==1 and music_run and (mainmenu))
	{
		Mix_PlayMusic(main_menu_music,-1);
		music_run=0;
	}
	while(mainmenu)
	{
		SDL_Event ev;
 		while(SDL_PollEvent(&ev))
		{
			if(ev.type==SDL_QUIT)
			{
 					close = 1;
					mainmenu=0;
			}
			else if(ev.type==SDL_KEYDOWN)
			{
				if(uivar==0)
				{
					if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT or ev.key.keysym.scancode==SDL_SCANCODE_UP) uivar=1;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT or ev.key.keysym.scancode==SDL_SCANCODE_DOWN) uivar=1;
					break;
				}
				else if(uivar==1)
				{
					if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT or ev.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT) uivar=2;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_DOWN) uivar=3;
					break;
				}
				else if(uivar==2)
				{
					if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT or ev.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT) uivar=1;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_DOWN) uivar=4;
					break;
				}
				else if(uivar==3)
				{
					if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT);
					else if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT) uivar=4;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_DOWN) uivar=5;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_UP) uivar=1;
					break;
				}
				else if(uivar==4)
				{
					if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT);
					else if(ev.key.keysym.scancode==SDL_SCANCODE_UP) uivar=2;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_DOWN) uivar=5;
					else if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT) uivar=3;
					break;
				}
				else if(uivar==5)
				{
					if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT or ev.key.keysym.scancode==SDL_SCANCODE_DOWN);
					else if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT);
					else if(ev.key.keysym.scancode==SDL_SCANCODE_UP) uivar=3;
					break;
				}

				
			}


			if(ev.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
			{
				if(game_sesh)
				game_sesh=0;
				
			}

			if(ev.key.keysym.scancode==SDL_SCANCODE_LEFT)
			{
				if(evar==2)
				evar=1;
				else if(evar==0) evar=1;
				
			}

			if(ev.key.keysym.scancode==SDL_SCANCODE_RIGHT)
			{
				if(evar==1)
				evar=2;
				else if(evar==0) evar=1;
				
			}
			
		}
			int mmmousex,mmmousey;
        	int mmbuttons=SDL_GetMouseState(&mmmousex,&mmmousey);	
	        SDL_RenderClear(rend);
			SDL_RenderCopy(rend,mainback_tex,NULL,&background_main_menu);
 			
 			

				if(uivar==1 || mmmousex>=New_game.x && mmmousex<=(New_game.x+New_game.w) && mmmousey>=New_game.y && mmmousey<=(New_game.y+New_game.h))
				{
					uivar=1;
					SDL_RenderCopy(rend,New_game_tex,NULL,&New_game);
					if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						uivar=0;
						reset_game(3);
					}
				}
				if(uivar==4 || mmmousex>=help.x && mmmousex<=(help.x+help.w) && mmmousey>=help.y && mmmousey<=(help.y+help.h))
				{
					uivar=4;
					SDL_RenderCopy(rend,help_tex,NULL,&help);
					if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN ||mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						Help=1;
						uivar=0;
						if(Help==1) help_render();		
					}
				}
				if(uivar==2 || mmmousex>=high_score.x && mmmousex<=(high_score.x+high_score.w) && mmmousey>=high_score.y && mmmousey<=(high_score.y+high_score.h))
				{
					uivar=2;
					SDL_RenderCopy(rend,high_score_tex,NULL,&high_score);
					if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN ||mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						uivar=0;
						Hscore=1;
						if(Hscore==1) highscore_render();
						
					}
				}
				if(uivar==3 || mmmousex>=options.x && mmmousex<=(options.x+options.w) && mmmousey>=options.y && mmmousey<=(options.y+options.h))
				{
					uivar=3;
					SDL_RenderCopy(rend,options_tex,NULL,&options);
					if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN ||mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						uivar=0;
						option=1;
						if(option==1) option_render();
					}
				}
				if(uivar==5 || mmmousex>=exi.x && mmmousex<=(exi.x+exi.w) && mmmousey>=exi.y && mmmousey<=(exi.y+exi.h))
				{
					uivar=5;
					SDL_RenderCopy(rend,exit_tex,NULL,&exi);
					if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN ||mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						uivar=0;
						game_sesh=1;
					}
				}
				if(game_sesh)
				{

					
					SDL_RenderCopy(rend,exit_back_tex,NULL,&exit_back);
					SDL_RenderCopy(rend,r_u_sure_tex,NULL,&r_u_sure);
					if(evar==1 || mmmousex>=yes.x && mmmousex<=(yes.x+yes.w) && mmmousey>=yes.y && mmmousey<=(yes.y+yes.h))
					{
						evar=1;
						SDL_RenderCopy(rend,yes_tex2,NULL,&yes);
						int mousex, mousey;
						int buttons = SDL_GetMouseState(&mousex, &mousey);
						if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
						{
							close=1;
							evar=0;
							return 0;
						}
					}
					else SDL_RenderCopy(rend,yes_tex,NULL,&yes);
					if(evar==2 || mmmousex>=no.x && mmmousex<=(no.x+no.w) && mmmousey>=no.y && mmmousey<=(no.y+no.h))
					{
						evar=2;
						SDL_RenderCopy(rend,no_tex2,NULL,&no);
						int mousex, mousey;
						int buttons = SDL_GetMouseState(&mousex, &mousey);
						if(ev.key.keysym.scancode==SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
						{
							evar=0;
							game_sesh=0;
							
						}
					}
					else SDL_RenderCopy(rend,no_tex,NULL,&no);
				}

			
			SDL_RenderPresent(rend);
			SDL_Delay(1000/60);
		
	}	
	return 1;

}

void option_render()
{
	while(option)
	{
		SDL_RenderClear(rend);
		SDL_Event oevent;
		while(SDL_PollEvent(&oevent))
		{
			if(oevent.type==SDL_QUIT)
			{
				option=0;
				close=1;
			}
			else if(oevent.type==SDL_KEYDOWN)
			{
				if(ovar==0)
				{
					if(oevent.key.keysym.scancode==SDL_SCANCODE_LEFT or oevent.key.keysym.scancode==SDL_SCANCODE_UP) ovar=1;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_RIGHT or oevent.key.keysym.scancode==SDL_SCANCODE_DOWN) ovar=1;
					break;
				}
				else if(ovar==1)
				{
					if(oevent.key.keysym.scancode==SDL_SCANCODE_LEFT or oevent.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_RIGHT) ovar=2;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_DOWN) ovar=3;
					break;
				}
				else if(ovar==2)
				{
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RIGHT or oevent.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_LEFT) ovar=1;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_DOWN) ovar=4;
					break;
				}
				if(ovar==3)
				{
					if(oevent.key.keysym.scancode==SDL_SCANCODE_LEFT);
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_RIGHT) ovar=4;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_DOWN) ovar=5;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_UP) ovar=1;
					break;
				}
				if(ovar==4)
				{
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RIGHT);
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_UP) ovar=2;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_DOWN) ovar=5;
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_LEFT) ovar=3;
					break;
				}
				if(ovar==5)
				{
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RIGHT or oevent.key.keysym.scancode==SDL_SCANCODE_DOWN);
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_LEFT);
					else if(oevent.key.keysym.scancode==SDL_SCANCODE_UP) ovar=3;
					break;
				}
			}
		}
	   
			back.x=1300;
			back.y=900;
			back.w=500;
			back.h=80;
			SDL_RenderCopy(rend,options_back_tex,NULL,&options_back);
			SDL_RenderCopy(rend,sound_font_tex,NULL,&sound_font);
			SDL_RenderCopy(rend,game_sound_tex,NULL,&game_sound);
			if(sound==1)
			{
				SDL_RenderCopy(rend,sound_on_tex,NULL,&sound_on);
				SDL_RenderCopy(rend,sound_off2_tex,NULL,&sound_off2);
			}
			else if(sound==0 )
			{
				SDL_RenderCopy(rend,sound_off_tex,NULL,&sound_off);
				SDL_RenderCopy(rend,sound_on2_tex,NULL,&sound_on2);
			}

			if(gamesound==1)
			{
				SDL_RenderCopy(rend,gamesound_on_tex,NULL,&gamesound_on);
				SDL_RenderCopy(rend,gamesound_off2_tex,NULL,&gamesound_off2);
			}
			else if(gamesound==0)
			{
				SDL_RenderCopy(rend,gamesound_off_tex,NULL,&gamesound_off);
				SDL_RenderCopy(rend,gamesound_on2_tex,NULL,&gamesound_on2);
			}
			int mousesx, mousesy;
			int buttonss = SDL_GetMouseState(&mousesx, &mousesy);
			if(ovar==5 || mousesx>=back.x && mousesx<=(back.x+back.w) && mousesy>=back.y && mousesy<=(back.y+back.h))
			{
				ovar==5;
				SDL_RenderCopy(rend,back2_tex,NULL,&back);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);
				if(oevent.key.keysym.scancode==SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					ovar=0;
					option=0;
				}
			}
			else SDL_RenderCopy(rend,back_tex,NULL,&back);
				
				
				
				if(ovar==1 || mousesx>=sound_on2.x && mousesx<=(sound_on2.x+sound_on2.w) && mousesy>=sound_on2.y && mousesy<=(sound_on2.y+sound_on2.h))
				{
					ovar==1;
					if(sound==0)
					{
						sound_on2.w=200;
						sound_on2.h=80;
						sound_on2.y=100;
						
						SDL_RenderCopy(rend,sound_on2_tex,NULL,&sound_on2);
					}
					else if(sound==1)
					{
						SDL_RenderCopy(rend,sound_on_tex,NULL,&sound_on);
					}
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						sound=1;
						music_run=0;
						Mix_PlayMusic(main_menu_music,-1);
						
			
					}	
					sound_on2.w=170;
					sound_on2.h=60;
					sound_on2.y=110;
				}
				
				else if(ovar==2 || mousesx>=sound_off2.x && mousesx<=(sound_off2.x+sound_off2.w) && mousesy>=sound_off2.y && mousesy<=(sound_off2.y+sound_off2.h))
				{
					ovar==2;
					if(sound==1)
					{
						sound_off2.w=200;
						sound_off2.h=80;
						sound_off2.y=100;
						SDL_RenderCopy(rend,sound_off2_tex,NULL,&sound_off2);
					}
					else if(sound==0)
					{
						SDL_RenderCopy(rend,sound_off_tex,NULL,&sound_off);
					}
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
					{	
						
						sound=0;
						music_run=1;
						Mix_HaltMusic();
					}
					sound_off2.w=170;
					sound_off2.h=60;
					sound_off2.y=110;
				}
				

				if(ovar==3 || mousesx>=gamesound_on2.x && mousesx<=(gamesound_on2.x+gamesound_on2.w) && mousesy>=gamesound_on2.y && mousesy<=(gamesound_on2.y+gamesound_on2.h))
				{
					ovar==3;
					if(gamesound==0)
					{
						gamesound_on2.w=200;
						gamesound_on2.h=80;
						gamesound_on2.y=200;
						
						SDL_RenderCopy(rend,gamesound_on2_tex,NULL,&gamesound_on2);
					}
					else if(gamesound==1)
					{						
						SDL_RenderCopy(rend,gamesound_on_tex,NULL,&gamesound_on);
					}
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
					{					
						gamesound=1;	
					}	
					gamesound_on2.w=170;
					gamesound_on2.h=60;
					gamesound_on2.y=210;
				}
				
				else if(ovar==4 || mousesx>=gamesound_off2.x && mousesx<=(gamesound_off2.x+gamesound_off2.w) && mousesy>=gamesound_off2.y && mousesy<=(gamesound_off2.y+gamesound_off2.h))
				{
					ovar==4;
					if(gamesound==1)
					{
						gamesound_off2.w=200;
						gamesound_off2.h=80;
						gamesound_off2.y=200;							
						SDL_RenderCopy(rend,gamesound_off2_tex,NULL,&gamesound_off2);
					}
					else if(gamesound==0)
					{	
						SDL_RenderCopy(rend,gamesound_off_tex,NULL,&gamesound_off);
					}
					if(oevent.key.keysym.scancode==SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
					{
						gamesound=0;			
					}
					gamesound_off2.w=170;
					gamesound_off2.h=60;
					gamesound_off2.y=210;
				}
			SDL_RenderPresent(rend);
		
	}
}

void highscore_render()
{
	SDL_RenderClear(rend);
	
	while(Hscore)
	{
		back.x=0;
		// if(!next_button) 
		next.y=900,next.x=1300;
		back.y=900;
		back.w=500;
        back.h=80;
		next.w=500;
        next.h=80;
		int hmousex, hmousey;
		int hbuttons = SDL_GetMouseState(&hmousex, &hmousey);
		SDL_Event hevent;
		while(SDL_PollEvent(&hevent))
		{
			if(hevent.type==SDL_QUIT)
			{
				Hscore=0;
				close=1;
				break;
			}
			if(hevent.type==SDL_MOUSEBUTTONDOWN)
			{
				if(hmousex>=back.x && hmousex<=(back.x+back.w) && hmousey>=back.y && hmousey<=(back.y+back.h))
				{
					printf("%d\n",next_button);
					if(next_button==0) 
					{
						Hscore=0;
					}
					else next_button=0;
					break;		
				}
			}
			if(hevent.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
			{
				
					if(next_button==0) 
					{
						Hscore=0;
					}
					else next_button=0;
					break;		
				
			}
		}
		SDL_RenderClear(rend);
		
		SDL_RenderCopy(rend,exit_back_tex,NULL,&exit_back);
		SDL_RenderCopy(rend,high_up_tex,NULL,&high_up);
		SDL_RenderCopy(rend,high_body_tex,NULL,&high_body);
		if(hmousex>=back.x && hmousex<=(back.x+back.w) && hmousey>=back.y && hmousey<=(back.y+back.h))
		{
			SDL_RenderCopy(rend,back2_tex,NULL,&back);
		}
		else SDL_RenderCopy(rend,back_tex,NULL,&back);
		
		if(!next_button)
		{
			nvar=0;
			if(hevent.key.keysym.scancode==SDL_SCANCODE_RIGHT) nvar=1;
			SDL_Rect nameh ,scoreh,indx_rec;
			SDL_Texture* name_tex=NULL;
			SDL_Texture* score_tex=NULL;
			SDL_Texture* indx_tex=NULL;
			nameh.h=scoreh.h=indx_rec.h=30;
			indx_rec.x=high_body.x+140-48;
			nameh.x=high_body.x+140;
			scoreh.x=high_body.x+500;
			nameh.y=scoreh.y=indx_rec.y=high_body.y+220;
			for(int i=0; i<10; i++)
			{
				int len=strlen(highscore_array[i].name);
				nameh.w=(len)*24;
				scoreh.w=4*28;
				indx_rec.w=2*24;
				name_tex=DISPLAYING_SCORE(highscore_array[i].name,1,1);
				char scorearray[5],indx[4];
				indx[0]=(i+1)/10+'0';
				indx[1]=(i+1)%10+'0';
				indx[2]='.';
				indx[3]='\0';
				scorearray[0]=highscore_array[i].score/1000+'0';
				scorearray[1]=(highscore_array[i].score/100)%10+'0';
				scorearray[2]=(highscore_array[i].score/10)%10+'0';
				scorearray[3]=highscore_array[i].score%10+'0';
				scorearray[4]='\0';
				score_tex=DISPLAYING_SCORE(scorearray,1,0);
				indx_tex=DISPLAYING_SCORE(indx,1,0);
				SDL_RenderCopy(rend,indx_tex,NULL,&indx_rec);
				SDL_RenderCopy(rend,name_tex,NULL,&nameh);
				SDL_RenderCopy(rend,score_tex,NULL,&scoreh);
				nameh.y+=50;
				scoreh.y+=50;
				indx_rec.y+=50;
				if(nameh.y>=high_body.y+high_body.h)
				{
					nameh.y=scoreh.y=high_body.y+180;
				}
				SDL_DestroyTexture(name_tex);
				SDL_DestroyTexture(score_tex);
				SDL_DestroyTexture(indx_tex);
			}
			if(nvar==1 || hmousex>=next.x && hmousex<=(next.x+next.w) && hmousey>=next.y && hmousey<=(next.y+next.h) && next_button==0)
			{
				nvar=1;
				SDL_RenderCopy(rend,next2_tex,NULL,&next);
				if(hevent.key.keysym.scancode==SDL_SCANCODE_RIGHT || (hbuttons && SDL_BUTTON(SDL_BUTTON_LEFT)))
				{
					next_button=1;
					nvar=0;
					
				}
			}
			else SDL_RenderCopy(rend,next_tex,NULL,&next);
			SDL_RenderPresent(rend);
			//SDL_Delay(1000/60);
			
		}
		else if(next_button)
		{
			
			SDL_Rect nameh ,scoreh,indx_rec;
			SDL_Texture* name_tex=NULL;
			SDL_Texture* score_tex=NULL;
			SDL_Texture* indx_tex=NULL;
			nameh.h=scoreh.h=indx_rec.h=30;
			indx_rec.x=high_body.x+140-48;
			nameh.x=high_body.x+140;
			scoreh.x=high_body.x+500;
			nameh.y=scoreh.y=indx_rec.y=high_body.y+220;
			for(int i=10; i<20; i++)
			{
				// SDL_RenderCopy(rend,high_body_tex,NULL,&high_body); 
				int len=strlen(highscore_array[i].name);
				nameh.w=(len)*24;
				scoreh.w=4*28;
				indx_rec.w=2*24;
				name_tex=DISPLAYING_SCORE(highscore_array[i].name,1,1);
				char scorearray[5],indx[4];
				indx[0]=(i+1)/10+'0';
				indx[1]=(i+1)%10+'0';
				indx[2]='.';
				indx[3]='\0';
				scorearray[0]=highscore_array[i].score/1000+'0';
				scorearray[1]=(highscore_array[i].score/100)%10+'0';
				scorearray[2]=(highscore_array[i].score/10)%10+'0';
				scorearray[3]=highscore_array[i].score%10+'0';
				scorearray[4]='\0';
				score_tex=DISPLAYING_SCORE(scorearray,1,0);
				indx_tex=DISPLAYING_SCORE(indx,1,0);
				SDL_RenderCopy(rend,indx_tex,NULL,&indx_rec);
				SDL_RenderCopy(rend,name_tex,NULL,&nameh);
				SDL_RenderCopy(rend,score_tex,NULL,&scoreh);
				nameh.y+=50;
				scoreh.y+=50;
				indx_rec.y+=50;
				if(nameh.y>=high_body.y+high_body.h)
				{
					nameh.y=scoreh.y=high_body.y+180;
				}
				SDL_DestroyTexture(name_tex);
				SDL_DestroyTexture(score_tex);
				SDL_DestroyTexture(indx_tex);
			//SDL_Delay(1000/60);
			}
			SDL_RenderPresent(rend);
		}
	}
					
}

void help_render()
{
	while(Help)
	{
		back.x=1300;
		back.y=900;
		back.w=500;
		back.h=80;
		if(Instruction)
		{
			back.x=0;
		}
		int hmousex, hmousey;
		int hbuttons = SDL_GetMouseState(&hmousex, &hmousey);
		SDL_RenderClear(rend);
		SDL_Event heevent;
		while(SDL_PollEvent(&heevent))
		{
			if(heevent.type==SDL_QUIT)
			{
				Help=0;
				close=1;
				break;
			}
			else if(heevent.type==SDL_KEYDOWN)
			{
				if(hvar==0)
				{
					if(heevent.key.keysym.scancode==SDL_SCANCODE_LEFT or heevent.key.keysym.scancode==SDL_SCANCODE_UP) hvar=1;
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT or heevent.key.keysym.scancode==SDL_SCANCODE_DOWN) hvar=1;
					break;
				}
				else if(hvar==1)
				{
					if(heevent.key.keysym.scancode==SDL_SCANCODE_LEFT or heevent.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT);
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_DOWN) hvar=2;
					break;
				}
				else if(hvar==2)
				{
					if(heevent.key.keysym.scancode==SDL_SCANCODE_LEFT );
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_UP) hvar=1;
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT) hvar=3;
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_DOWN) hvar=4;
					break;
				}
				if(hvar==3)
				{
					if(heevent.key.keysym.scancode==SDL_SCANCODE_LEFT) hvar=2;
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT);
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_DOWN) hvar=4;
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_UP) hvar=1;
					break;
				}
				if(hvar==4)
				{
					if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT);
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_UP) hvar=3;
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_DOWN);
					else if(heevent.key.keysym.scancode==SDL_SCANCODE_LEFT);
					break;
				}	
			}
			
			if(heevent.type==SDL_MOUSEBUTTONDOWN)
			{
				if(hmousex>=back.x && hmousex<=(back.x+back.w) && hmousey>=back.y && hmousey<=(back.y+back.h))
				{
					if(!Controls and !Powerup_info and !Instruction)
					{
						 Help=0;
						 break;
					}	
					if(Instruction2)
					{
						Instruction2=0;
						break;
					}
					else if(Instruction)
					{
						Instruction=0;
						break;
					}
				}
			}
			if(heevent.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
			{
				if(Controls) Controls=0,covar=0;
				else if(Powerup_info) Powerup_info=0;
				else if(Instruction2)
				{
					Instruction2=0;
					
				}
				else if(Instruction)
				{
					Instruction=0;
				}
				break;
				
			}
			if(heevent.key.keysym.scancode==SDL_SCANCODE_RETURN)
			{
					if(!Controls and !Powerup_info and !Instruction and hvar==4)
					{
						 Help=hvar=0;
						 break;
					}	

					// if(Instruction2)
					// {
					// 	Instruction2=0;
					// 	break;
					// }
					// else if(Instruction)
					// {
					// 	Instruction=0;
					// 	break;
					// }
			}
			
		}
		
		SDL_RenderCopy(rend,help_back_tex,NULL,&options_back);
		
		
		if(hvar==4 or hmousex>=back.x && hmousex<=(back.x+back.w) && hmousey>=back.y && hmousey<=(back.y+back.h))
		{
					hvar=4;
					SDL_RenderCopy(rend,back2_tex,NULL,&back);
		}
		else SDL_RenderCopy(rend,back_tex,NULL,&back);
		if(hvar==1 or hmousex>=instruction.x && hmousex<=(instruction.x+instruction.w) && hmousey>=instruction.y && hmousey<=(instruction.y+instruction.h))
		{
					hvar=1;
					SDL_RenderCopy(rend,instruction2_tex,NULL,&instruction);
					if(hbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) or heevent.key.keysym.scancode==SDL_SCANCODE_RETURN)
					{
						 Instruction=1;	
						//  hvar=0;
					}	
		}
		else SDL_RenderCopy(rend,instruction_tex,NULL,&instruction);

		if(hvar==2 or hmousex>=controls.x && hmousex<=(controls.x+controls.w) && hmousey>=controls.y && hmousey<=(controls.y+controls.h))
		{
					hvar=2;
					SDL_RenderCopy(rend,controls2_tex,NULL,&controls);
					if(hbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) or heevent.key.keysym.scancode==SDL_SCANCODE_RETURN)
					{
						 Controls=1;
						//  hvar=0;
					}	
		}
		else SDL_RenderCopy(rend,controls_tex,NULL,&controls);

		if(hvar==3 or hmousex>=powerup_info.x && hmousex<=(powerup_info.x+powerup_info.w) && hmousey>=powerup_info.y && hmousey<=(powerup_info.y+powerup_info.h))
		{
					hvar=3;
					SDL_RenderCopy(rend,powerup_info2_tex,NULL,&powerup_info);
					if(hbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) or heevent.key.keysym.scancode==SDL_SCANCODE_RETURN)
					{
						 Powerup_info=1;
						//  hvar=0;
					}	
		}
		else SDL_RenderCopy(rend,powerup_info_tex,NULL,&powerup_info);
		if(Controls)
		{
			covar=1;
			int hcmousex, hcmousey;
		    int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend,control_body_tex,NULL,&control_body);
            back.x=1300;
		    back.y=900;
			
		    if( hcmousex>=back.x && hcmousex<=(back.x+back.w) && hcmousey>=back.y && hcmousey<=(back.y+back.h))
			{
				
				SDL_RenderCopy(rend,back2_tex,NULL,&back);
				if(hcbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) )
				{
					Controls=0;	
					covar=0;
				}	
			}
			else SDL_RenderCopy(rend,back_tex,NULL,&back);

		}

		if(Powerup_info)
		{
			int hcmousex, hcmousey;
		    int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend,powerup_info_body_tex,NULL,&powerup_info_body);
            back.x=1300;
		    back.y=900;
		    if(hcmousex>=back.x && hcmousex<=(back.x+back.w) && hcmousey>=back.y && hcmousey<=(back.y+back.h))
			{
				SDL_RenderCopy(rend,back2_tex,NULL,&back);
				if(hcbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) or heevent.key.keysym.scancode==SDL_SCANCODE_RETURN)
				{
					Powerup_info=0;
					
				}	
			}
			else SDL_RenderCopy(rend,back_tex,NULL,&back);

		}

		if(Instruction)
		{
			ivar=0;
			if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT) ivar=1;
			int hcmousex, hcmousey;
		    int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend,instruction_back_tex,NULL,&exit_back);
			SDL_RenderCopy(rend,instruction_body_tex,NULL,&instruction_body);
            back.x=0;
		    back.y=900;
			back.w=500;
            back.h=80;
		    if(hcmousex>=back.x && hcmousex<=(back.x+back.w) && hcmousey>=back.y && hcmousey<=(back.y+back.h))
			{
				SDL_RenderCopy(rend,back2_tex,NULL,&back);
				// if(hcbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) )
				// {
				// 	Instruction=0;
					
				// }	
			}
			else SDL_RenderCopy(rend,back_tex,NULL,&back);

			next.x=1300;
		    next.y=900;
			next.w=500;
            next.h=80;
		    if(ivar==1 || hcmousex>=next.x && hcmousex<=(next.x+next.w) && hcmousey>=next.y && hcmousey<=(next.y+next.h))
			{
				ivar=1;
				SDL_RenderCopy(rend,next2_tex,NULL,&next);
				if(heevent.key.keysym.scancode==SDL_SCANCODE_RIGHT || (hcbuttons && SDL_BUTTON(SDL_BUTTON_LEFT)))
				{
					Instruction2=1;	
					ivar=0;
				}	
			}
			else SDL_RenderCopy(rend,next_tex,NULL,&next);
             
		}
        if(Instruction2)
		{
			int hcmousex, hcmousey;
		    int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend,instruction_back_tex,NULL,&exit_back);
			SDL_RenderCopy(rend,instruction2_body_tex,NULL,&instruction_body);
            back.x=0;
		    back.y=900;
			back.w=500;
            back.h=80;
		    if(hcmousex>=back.x && hcmousex<=(back.x+back.w) && hcmousey>=back.y && hcmousey<=(back.y+back.h))
			{
				SDL_RenderCopy(rend,back2_tex,NULL,&back);
				// if(hcbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				// {
				// 	Instruction2=0;
					
				// }	
			}
			else SDL_RenderCopy(rend,back_tex,NULL,&back);
             
		}
		SDL_RenderPresent(rend);
		SDL_Delay(1000/60);
	}

}

void pause_menu_renderer()
{
	if(sound==1 and music_run and pause)
	{
		Mix_PlayMusic(main_menu_music,-1);
		music_run=0;
	}
	while(pause)
	{
		SDL_Event evp;
 		while(SDL_PollEvent(&evp))
		{
			if(evp.type==SDL_QUIT)
			{
 					close = 1;
					pause=1-pause;
			}
			else if(evp.type==SDL_KEYDOWN)
			{
				if(evp.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
				{
					pause=1-pause;
					break;
				}
				if(pvar==0)
				{
					if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT or evp.key.keysym.scancode==SDL_SCANCODE_UP) pvar=1;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT or evp.key.keysym.scancode==SDL_SCANCODE_DOWN) pvar=1;
					break;
				}
				else if(pvar==1)
				{
					if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT or evp.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT) pvar=2;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_DOWN) pvar=3;
					break;
				}
				else if(pvar==2)
				{
					if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT or evp.key.keysym.scancode==SDL_SCANCODE_UP);
					else if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT) pvar=1;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_DOWN) pvar=4;
					break;
				}
				if(pvar==3)
				{
					if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT);
					else if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT) pvar=4;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_DOWN) pvar=5;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_UP) pvar=1;
					break;
				}
				if(pvar==4)
				{
					if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT);
					else if(evp.key.keysym.scancode==SDL_SCANCODE_UP) pvar=2;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_DOWN) pvar=5;
					else if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT) pvar=3;
					break;
				}
				if(pvar==5)
				{
					if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT or evp.key.keysym.scancode==SDL_SCANCODE_DOWN);
					else if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT);
					else if(evp.key.keysym.scancode==SDL_SCANCODE_UP) pvar=3;
					break;
				}
			}
			if(evp.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
			{
				if(game_sesh)
				game_sesh=0;
				
			}

			if(evp.key.keysym.scancode==SDL_SCANCODE_LEFT)
			{
				if(evar==2)
				evar=1;
				else if(evar==0) evar=1;
				
			}

			if(evp.key.keysym.scancode==SDL_SCANCODE_RIGHT)
			{
				if(evar==1)
				evar=2;
				else if(evar==0) evar=1;
				
			}
		}
		int mmmousex,mmmousey;
		int mmbuttons=SDL_GetMouseState(&mmmousex,&mmmousey);	
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend,pause_back_tex,NULL,&background_main_menu);
		if(pvar==1 || mmmousex>=New_game.x && mmmousex<=(New_game.x+New_game.w) && mmmousey>=New_game.y && mmmousey<=(New_game.y+New_game.h))
		{ 
			pvar=1;
			SDL_RenderCopy(rend,continue_tex,NULL,&New_game); //here continue is on previous newgame's location
			if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar=0;
				pause=1-pause;
				Mix_HaltMusic();
				music_run=1;
			}
		}
		if(pvar==2 || mmmousex>=high_score.x && mmmousex<=(high_score.x+high_score.w) && mmmousey>=high_score.y && mmmousey<=(high_score.y+high_score.h))
		{
			pvar=2;
			SDL_RenderCopy(rend,New_game_tex,NULL,&high_score); //here new game's loaction is on previous highscore's location
			if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar=0;
				pause=1-pause;
				reset_game(3);
			}
		}
		if(pvar==4 || mmmousex>=help.x && mmmousex<=(help.x+help.w) && mmmousey>=help.y && mmmousey<=(help.y+help.h))
		{
			pvar=4;
			SDL_RenderCopy(rend,help_tex,NULL,&help);
			if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar=0;
				Help=1;
				if(Help==1) help_render();
				
			}
		}
		if(pvar==3 || mmmousex>=options.x && mmmousex<=(options.x+options.w) && mmmousey>=options.y && mmmousey<=(options.y+options.h))
		{
			pvar=3;
			SDL_RenderCopy(rend,options_tex,NULL,&options);
			if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar=0;
				option=1;
				if(option==1) option_render();
			}
		}
		if(pvar==5 || mmmousex>=exi.x && mmmousex<=(exi.x+exi.w) && mmmousey>=exi.y && mmmousey<=(exi.y+exi.h))
		{
			pvar=5;
			SDL_RenderCopy(rend,exit_tex,NULL,&exi);
			if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar=0;
				game_sesh=1;
			}
		}
		if(game_sesh)
		{
			SDL_RenderCopy(rend,exit_back_tex,NULL,&exit_back);
			SDL_RenderCopy(rend,r_u_sure_tex,NULL,&r_u_sure);
			SDL_RenderCopy(rend,no_tex,NULL,&no);
			if(evar==1 || mmmousex>=yes.x && mmmousex<=(yes.x+yes.w) && mmmousey>=yes.y && mmmousey<=(yes.y+yes.h))
			{
				evar=1;
				SDL_RenderCopy(rend,yes_tex2,NULL,&yes);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);
				if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN ||buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					evar=0;
					close=1;
					return ;
				}
			}
			else SDL_RenderCopy(rend,yes_tex,NULL,&yes);
			if(evar==2 || mmmousex>=no.x && mmmousex<=(no.x+no.w) && mmmousey>=no.y && mmmousey<=(no.y+no.h))
			{
				evar=2;
				SDL_RenderCopy(rend,no_tex2,NULL,&no);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);
				if(evp.key.keysym.scancode==SDL_SCANCODE_RETURN ||buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					evar=0;
					game_sesh=0;
				}
			}
			else SDL_RenderCopy(rend,no_tex,NULL,&no);
		}
					

		SDL_RenderPresent(rend);
	}
		
}

void mainmenu_level_renderer()
{
	if(mainmenu==1)
	{
		
		if(!mainmenu_render()) close=1;
		//printf("%d %d\n",sound,music_run);
		
		level2=1;
		level3=1;
		level1=1;
		//uivar=0;
		
	}
	else if(gameover==0 and pause)
	{
		pause_menu_renderer();
	}
	else if(gameover == 0 and life)
	{

		game_physics();
		SDL_RenderClear(rend);
		if(level==1)
		{
			if(level1==1)
			{
				if(gamesound==1)
				Mix_PlayChannel(-1,level_up,0);
				SDL_RenderCopy(rend,level1_back,NULL,&level_background);
				SDL_RenderPresent(rend);
				SDL_Delay(1000);
				SDL_RenderClear(rend);
				level1=0;
			}
			else
			{
				//if(ball.y)
				SDL_RenderCopy(rend,background1,NULL,&background);
				bar_anim=bar_and_bricks_render(bar_anim,level);
				//life
				//scoring
				score_and_life_print(score,life);
				// SDL_RenderCopy(rend, tex, NULL, &bar);
				// SDL_RenderCopy(rend, gbartex[1].tex, NULL, &bar);
				int fx,fy;
				int buttons = SDL_GetGlobalMouseState(&fx, &fy);
				
				firerender(fbar | mfbar);
				powerup_renderer(power_up.hoise,power_up.type);
				SDL_RenderCopy(rend, tex2, NULL, &ball);
				
				SDL_RenderPresent(rend);
			}
		}
		else if(level==2)
		{
			if(level2==1)
			{
				if(gamesound==1 && level==2)
				Mix_PlayChannel(-1,level_up,0);
				SDL_RenderCopy(rend,level2_back,NULL,&level_background);
				SDL_RenderPresent(rend);
				SDL_Delay(1000);
				SDL_RenderClear(rend);
				level2=0;
			}
			else
			{
				SDL_RenderCopy(rend,background2,NULL,&background);
				bar_anim=bar_and_bricks_render(bar_anim,level);
				//life
				//scoring
				score_and_life_print(score,life);
				// SDL_RenderCopy(rend, tex, NULL, &bar);
				// SDL_RenderCopy(rend, gbartex[1].tex, NULL, &bar);
				int fx,fy;
				int buttons = SDL_GetGlobalMouseState(&fx, &fy);
				
				firerender(fbar | mfbar);
				powerup_renderer(power_up.hoise,power_up.type);
				SDL_RenderCopy(rend, tex2, NULL, &ball);
				
				SDL_RenderPresent(rend);
			}
		
		}
		else if(level==3)
		{
			if(level3==1)
			{
				if(gamesound==1 && level==3)
				Mix_PlayChannel(-1,level_up,0);
				SDL_RenderCopy(rend,level3_back,NULL,&level_background);
				SDL_RenderPresent(rend);
				SDL_Delay(1000);
				SDL_RenderClear(rend);
				level3=0;
			}
			else
			{
				SDL_RenderCopy(rend,background3,NULL,&background);
				bar_anim=bar_and_bricks_render(bar_anim,level);
				//life
				//scoring
				score_and_life_print(score,life);
				// SDL_RenderCopy(rend, tex, NULL, &bar);
				// SDL_RenderCopy(rend, gbartex[1].tex, NULL, &bar);
				int fx,fy;
				int buttons = SDL_GetGlobalMouseState(&fx, &fy);
				
				firerender(fbar | mfbar);
				powerup_renderer(power_up.hoise,power_up.type);
				SDL_RenderCopy(rend, tex2, NULL, &ball);
				
				SDL_RenderPresent(rend);
			}
		}
		SDL_Delay(1000/80);

 		}
		else if(gameover==1 or life==0  or level>3)
		{
			
 			BALL_SPEED=20,theta=30;
	        dx=BALL_SPEED*sin(theta*acos(-1)/180),dy=BALL_SPEED*cos(theta*acos(-1)/180);
 			SDL_RenderClear(rend);
 			
 			SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
        	SDL_RenderDrawPoint(rend, 10, 20);
        	SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0xFF);

			name_write();
	 		SDL_RenderPresent(rend);
			reset_game(0);
 		}
}

void quit()
{ 
	
	SDL_Delay(1000/60);
 	SDL_DestroyRenderer(rend);
 	SDL_DestroyWindow(win);
	SDL_DestroyTexture(back_tex);
	SDL_DestroyTexture(New_game_tex);
	SDL_DestroyTexture(help_tex);
	SDL_DestroyTexture(high_score_tex);
	SDL_DestroyTexture(exit_tex);
	SDL_DestroyTexture(r_u_sure_tex);
	SDL_DestroyTexture(yes_tex);
	SDL_DestroyTexture(no_tex);
	SDL_DestroyTexture(exit_back_tex);
	SDL_DestroyTexture(yes_tex2);
	SDL_DestroyTexture(no_tex2);
	SDL_DestroyTexture(options_tex);
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(tex2);
	SDL_DestroyTexture(liferend);
	SDL_DestroyTexture(background1);
	SDL_DestroyTexture(gameover_tex);

	gameover_tex=NULL;
	back_tex=NULL;
	New_game_tex=NULL;
	help_tex=NULL;
	high_score_tex=NULL;
	exit_tex=NULL;
	r_u_sure_tex=NULL;
	yes_tex=NULL;
	no_tex=NULL;
	exit_back_tex=NULL;
	yes_tex2=NULL;
	no_tex2=NULL;
	options_tex=NULL;
	tex=NULL;
	tex2=NULL;
	liferend=NULL;
	background1=NULL;
	
    Mix_FreeMusic(main_menu_music);
	for(int i=0; i<4; i++) SDL_DestroyTexture(gbartex[i].tex);
	for(int i=0; i<4; i++) SDL_DestroyTexture(mbartex[i].tex);
	for(int i=0; i<4; i++) SDL_DestroyTexture(fbartex[i].tex);
	for(int i=0; i<4; i++) SDL_DestroyTexture(mfbartex[i].tex);
	font_closing();
	level_destroy();
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}






