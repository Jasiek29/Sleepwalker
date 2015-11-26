#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>


#include "score.cpp"

#include "state.cpp"
#include "room.cpp"

#include "ship.cpp"

#include "lives.cpp"

#include "states/menu.cpp"
#include "states/ingame.cpp"
#include "states/interlude.cpp"
#include "states/logo.cpp"
#include "states/jabs.cpp"
#include "states/gameover.cpp"
#include "states/livesleft.cpp"
#include "states/infopage.cpp"
#include "states/wingame.cpp"
#include "states/highscorein.cpp"
#include "states/highscoretable.cpp"



#include "level.cpp"



int main()
{
	int tmp_lives =0 ;
	int lives = 3;
	std::stack<Level> lvlstack;
	int menu_pointer = 0;
	sf::Clock beat_time;
	int sukowa;
	
   sf::RenderWindow window(sf::VideoMode(800, 400), "Sleepwalker");
    window.setFramerateLimit(60);
    
    Highscoretable highscoretable(&window);
    Highscorein highscorein(1233,&window);
    Livesleft livesleft(&lives,&window);
    Gameover gameover(&window);
    Logo logo(&window);
    Jabs jabs(&window);
    Infopage infopage(&window);
    Menu menu(&menu_pointer,&window);
    
    Interlude intone("Level 1","Sometimes life is just a straight walk ahead.",&window);
    Interlude inttwo("Level 2","Sometimes it is like a zig-zag.",&window);
    Interlude intthree("Level 3","Sometimes in life you have to take two steps forward and then one back.",&window);
    Interlude intfour("Level 4","Don't panic.",&window);
    Interlude intfive("Level 5","Follow the arrows.",&window);
    Interlude intsix("Level 6","Colors matter.",&window);
    Interlude intseven("Level 7","Some arrows are traitors.",&window);
    Interlude inteight("Level 8","No traitors this time just run. Just run!",&window);
    Interlude intnine("Level 9","You little brat. You made it.",&window);
    Interlude intten("Level 10","The writing on the wall.",&window);
    
    
	Ingame lvlone(1,&lives,&window);
	Ingame lvltwo(2,&lives,&window);
	Ingame lvlthree(3,&lives,&window);
	Ingame lvlfour(4,&lives,&window);
	Ingame lvlfive(5,&lives,&window);
	Ingame lvlsix(6,&lives,&window);
	Ingame lvlseven(7,&lives,&window);
	Ingame lvleight(8,&lives,&window);
	Ingame lvlnine(9,&lives,&window);
	Ingame lvlten(10,&lives,&window);
	
	Level levels[10];
	
	 levels[0] = Level(1,intone,lvlone);
	 levels[1] = Level(2,inttwo,lvltwo);
	 levels[2] = Level(3,intthree,lvlthree);
	 levels[3] = Level(4,intfour,lvlfour);
	 levels[4] = Level(5,intfive,lvlfive);
	 levels[5] = Level(6,intsix,lvlsix);
	 levels[6] = Level(7,intseven,lvlseven);
	 levels[7] = Level(8,inteight,lvleight);
	 levels[8] = Level(9,intnine,lvlnine);
	 levels[9] = Level(10,intten,lvlten);
	

		for (int i = 9 ; i>=0;i--)

		{
			
			lvlstack.push(levels[i]);
			
		}

	logo.run();
	jabs.run();
	//highscoretable.run();
	//highscorein.run();
	
	do 
	{
	menu.run();
	
		if(menu_pointer == 1)
		{
			infopage.run();
			menu = Menu(&menu_pointer,&window);
			infopage.reset();
		}
		if(menu_pointer == 2)
		{
			highscoretable.run();
			menu = Menu(&menu_pointer,&window);
			highscoretable.reset();
		}
		if(menu_pointer == 12)
		{
			beat_time.restart();
	while (!lvlstack.empty() && window.isOpen()&&lives>0)
  {
	 tmp_lives = lives;
     lvlstack.top().run();
     lvlstack.pop();
     if(lives != tmp_lives)
     
     {
		 lvlstack.push(levels[9-lvlstack.size()]);
		// livesleft.run();
	 }

  }
  if(window.isOpen())
  {
  
  if (lives>0)
  
  {
	  sukowa = beat_time.getElapsedTime().asSeconds();
	  Wingame wingame(sukowa,&window);
	  wingame.run();
	  menu = Menu(&menu_pointer,&window);
	  wingame.reset();
	  	  while(!lvlstack.empty())lvlstack.pop();

	  for (int i = 9 ; i>=0;i--)

		{
			
			lvlstack.push(levels[i]);
			
		}
	  lives = 3;
  }
  
  else
  {
	  gameover.run();
	  menu = Menu(&menu_pointer,&window);
	  gameover = Gameover(&window);
	  while(!lvlstack.empty())lvlstack.pop();
	  for (int i = 9 ; i>=0;i--)

		{
			
			lvlstack.push(levels[i]);
			
		}
		lives = 3;
  }
}
		}
		
	if(!window.isOpen()||menu_pointer == 15)menu_pointer = 0;
	}while(menu_pointer != 0 );
	


    return 0;
}
