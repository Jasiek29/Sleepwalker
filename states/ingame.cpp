


class Ingame : public State

{
	public:
	~Ingame() {};
	Ingame() {};
	Ingame(int lv_nr,int *liv_nr,sf::RenderWindow * wind) : State(wind)
	
	{
		lvl_nr = lv_nr;
		lives_nr = liv_nr;
		};


	
	protected:
	
	Lives lives;
	
		void level(int nr);
	Ship ship;
	int lvl_nr;
	int * lives_nr;
	
	//textury tylko dla niektorych poziomow
	sf::Texture guide_arrow;
	sf::Texture warn;
	sf::Texture nar;
	
	sf::Texture comp;
	sf::Texture cha;
	sf::Texture como;
	sf::Texture comtw;
	sf::Texture comth;
	sf::Texture bom;
	sf::Texture lau;
	
	
	sf::Texture butt;
	sf::Texture plr;
	sf::Texture abutt;
	sf::Texture bett;
	sf::Texture nightlamp;
	sf::RectangleShape darken;
	
	//sprity tylko dla niektorych poziomow
	sf::Sprite garl;
	sf::Sprite garr;
	sf::Sprite warnin;
	sf::Sprite narrator;
	sf::Sprite computer;
	sf::Sprite chair;
	sf::Sprite comone;
	sf::Sprite comtwo;
	sf::Sprite comthree;
	sf::Sprite bomb;
	sf::Sprite launcher;
	
	
	sf::Sprite arrr;
	sf::Sprite arrl;
	sf::Sprite abutton;
	sf::Sprite bed;
	sf::Sprite lamp;
	
