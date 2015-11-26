class Menu : public State

{
	public:
	~Menu() {};
	Menu(){};
	Menu(int * menu_poi,sf::RenderWindow * wind) : State(wind)
	
	{
		selection_pointer = menu_poi;
		};

	
	
	
	protected:
	
	//przejezdzanie pomiedzy opcjiami w menu
	float select_switch;

	
	float dt;
	
	int * selection_pointer;

	
	//sf::RectangleShape darken;
	

	sf::Texture title;
	
	sf::Sprite tits;
	// opcje menu
	sf::Text selector[4];
	
	//sfx
	sf::SoundBuffer buffer;
// load something into the sound buffer...

sf::Sound blip;

	
	sf::Font standard_font;
	sf::Clock timer;
	
	virtual void init()
	
	
	{
		dt=0;
		select_switch = 0.2;
		
		if (!standard_font.loadFromFile("fonts/Unique.ttf"))
{
    // error...
}
	//	darken = sf::RectangleShape(sf::Vector2f(800,400));
		
//sfx
if (!buffer.loadFromFile("sfx/Blip 007.wav"))

{
     //error
}
blip.setBuffer(buffer);


		if(!title.loadFromFile("gfx/title.png"))std::cout<<"Error"<<std::endl;

		tits.setTexture(title);
		tits.setOrigin(50,8);
		tits.setScale(sf::Vector2f(3,3));
		tits.setPosition(400,100);
		
		sf::FloatRect tempt ;
		
		for(int i =0 ; i<4;i++)
		{
			selector[i].setFont(standard_font);
			selector[i].setCharacterSize(28);
			 
		
		// dla centrowania obiektow
		
			tempt = selector[i].getGlobalBounds();
			selector[i].setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));
			
			selector[i].setPosition(350,150+30*i);
		}
		
		selector[0].setString("Start game");
		selector[1].setString("Info");
		selector[2].setString("Highscores");
		selector[3].setString("Exit");
		
		
		selector[0].setColor(sf::Color(0,127,127));
		
		timer.restart();
		
		};
		
	virtual void update(){
		
		sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            
            {
                window->close();
                has_ended = true;
                }
             
             if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
             
             {
				// has_ended = true;
				 
			 }
             
             if (dt > select_switch && event.type == sf::Event::KeyReleased )
             
             {
				
			if (	 event.key.code == sf::Keyboard::Up)
			
			{
				
						if(selector[0].getColor() == sf::Color(0,127,127))
					
					{
						selector[0].setColor(sf::Color(255,255,255)) ;
						selector[3].setColor(sf::Color(0,127,127)) ;
						
					}
					
					else
					
					{
				
				
				for(int i =1;i<4;i++)
					{
						if(selector[i].getColor() == sf::Color(0,127,127))
						{
							selector[i].setColor(sf::Color(255,255,255)) ;
							selector[i-1].setColor(sf::Color(0,127,127)) ;
							break;
							
						}
						
					}
			
			}
				
				 blip.play();
				 dt=0;
				 timer.restart();
				
			}
			
			if (	 event.key.code == sf::Keyboard::Down)
				
				{
					
					if(selector[3].getColor() == sf::Color(0,127,127))
					
					{
						selector[3].setColor(sf::Color(255,255,255)) ;
						selector[0].setColor(sf::Color(0,127,127)) ;
						
					}
					
					else
					{
					
					for(int i =0;i<3;i++)
					{
						if(selector[i].getColor() == sf::Color(0,127,127))
						{
							selector[i].setColor(sf::Color(255,255,255)) ;
							selector[i+1].setColor(sf::Color(0,127,127)) ;
							break;
							
						}
						
					}
					
				}
					
				 blip.play();
				 dt=0;
				 timer.restart();
			}
				
            
                
			}
		
	
	
	
	 if (dt > select_switch && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
             
             {
				blip.play();
				dt=0;
				while(!dt>select_switch) dt = timer.getElapsedTime().asSeconds();
				
             if(selector[3].getColor() == sf::Color(0,127,127))
             {
                window->close();
                *selection_pointer = 15;
                has_ended = true;
			 }
			 
			if(selector[0].getColor() == sf::Color(0,127,127))
             {
				*selection_pointer = 12;
                has_ended = true;
			 }
			 if(selector[1].getColor() == sf::Color(0,127,127))
             {
				  has_ended = true;
				*selection_pointer = 1;

			 }
			 if(selector[2].getColor() == sf::Color(0,127,127))
             {
				  has_ended = true;
				*selection_pointer = 2;

			 }
			 
                
			}
		
	}
	

		
		dt = timer.getElapsedTime().asSeconds();
		

		
		};
		
		
	virtual void draw(){
		
		window->clear(sf::Color::Black);
		
		window->draw(tits);
		for(int i =0;i<4;i++)
		{
			window->draw(selector[i]);
			
		}
		
		//if(dt<fadein_time || dt>fadein_time+stable_time)window->draw(darken);
		
		window->display();
		
		
		
		};
	
	
	
};
