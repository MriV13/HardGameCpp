#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>


volatile long speed = 0;
void increment_speed()
{
    speed++;
}
END_OF_FUNCTION( increment_speed );
LOCK_VARIABLE( speed );
LOCK_FUNCTION( increment_speed );
int lose_x=0;
int lose_y=0;
int lvl=0;
int c=0;
int gracz1_x=365;
int gracz1_y=39;
int superx = 365;
int supery = 39;
int dead=0;
int czas=0;
int win=0;
int l=0;
int zapis=0;
int openx=0;
int st=0;
int prog=0;
int z=0;
int aa=0;
int bb=0;
int cc=0;
int score=0;
int score_d=0;


bool mozna_w_lewo(int x, int y, BITMAP* bufor)
{
if(getpixel(bufor,x-1,y+1)==makecol(0,0,0))return false;
if(getpixel(bufor,x-1,y+5 )==makecol(0,0,0))return false;
if(getpixel(bufor,x-1,y+9)==makecol(0,0,0))return false;
else return true;
}

bool mozna_w_prawo(int x, int y, BITMAP* bufor)
{
if(getpixel(bufor,x+10,y+1)==makecol(0,0,0))return false;
if(getpixel(bufor,x+10,y+5 )==makecol(0,0,0))return false;
if(getpixel(bufor,x+10,y+9)==makecol(0,0,0))return false;
else return true;
}

bool mozna_w_gore(int x, int y, BITMAP* bufor)
{
if(getpixel(bufor,x+1,y-1)==makecol(0,0,0))return false;
if(getpixel(bufor,x+5 ,y-1)==makecol(0,0,0))return false;
if(getpixel(bufor,x+9,y-1)==makecol(0,0,0))return false;
else return true;
}

bool mozna_w_dol(int x, int y, BITMAP* bufor)
{
if(getpixel(bufor,x+1,y+10)==makecol(0,0,0))return false;
if(getpixel(bufor,x+5 ,y+10)==makecol(0,0,0))return false;
if(getpixel(bufor,x+9,y+10)==makecol(0,0,0))return false;
else return true;
}



bool przegrana(BITMAP*bufor,int x, int y)
{
if(getpixel(bufor,x+3,y+1)==makecol(1,0,0))return true;
if(getpixel(bufor,x+3,y+5 )==makecol(1,0,0))return true;
if(getpixel(bufor,x+3,y+9)==makecol(1,0,0))return true;

	else return false;
	
if(getpixel(bufor,x-7,y-1)==makecol(1,0,0))return true;
if(getpixel(bufor,x-7,y-5 )==makecol(1,0,0))return true;
if(getpixel(bufor,x-7,y-9)==makecol(1,0,0))return true;

	else return false;
	
if(getpixel(bufor,x+1,y-3)==makecol(1,0,0))return true;
if(getpixel(bufor,x+5 ,y-3)==makecol(1,0,0))return true;
if(getpixel(bufor,x+9,y-3)==makecol(1,0,0))return true;

	else return false;
	
if(getpixel(bufor,x-1,y+7)==makecol(1,0,0))return true;
if(getpixel(bufor,x-5,y+7)==makecol(1,0,0))return true;
if(getpixel(bufor,x-9,y+7)==makecol(1,0,0))return true;

	else return false;

}