	sf::Sprite player;

virtual void init()

{
	lives = Lives(*lives_nr);
	
	if(!window->isOpen())has_ended=true;
	 darken = sf::RectangleShape(sf::Vector2f(800,400));
	
	 ship = Ship();
	level(lvl_nr);

	
	if (!nightlamp.loadFromFile("gfx/nightlamp.png"))
	
	{
    // error...
		}
	
	if (!butt.loadFromFile("gfx/arrow.png"))
	
	{
    // error...
		}
		
		if (!abutt.loadFromFile("gfx/a.png"))
	
	{
    // error...
		}
		
		if (!bett.loadFromFile("gfx/bed.png"))
	
	{
    // error...
		}
		
		
	if (!plr.loadFromFile("gfx/lanternman.png"))
	
	{
    // error...
		}
	
	if(lvl_nr == 5 || lvl_nr == 7 || lvl_nr == 8)
	
	{
		if (guide_arrow.loadFromFile("gfx/garrow.png"))
	
	{
    // error...
		}
		
		if (guide_arrow.loadFromFile("gfx/garrow.png"))
	
	{
    // error...
		}
		
		if (warn.loadFromFile("gfx/warning.png"))
	
	{
    // error...
		}
		
		
	}
	
	if( lvl_nr == 9)
	
	{
		if (nar.loadFromFile("gfx/narrator.png"))
	
	{
    // error...
		}
		
		if (bom.loadFromFile("gfx/atom bomb.png"))
	
	{
    // error...
		}
		
		if (lau.loadFromFile("gfx/launcher.png"))
	
	{
    // error...
		}
	
		
		
	}
	
	if(lvl_nr == 10)
	
	{
		if (comp.loadFromFile("gfx/pc.png"))
	
	{
    // error...
		}
		
		
		if (cha.loadFromFile("gfx/chair.png"))
	
	{
    // error...
		}
		
		if (como.loadFromFile("gfx/com1.png"))
	
	{
    // error...
		}
		
		if (comtw.loadFromFile("gfx/com2.png"))
	
	{
    // error...
		}
		
		if (comth.loadFromFile("gfx/com3.png"))
	
	{
    // error...
		}
		
		
	}
	
	player.setTexture(plr);
	//set origin - zeby latwo obracac
	player.setOrigin(sf::Vector2f(16,24));
	player.setPosition(sf::Vector2f(400,250));
    player.setScale(sf::Vector2f(4,4));
	
	arrr.setTexture(butt);
	arrr.setPosition(sf::Vector2f(350,132));
	
	arrl.setTexture(butt);
	arrl.setPosition(sf::Vector2f(450,132));
    arrl.setScale(sf::Vector2f(-1,1));
    
    abutton.setTexture(abutt);
    abutton.setPosition(sf::Vector2f(388,100));
    
    bed.setTexture(bett);
    bed.setScale(sf::Vector2f(5,5));
    bed.setPosition(sf::Vector2f(310,190));
    
    
	lamp.setTexture(nightlamp);
    lamp.setScale(sf::Vector2f(4,4));
    lamp.setPosition(sf::Vector2f(470,196));
	
	if(lvl_nr == 5 || lvl_nr == 7 || lvl_nr == 8)
	
	{
		warnin.setTexture(warn);
		warnin.setOrigin(sf::Vector2f(32,32));
		
		warnin.setScale(sf::Vector2f(2,2));
		warnin.setPosition(sf::Vector2f(550,100));
		
		garl.setTexture(guide_arrow);
		garr.setTexture(guide_arrow);
		
		garl.setOrigin(sf::Vector2f(16,16));
		garr.setOrigin(sf::Vector2f(16,16));
		
		garl.setScale(sf::Vector2f(-1,1));
		
		garr.setPosition(sf::Vector2f(450,200));
		garl.setPosition(sf::Vector2f(350,200));
		
		garl.setColor(sf::Color(0,255,0));
		garr.setColor(sf::Color(0,255,0));
		
	}
	
	if(lvl_nr == 9)
	
	{
		
		narrator.setTexture(nar);
		narrator.setOrigin(16,16);
		narrator.setPosition(184,224);
		narrator.setScale(5,5);
		bomb.setTexture(bom);
		launcher.setTexture(lau);
		launcher.setScale(5,5);
		bomb.setScale(2,2);
		
		bomb.setPosition(500,100);
		launcher.setPosition(388,168);
	}
	
	if(lvl_nr == 10)
	
	{
		
		computer.setTexture(comp);
		computer.setOrigin(32,32);
		computer.setPosition(328,188);
		computer.setScale(1.5,1.5);
		
		chair.setTexture(cha);
		chair.setOrigin(32,32);
		chair.setPosition(468,268);
		chair.setScale(2.5,2.5);
		
		
		comone.setTexture(como);
		comone.setPosition(100,100);
		comone.setScale(3,3);
		comtwo.setTexture(comtw);
				comtwo.setPosition(90,100);
				comtwo.setScale(0.20,0.20);

		comthree.setTexture(comth);
				comthree.setPosition(100,100);

		
	}
	
	
};

virtual void update()

{
	
	sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            
            {
                window->close();
                has_ended = true;
                }
                
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right){
				
				
				if( ship.switch_roomr())
				{
				if(lvl_nr==9&&ship.occupy_ID%3==0) 
				
				{
					 narrator.setScale(sf::Vector2f(-5,5));
					 narrator.setPosition(584,224);
				 }
				 else
				 
				 {
					  narrator.setScale(sf::Vector2f(5,5));
					 narrator.setPosition(184,224);
				 }
				 
				player.setScale(sf::Vector2f(4,4));
				 
				 
			 }
				 
				 }   
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left){
				
				 
				 if(ship.switch_rooml()) 
				 
				 {
					 
				 if(lvl_nr==9&&ship.occupy_ID%3==0)
				 
				 {
					 narrator.setScale(sf::Vector2f(-5,5));
					 narrator.setPosition(584,224);
				 }
				 else
				 
				 {
					  narrator.setScale(sf::Vector2f(5,5));
					 narrator.setPosition(184,224);
				 }
				 
				 
				  player.setScale(sf::Vector2f(-4,4));  
				  
			  }
				  
				 } 
				 
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A){
				
				 
				 if(ship.occupy_ID==ship.destination_ID)  
				 
				 {
					 
					 has_ended = true;  
				  
				  
			  }
				  
				 } 
                
        }
	
	
	
	 ship.drain_time();
	 if(lvl_nr == 9)
	 
	 {
		
		 if(narrator.getPosition().x>370&&narrator.getPosition().x<430)
     {
		  has_ended = true;
		  --*lives_nr;
		  
		  }
		  if(narrator.getPosition().x < 410)narrator.setPosition(184 + 138*(10-ship.roomarray[ship.occupy_ID].time),224+30*sin(ship.roomarray[ship.occupy_ID].time)); 
		 if(narrator.getPosition().x > 390)narrator.setPosition(584 - 138*(10-ship.roomarray[ship.occupy_ID].time),224+30*sin(ship.roomarray[ship.occupy_ID].time)); 
		 
		  
	 }
	 
	 //Level 4 and 8  only
	 
	 if(lvl_nr==4 || (lvl_nr == 8 && ship.occupy_ID>14))ship.share_time();
	 
	 //
	 
     if(ship.check_time())
     {
		  has_ended = true;
		  --*lives_nr;
		  
		  }
	
};

virtual void draw()

