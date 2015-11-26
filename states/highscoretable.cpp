class Highscoretable : public State

{
	public:
	~Highscoretable() {};
	Highscoretable(){};
	Highscoretable(sf::RenderWindow * wind) : State(wind)
	
	{


		};

	void load_results();
	
	
	protected:

	

	
	int your_score;
	
	Score scores[3];
	
	sf::Text highscore_names[3];
	sf::Text highscore_results[3];
	sf::Text mess;
	
	
	sf::Font standard_font;
	sf::Clock timer;
	
	virtual void init()
	
	
	{
		
		
		for (int i =0 ; i<3;i++)
	{
		scores [i] = Score("---",9999);
		
	}
	

		
		
		if (!standard_font.loadFromFile("fonts/Unique.ttf"))
{
    // error...
}
		
		load_results();
		
		// dla centrowania obiektow
		for(int i = 0;i<3;i++)
		
		{
			highscore_names[i].setFont(standard_font);
			highscore_names[i].setString(scores[i].getName());
			highscore_names[i].setCharacterSize(36);
			highscore_names[i].setPosition(320,100+30*i);
			
			highscore_results[i].setFont(standard_font);
			
			std::stringstream ss;
			ss << scores[i].getScore();

			highscore_results[i].setString(ss.str());
			highscore_results[i].setCharacterSize(36);
			highscore_results[i].setPosition(430,100+30*i);
			
		}


			mess.setFont(standard_font);
			mess.setString("Press Enter to return to menu");
			mess.setCharacterSize(36);
			mess.setPosition(150,250);
		

		
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
             
              if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Return))
             
             {

				 has_ended = true;
				 
			 }
             
     
             
             
                
			}
		


		};
		
		
	virtual void draw(){
		
		window->clear(sf::Color::Black);
		
		for(int i = 0; i<3;i++)
		{
		window->draw(highscore_names[i]);
		window->draw(highscore_results[i]);
		}
		window->draw(mess);
		window->display();
		
		
		
		};
	
	
	
};


void Highscoretable::load_results()

{
	int c;
	std::string a,b;
	
	std::ifstream myfile;
  myfile.open ("saves/highscores.tsw");
  while (myfile >> a >> b)
  {
	  c = std::strtol(b.c_str(),0,10); 
	  	for (int i=0;i<3;i++)
	{
		if(c< scores[i].getScore())
		{
			
			if (i<2)
			{
				 scores[2].setName(scores[1].getName());
				 scores[2].setScore(scores[1].getScore());
			}	
			if (i==0)
			{
				scores[1].setName(scores[0].getName());
				 scores[1].setScore(scores[0].getScore());
			}
				
				
		  scores[i].setName(a);
		  scores[i].setScore(c);
			break;
			}
		
	}
	  
  }
  
  myfile.close();	
	

	
	
};