void menu()
{
     DATAFILE*data=NULL;
 data=load_datafile("Data/Data.dat");
int next=1;
int plus=0;
int cc=0;
	BITMAP*bufor;
    BITMAP * startmenu;  
    BITMAP * startmenusell; 
    BITMAP * infomenu; 
    BITMAP * infomenusell; 
    BITMAP * quitmenu; 
    BITMAP * quitmenusell; 
    BITMAP * dalej;    
    BITMAP * gracz1;
    BITMAP * lose ;
    BITMAP * save;
    BITMAP * klucz;
    BITMAP * blok;
      
    gracz1=(BITMAP*) data[0].dat;
    lose=(BITMAP*) data[1].dat;
    save=(BITMAP*) data[2].dat;
    klucz=(BITMAP*) data[3].dat;
    blok=(BITMAP*) data[4].dat;
	startmenu=    (BITMAP*) data[9].dat;
	startmenusell=(BITMAP*) data[10].dat;
	infomenu=     (BITMAP*) data[11].dat;
	infomenusell= (BITMAP*) data[12].dat;
	quitmenu=     (BITMAP*) data[13].dat;
	quitmenusell= (BITMAP*) data[14].dat;
	dalej=        (BITMAP*) data[15].dat;
	
	bufor = create_bitmap( 640, 480 );
	
 
 
    	while( !key[ KEY_ESC ] )
{
    if( key[ KEY_UP ]) plus--;
    
    if( key[ KEY_DOWN ]) plus++;
    
clear_to_color( bufor, makecol( 0, 150, 25 ) );

if(plus<0){plus=450;}
if(plus<150 && plus>0){next=1;}
 if(plus>150 && plus<300){next=2;}
 if(plus>300 && plus<450){next=3;}
 if(plus>450){plus=1;}
 
 masked_blit( startmenu, bufor, 0, 0, 245, 100, startmenu->w, startmenu->h );
 masked_blit( infomenu, bufor, 0, 0, 245, 170, startmenu->w, startmenu->h );
 masked_blit( quitmenu, bufor, 0, 0, 245, 240, startmenu->w, startmenu->h );
 textprintf_ex(bufor, font, 10,470, makecol(0, 0, 0), -1, "Version: 1.0_01");
  textprintf_ex(bufor, font,580,470, makecol(0, 0, 0), -1, "By MriV");
 
 if(next==1){ masked_blit( startmenusell, bufor, 0, 0, 245, 100, startmenusell->w, startmenusell->h );}
 if(next==2){masked_blit( infomenusell, bufor, 0, 0, 245, 170, startmenusell->w, startmenusell->h );}
 if(next==3){masked_blit( quitmenusell, bufor, 0, 0, 245, 240, startmenusell->w, startmenusell->h );}
 
 if(next==1 && key[ KEY_ENTER]){
            if(win==1 && c==1){win=0;c=0;}
            if(c==1)
            {
            cc=1;
            }
            if(c==0){return;}
            }
            
            
 if(next==2 && key[ KEY_ENTER]){l=1; textprintf_ex(bufor, font, 10,10, makecol(0, 0, 0), -1, "SOON..."); }
   
  if(l==1)
  {
      clear_to_color( bufor, makecol(150, 78, 25 ) ); 
textprintf_ex(bufor, font, 100,100, makecol(0, 0, 0), -1, "F1     : Back");
textprintf_ex(bufor, font, 100,110, makecol(0, 0, 0), -1, "Enter  : Sellect");
textprintf_ex(bufor, font, 100,120, makecol(0, 0, 0), -1, "ESC    : Quit");
textprintf_ex(bufor, font, 100,240, makecol(0, 0, 0), -1, "Player :");
masked_blit( gracz1, bufor, 0, 0, 165, 240, gracz1->w, gracz1->h );
textprintf_ex(bufor, font, 100,265, makecol(0, 0, 0), -1, "Save   :");
masked_blit( save, bufor, 0, 0, 165, 255,save->w, save->h );
textprintf_ex(bufor, font, 100,305, makecol(0, 0, 0), -1, "Dead   :");
masked_blit( lose, bufor, 0, 0, 165, 305, lose->w, lose->h );
textprintf_ex(bufor, font, 100,330, makecol(0, 0, 0), -1, "KEY    :");
masked_blit( klucz, bufor, 0, 0, 165, 330, klucz->w, klucz->h );
textprintf_ex(bufor, font, 100,355, makecol(0, 0, 0), -1, "Block  :");
masked_blit( blok, bufor, 0, 0, 165, 355, blok->w, blok->h );
textprintf_ex(bufor, font, 50,449, makecol(0, 0, 0), -1, "E-mail: stefanwiselka@gmail.com");
textprintf_ex(bufor, font, 50,460, makecol(0, 0, 0), -1, "Youtube: https://www.youtube.com/channel/UCM4S-mySz72H9vidIwdvteQ");
if( key[ KEY_F1] ){l=0;}     
  }
  
 if(next==3 && key[ KEY_ENTER]){}
 
  if(cc==1 && win ==0){masked_blit(dalej, bufor, 0, 0, 170, 90, dalej->w, dalej->h );
  if(key[KEY_Y]){return;}
  if(key[KEY_N]){gracz1_x=365;openx=0;lvl=0;st=0;zapis=0;gracz1_y=39;czas=0;dead=0;return;}

}
blit( bufor, screen, 0, 0, 0, 0, 640, 480 );
}

}
int main()
{
	allegro_init();
	install_keyboard();
	set_color_depth( 32 );
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0 );   
    install_timer();
    install_int_ex( increment_speed, BPS_TO_TIMER(100 ) );
    
    DATAFILE*data=NULL;
    data=load_datafile("Data/Data.dat"); 
    
 
    menu();
    
    BITMAP * bufor = NULL;
    BITMAP * lose_bufor= NULL;
    
    BITMAP * super;
    BITMAP * gracz1;
    BITMAP * lose ;
    BITMAP * save;
    BITMAP * klucz;
    BITMAP * blok;
    BITMAP * a123;
	
	BITMAP * plansza1;
	BITMAP * plansza2;
	
	BITMAP * winb;
    
   lose_bufor = create_bitmap( 640, 480 );
   bufor = create_bitmap( 640, 480 );
       if( !bufor )
    {
    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
    allegro_message( "Nie mogê utworzyæ bufora !" );
    allegro_exit();
    return 0;
    }
    
    super=(BITMAP*) data[0].dat;