{
	darken.setFillColor(sf::Color(0,0,0, 255-(255/10)*int(ship.roomarray[ship.occupy_ID].time)));
                window->clear(sf::Color::Black);
                window->draw(ship);
                
                 if(lvl_nr == 9)
	   
	   {
		   
		   window->draw(narrator);
		   
		   
	   }
                
                
                if(ship.occupy_ID!=ship.destination_ID)
                
                {
					
                window->draw(arrr);
                window->draw(arrl);
       
       //Level 5 only
       if(lvl_nr==5 || lvl_nr == 8)
       
       {
		   if (lvl_nr == 5 && ship.occupy_ID == 16)window->draw(warnin);
		   if (ship.occupy_ID == 0 || ship.occupy_ID + 1 == ship.roomarray[ship.occupy_ID].rroom_nr)
		  {
			 if (lvl_nr==5) window->draw(garr);
			 else window->draw(garl);
		  } 
		   else 
		   
		   {
			   if(ship.occupy_ID!=23&& lvl_nr == 5)window->draw(garl);
			   else window->draw(garr);
			   
		   }
		   
		   
	   }
	   
	   if (lvl_nr == 7 )
	   
	   {
		   
		   if (ship.occupy_ID == 0 || ship.occupy_ID + 1 == ship.roomarray[ship.occupy_ID].rroom_nr)
		  {
			 if (ship.roomarray[ship.occupy_ID].colour != sf::Color(0,255,0)) window->draw(garr);
			 else window->draw(garl);
		  } 
		   else 
		   
		   {
			   if(ship.occupy_ID!=23 && ship.roomarray[ship.occupy_ID].colour != sf::Color(0,255,0))window->draw(garl);
			   else window->draw(garr);
			   
		   }
		   
		   
	   }
	   
	  if (lvl_nr == 10)
	  
	  {
		  if (ship.occupy_ID == 4)window->draw(comone);
		  if (ship.occupy_ID == 9)window->draw(comtwo);
		  if (ship.occupy_ID == 16)window->draw(comthree);
		  
	  }
       
                
			}
			
			else 
			
			{
				if(lvl_nr == 10)
				
				{
					window->draw(computer);
					window->draw(chair);
					window->draw(abutton);
					
					
				}
				
				else
				{
				if(lvl_nr == 9)
				
				{
					window->draw(abutton);
					window->draw(bomb);
					window->draw(launcher);
					
					
					
				}
				else
				
				{
				 window->draw(abutton);
				 window->draw(bed);
				 window->draw(lamp);
			 }
			 
			 }
			}
			
                window->draw(player);
                
                window->draw(lives);
                //temporary solution
                window->draw(darken);
                window->display();
	
	
};



};


void Ingame::level(int nr){
	switch(nr)
	{
		
		case 2:
		
		for (int i=0;i<24;i++)
	
	{

	if(i%2 != 0)
	
	{
					std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
	}
	
}
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		
		case 3:
		
			for (int i=0;i<24;i++)
	
	{

	if(i%3 == 2)
	
	{
					std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
	}
	
}
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		
		case 4:
		
			for (int i=0;i<24;i++)
	
	{

		ship.roomarray[i].setColour(sf::Color(255,255,255));
	
}
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		case 5:
		
			for (int i=0;i<24;i++)
	
	{
		if(i != 0 && (i%3 == 0 || i%5 == 0 || i%7 == 0))
	
	{
					std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
	}
	
		ship.roomarray[i].setColour(sf::Color(255,255,255));
	
}
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		case 6:
		
				for (int i=0;i<24;i++)
	
	{

	if((i%4 == 0 || i%7 == 0)&& i!=0)
	
	{
					std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
		ship.roomarray[i].setColour(sf::Color(255,0,0));
	}
	
	else
	
	{
		
				ship.roomarray[i].setColour(sf::Color(0,255,0));

		
		
	}
	
}
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		case 7:
		
		
		
			for (int i=0;i<24;i++)
	
	{

	if ((i%3 ==0 || i%5 == 0)&& i!=0)
	
	{
			std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
		
		
		
	}


	if((i%4 == 0 || i%7 == 0)&& i!=0)
	
	{
		
		ship.roomarray[i].setColour(sf::Color(255,0,0));
	}
	
	else
	
	{
		
				ship.roomarray[i].setColour(sf::Color(0,255,0));

		
		
	}
	
}
		ship.roomarray[0].setColour(sf::Color(0,0,255));
		
		ship.roomarray[23].setColour(sf::Color(0,0,255));
		
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		case 8:
		
				
			for (int i=0;i<24;i++)
	
	{

	if ((i%3 ==0 || i%5 == 0)&& i!=0)
	
	{
			std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
		
		
		
	}

ship.roomarray[i].setColour(sf::Color(255,255,255));

	
}
		
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		case 9:
		
		for (int i=0;i<24;i++)
	
	{

	if(i%3 == 0 && i!=0)
	
	{
					std::cout<<"B"<<std::endl;
		if(i!=23)ship.roomarray[i].set_l_nr(i+1) ;
		ship.roomarray[i].set_r_nr(i-1);
	}
	
}
		
		
		
		
		ship.roomarray[23].set_r_nr(-1);
		break;
		
		
		
		
		default:
		
		
		break;
		
		
		
		
	}
	
	
	
	
	
	};