gracz1=(BITMAP*) data[0].dat;
lose=(BITMAP*) data[1].dat;
save=(BITMAP*) data[2].dat;
klucz=(BITMAP*) data[3].dat;
blok=(BITMAP*) data[4].dat;
a123=(BITMAP*) data[5].dat;
plansza1=(BITMAP*) data[6].dat;
plansza2=(BITMAP*) data[7].dat;

winb=(BITMAP*) data[8].dat;

int i_100=0;
int j_100=100;
int i_50=0;
int j_50=50;







        while( !key[ KEY_ESC ] ){
       while( speed > 0 )
{
       
       if(!przegrana(lose_bufor,gracz1_x,gracz1_y))
		{
    if( key[ KEY_LEFT ] &&  mozna_w_lewo(gracz1_x,gracz1_y,bufor)) gracz1_x-=1;
    
    if( key[ KEY_RIGHT ] && mozna_w_prawo(gracz1_x,gracz1_y,bufor)) gracz1_x+=1;
    
    if( key[ KEY_UP ] && mozna_w_gore(gracz1_x,gracz1_y,bufor)) gracz1_y-=1;
    
    if( key[ KEY_DOWN ] && mozna_w_dol(gracz1_x,gracz1_y,bufor)) gracz1_y+=1;
    
      if( key[ KEY_A ]) superx--;
    
    if( key[ KEY_D ] ) superx++;
    
    if( key[ KEY_W ] ) supery--;
    
    if( key[ KEY_S ] ) supery++;
}
    //***********************************50*******50*   LEFT RIGHT
      if(j_50==50)i_50++;
      if(j_50==0)i_50--;
      if(i_50>50)j_50=0;
      if(i_50<0)j_50=50;  
 //***********************************100*******100*  LEFT RIGHT
 
      if(j_100==100)i_100++;
      if(j_100==0)i_100--;
      if(i_100>100)j_100=0;
      if(i_100<0)j_100=100;
      
      

      speed--;
      if(st==0)z++;
  
}


clear_to_color( bufor, makecol( 0, 0, 255 ) );



if(lvl==0){
    masked_blit( plansza1, bufor, 0, 0, 0, 0, plansza1->w, plansza1->h );
   //==============================================================================================LOSE

	masked_blit( lose, lose_bufor, 0, 0, lose_x+180+i_100*3+2, lose_y+14, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+613, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+602, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+591, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+580, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+569, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+558, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+547, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+536, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+525, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+514, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+503, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+492, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+481, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+470, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+459, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+448, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+437, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+426, lose_y+210, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+415, lose_y+210, lose->w, lose->h );
	
	masked_blit( lose, lose_bufor, 0, 0, lose_x+600, lose_y+268+i_100, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+588, lose_y+268+i_50*2, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+576, lose_y+268+i_100, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+564, lose_y+268+i_50*2, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+552, lose_y+268+i_100, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+540, lose_y+268+i_100, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+528, lose_y+268+i_100, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+516, lose_y+268+i_50*2, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+425, lose_y+280+i_50, lose->w, lose->h );
	
	masked_blit( lose, lose_bufor, 0, 0, lose_x+540+i_100/2, lose_y+464, lose->w, lose->h );
	masked_blit( lose, lose_bufor, 0, 0, lose_x+554, lose_y+392+i_50, lose->w, lose->h );
	
	masked_blit( lose, lose_bufor, 0, 0, lose_x+200+i_100, lose_y+400, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+100+i_100, lose_y+450, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+260-i_100, lose_y+420, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+150-i_100, lose_y+430, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+100+i_100, lose_y+300, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+300-i_100, lose_y+280, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+50+i_100, lose_y+320, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+320-i_100, lose_y+360, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+240, lose_y+280+i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+100, lose_y+450-i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+220, lose_y+300+i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+170, lose_y+430-i_100, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+20+i_100, lose_y+290+i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+50+i_100, lose_y+430-i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+130, lose_y+380-i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+240-i_100, lose_y+440-i_100, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+50+i_50/4, lose_y+290+i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+35+i_50/2, lose_y+430-i_50*2, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+100-i_50, lose_y+280+i_50*2, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+230-i_100*2, lose_y+440-i_50, lose->w, lose->h );
    
	//==============================================================================================Zapiski + przejscia
	masked_blit( save, bufor, 0, 0, 593, 235, save->w, save->h );
	masked_blit( save, bufor, 0, 0, 451, 306, save->w, save->h );
	masked_blit( save, bufor, 0, 0, 334, 384, save->w, save->h );
	masked_blit( save, bufor, 0, 0, -20, 280, save->w, save->h );
	if(gracz1_x>=593 && gracz1_x<=623 && gracz1_y>=235 && gracz1_y<=265){zapis=1;}
	if(gracz1_x>=451 && gracz1_x<=481 && gracz1_y>=306 && gracz1_y<=336){zapis=2;}
	if(gracz1_x>=334 && gracz1_x<=364 && gracz1_y>=384 && gracz1_y<=414){zapis=3;}
	if(gracz1_x>=-20 && gracz1_x<=10 && gracz1_y>=280 && gracz1_y<=310){zapis=4;}
	if(gracz1_x>=-18 && gracz1_x<=-1 && gracz1_y>=275 && gracz1_y<=315){lvl=1;gracz1_x=630;}
	if(gracz1_x>=-18 && gracz1_x<=-1 && gracz1_y>=23 && gracz1_y<=25){lvl =1;gracz1_x=630;}
	//==============================================================================================klucze
	if(gracz1_x>=455 && gracz1_x<=470 && gracz1_y>=311 && gracz1_y<=326){openx=1;}
	if (openx==0){masked_blit( klucz, bufor, 0, 0, 460, 316, klucz->w, klucz->h );}
	if (openx==0){masked_blit( blok, bufor, 0, 0, 613, 378, blok->w, blok->h );}
	
	
	masked_blit( gracz1, bufor, 0, 0, gracz1_x, gracz1_y, gracz1->w, gracz1->h );
//	masked_blit( super, bufor, 0, 0, superx, supery, super->w, super->h );
	}
    if(lvl==1){
                       
    masked_blit( plansza2, bufor, 0, 0, 0, 0, plansza2->w, plansza2->h );
    //==============================================================================================LOSE
    masked_blit( lose, lose_bufor, 0, 0, lose_x+489, lose_y+253+i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+499, lose_y+353-i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+509, lose_y+253+i_100, lose->w, lose->h ); masked_blit( lose, lose_bufor, 0, 0, lose_x+519, lose_y+353-i_100, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+529, lose_y+253+i_100, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+539, lose_y+353-i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+549, lose_y+253+i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+559, lose_y+353-i_100, lose->w, lose->h ); masked_blit( lose, lose_bufor, 0, 0, lose_x+569, lose_y+253+i_100, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+579, lose_y+353-i_100, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+589, lose_y+253+i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+599, lose_y+353-i_100, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+609, lose_y+253+i_100, lose->w, lose->h );
    
    masked_blit( lose, lose_bufor, 0, 0, lose_x+143, lose_y+252+i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+154, lose_y+302-i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+165, lose_y+252+i_50, lose->w, lose->h ); masked_blit( lose, lose_bufor, 0, 0, lose_x+176, lose_y+302-i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+187, lose_y+252+i_50, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+198, lose_y+302-i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+209, lose_y+252+i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+220, lose_y+302-i_50, lose->w, lose->h ); masked_blit( lose, lose_bufor, 0, 0, lose_x+231, lose_y+252+i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+242, lose_y+302-i_50, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+253, lose_y+252+i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+264, lose_y+302-i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+275, lose_y+252+i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+309, lose_y+252+i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+320, lose_y+302-i_50, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+331, lose_y+252+i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+342, lose_y+302-i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+353, lose_y+252+i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+364, lose_y+302-i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+375, lose_y+252+i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+386, lose_y+302-i_50, lose->w, lose->h );
    masked_blit( lose, lose_bufor, 0, 0, lose_x+397, lose_y+252+i_50, lose->w, lose->h );  masked_blit( lose, lose_bufor, 0, 0, lose_x+408, lose_y+302-i_50, lose->w, lose->h );masked_blit( lose, lose_bufor, 0, 0, lose_x+419, lose_y+252+i_50, lose->w, lose->h );
  

   
   masked_blit( lose, lose_bufor, 0, 0, lose_x+300+i_100/2, lose_y+17+i_50*2, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+320+i_100/2, lose_y+17+i_50*2, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+340+i_100/2, lose_y+17+i_50*2, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+360+i_100/2, lose_y+17+i_50*2, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+380+i_100/2, lose_y+17+i_50*2, lose->w, lose->h );
   
   masked_blit( lose, lose_bufor, 0, 0, lose_x+200+i_100, lose_y+199, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+200+i_100, lose_y+188, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+200+i_100, lose_y+177, lose->w, lose->h );  
   masked_blit( lose, lose_bufor, 0, 0, lose_x+343+i_100, lose_y+209, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+343+i_100, lose_y+198, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+343+i_100, lose_y+187, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+443-i_100, lose_y+176, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+443-i_100, lose_y+165, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+443-i_100, lose_y+154, lose->w, lose->h );
   
   masked_blit( lose, lose_bufor, 0, 0, lose_x+288, lose_y+201-i_50-i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+277, lose_y+49+i_50+i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+266, lose_y+151+i_50-i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+255, lose_y+49+i_50+i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+244, lose_y+101-i_50+i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+233, lose_y+49+i_50+i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+222, lose_y+101+i_50-i_100, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+311-i_50*2+i_100/4, lose_y+109+i_50/2-i_100/2, lose->w, lose->h );
   
   masked_blit( lose, lose_bufor, 0, 0, lose_x+141+i_50, lose_y+338+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+152+i_50, lose_y+338+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+163+i_50, lose_y+338+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+174+i_50, lose_y+338+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+185+i_50, lose_y+338+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+196+i_50, lose_y+338+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+207+i_50, lose_y+338+i_50, lose->w, lose->h );
   
   masked_blit( lose, lose_bufor, 0, 0, lose_x+191-i_50, lose_y+378+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+202-i_50, lose_y+378+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+213-i_50, lose_y+378+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+224-i_50, lose_y+378+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+235-i_50, lose_y+378+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+246-i_50, lose_y+378+i_50, lose->w, lose->h );
   masked_blit( lose, lose_bufor, 0, 0, lose_x+257-i_50, lose_y+378+i_50, lose->w, lose->h );
   //==============================================================================================Zapiski + przejscia
    masked_blit( save, bufor, 0, 0, 630, 279, save->w, save->h );
    masked_blit( save, bufor, 0, 0, 446, 246, save->w, save->h );
    masked_blit( save, bufor, 0, 0, 100, 288, save->w, save->h );
    masked_blit( save, bufor, 0, 0, 239, 440, save->w, save->h );
    masked_blit( save, bufor, 0, 0, 467, 17, save->w, save->h );
    
    if(gracz1_x>=630 && gracz1_x<649 && gracz1_y>=280 && gracz1_y<=310){zapis=5;}
    if(gracz1_x>=446 && gracz1_x<476 && gracz1_y>=246 && gracz1_y<=276){zapis=6;}
    if(gracz1_x>=99 && gracz1_x<129 && gracz1_y>=287 && gracz1_y<=317){zapis=7;}
    if(gracz1_x>=239 && gracz1_x<269 && gracz1_y>=440 && gracz1_y<=470){zapis=8;}    
    if(gracz1_x>=467 && gracz1_x<497 && gracz1_y>=17 && gracz1_y<=47){zapis=9;}   
    if(gracz1_x>=637 && gracz1_x<=670 && gracz1_y>=270 && gracz1_y<=310){lvl=0;gracz1_x=1;}
    if(gracz1_x>=637 && gracz1_x<=670 && gracz1_y>=15 && gracz1_y<=30){lvl =0;gracz1_x=1;}
  //==============================================================================================klucze  
    if(gracz1_x>=305 && gracz1_x<=320 && gracz1_y>=455 && gracz1_y<=470){openx=2;}
	if (openx<2){masked_blit( klucz, bufor, 0, 0, 310, 460, klucz->w, klucz->h );}
    if (openx<2){masked_blit( blok, bufor, 0, 0, 600, 24, blok->w, blok->h );}
	
	if(gracz1_x>=185 && gracz1_x<=222 && gracz1_y>=-5 && gracz1_y<=3){win=1;}

	masked_blit( gracz1, bufor, 0, 0, gracz1_x, gracz1_y, gracz1->w, gracz1->h );
   // masked_blit( super, bufor, 0, 0, superx, supery, super->w, super->h );
             }
      if(z>=100){czas+=1;z=0;}
      
      	if(win == 1)
	{
        gracz1_x=365;
        gracz1_y=39;
         st=1;
         score_d=dead+czas/5;
         score=czas+score_d;
         lvl=2;
         textprintf_ex(bufor, font, 280, 240, makecol(0, 150, 115), -1, "SCORE:");  
         textprintf_ex(bufor, font, 330, 240, makecol(0, 150, 115), -1, "%d", score);
         masked_blit( winb, bufor, 0, 0, 180, 100, winb->w, winb->h );
         
         textprintf_ex(bufor, font, 10,440, makecol(0, 150, 115), -1, "Smallest score: Best");
         textprintf_ex(bufor, font, 10,450, makecol(0, 150, 115), -1, "Press key: F1");
         
    }
	if(key[ KEY_F1 ] ) {
            if(lvl==2){openx=0;score=0;score_d=0;st=0;zapis=0;dead=0;czas=0;lvl=0;}
            c=1; menu();
            }
    
           
     textprintf_ex(bufor, font, 5, 5, makecol(0, 150, 115), -1, "DEAD:");  
     textprintf_ex(bufor, font, 45, 5, makecol(0, 150, 115), -1, "%d", dead);
     textprintf_ex(bufor, font, 70, 5, makecol(0, 150, 115), -1, "TIME:");
     textprintf_ex(bufor, font, 110, 5, makecol(0, 150, 115), -1, "%d", czas);
   
     // textprintf_ex(bufor, font, 610, 460, makecol(0, 0, 200), -1, "%d", superx);
      // textprintf_ex(bufor, font, 610, 470, makecol(0, 0, 200), -1, "%d", supery); 
       if( key[ KEY_B ]  ){
           if( key[ KEY_K ]  ){
               if( key[ KEY_M ]  ){
           masked_blit( a123, bufor, 0, 0, 0, 0, a123->w, a123->h );prog=1;
           } } }
       masked_blit( lose_bufor, bufor, 0, 0, 0, 0, 640, 480 );
       
if(przegrana(lose_bufor,gracz1_x,gracz1_y)&& prog==0){	
         dead+=1; 
		 if(zapis==0){gracz1_x=365;	gracz1_y=39;}
	     if(zapis==1){gracz1_x=603;	gracz1_y=245;}
         if(zapis==2){gracz1_x=460;	gracz1_y=316;}
         if(zapis==3){gracz1_x=344;	gracz1_y=394;}
         if(zapis==4){gracz1_x=0;	gracz1_y=290;}
         if(zapis==5){gracz1_x=630;	gracz1_y=290;}
         if(zapis==6){gracz1_x=456;	gracz1_y=256;}
         if(zapis==7){gracz1_x=109;	gracz1_y=297;}
         if(zapis==8){gracz1_x=249;	gracz1_y=450;}
         if(zapis==9){gracz1_x=477;	gracz1_y=27;}
    } 


blit( bufor, screen, 0, 0, 0, 0, 640, 480 );
clear_to_color( lose_bufor, makecol( 255, 0, 255 ) );
}

destroy_bitmap( lose_bufor );
destroy_bitmap( gracz1 );
destroy_bitmap( lose );
destroy_bitmap( bufor );
destroy_bitmap( plansza1 );
destroy_bitmap( save );
    allegro_exit();

return 0;
}
END_OF_MAIN();


