class Highscorein : public State

{
	public:
	~Highscorein() {};
	Highscorein(){};
	Highscorein(int scr,sf::RenderWindow * wind) : State(wind)
	
	{
		your_score = scr;

		};


	
	
	protected:

	
	int your_score;
	
	std::string characters[26];
	
	sf::Text tit;
	sf::Text score;
	sf::Text name[3];
	std::string str;
	
	sf::Font standard_font;
	sf::Clock timer;
	
	virtual void init()
	
	
	{
		characters[0]="A";
		characters[1]="B";
		characters[2]="C";
		characters[3]="D";
		characters[4]="E";
		characters[5]="F";
		characters[6]="G";
		characters[7]="H";
		characters[8]="I";
		characters[9]="J";
		characters[10]="K";
		characters[11]="L";
		characters[12]="M";
		characters[13]="N";
		characters[14]="O";
		characters[15]="P";
		characters[16]="Q";
		characters[17]="R";
		characters[18]="S";
		characters[19]="T";
		characters[20]="U";
		characters[21]="V";
		characters[22]="W";
		characters[23]="X";
		characters[24]="Y";
		characters[25]="Z";
		
		
		
		
		
		if (!standard_font.loadFromFile("fonts/Unique.ttf"))
{
    // error...
}

		
		for(int i = 0;i<3;i++)
		
		{
			name[i].setFont(standard_font);
			name[i].setString("A");
			name[i].setCharacterSize(36);
			name[i].setPosition(370+30*i,200);
		}
		name[0].setColor(sf::Color(0,127,127));
		
		tit.setFont(standard_font); 
		score.setFont(standard_font); 

		std::stringstream ss;
		ss << your_score;
		 str = ss.str();
		
		
		tit.setString("TYPE in your name:");
		
		score.setString(str + " seconds");


		tit.setCharacterSize(24);
		score.setCharacterSize(24);

		
		// dla centrowania obiektow
		
		sf::FloatRect tempt = tit.getGlobalBounds();
		sf::FloatRect tempr = score.getGlobalBounds();

		
		tit.setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));
		score.setOrigin(sf::Vector2f(tempr.width/2,tempr.height/2));

		
		tit.setPosition(400,150);
		score.setPosition(400,250);

		score.setColor(sf::Color(0,127,127));

		
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
				 save_score();
				 has_ended = true;
				 
			 }
             
             if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
             
             {
				 for(int i =0 ; i<3;i++)
				 {
					 if(name[i].getColor() == sf::Color(0,127,127))
					 {
						 if(name[i].getString()==characters[25])
						 {
							 name[i].setString(characters[0]);
							 
							 }
							 else
							 {
						 for(int j=0;j<25;j++)
						 {
							 if(name[i].getString()==characters[j])
							 {
								 name[i].setString(characters[j+1]);
								 break;
							 }
						 }
					 }
					 }
				 }
				 
			 }
			 
			  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
             
             {
				 for(int i =0 ; i<3;i++)
				 {
					 if(name[i].getColor() == sf::Color(0,127,127))
					 {
						 if(name[i].getString()==characters[0])
						 {
							 name[i].setString(characters[25]);
							 
							 }
							 else
							 {
						 for(int j=1;j<26;j++)
						 {
							 if(name[i].getString()==characters[j])
							 {
								 name[i].setString(characters[j-1]);
								 break;
							 }
						 }
					 }
					 }
				 }
				 
			 }
			 
			 
			 			  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
			 			  {
							   for(int i =0 ; i<3;i++)
				 {
					 if(name[i].getColor() == sf::Color(0,127,127))
					 {
						name[i].setColor(sf::Color(255,255,255));
						name[(i+1)%3].setColor(sf::Color(0,127,127));
						break;
						 }
					 
				 }
						  }

			 if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
			 			  {
							  for(int i =0 ; i<3;i++)
				 {
					 if(name[i].getColor() == sf::Color(0,127,127))
					 {
						name[i].setColor(sf::Color(255,255,255));
						name[(i-1)%3].setColor(sf::Color(0,127,127));
						break;

						 }
					 
				 }  
						  }
			 
                
			}
		
		
	
		};
		
		
	virtual void draw(){
		
		window->clear(sf::Color::Black);
		
		window->draw(tit);
		window->draw(score);
		for(int i=0;i<3;i++)
		{
		window->draw(name[i]);
	}
		window->display();
		
		
		
		};
	
	void save_score()
	{
	std::ofstream myfile;
  myfile.open ("saves/highscores.tsw");
  myfile << std::string(name[0].getString());
  myfile << std::string(name[1].getString());
  myfile << std::string(name[2].getString());
  myfile << " ";
  myfile << str;
  myfile << "\n";
  
  myfile.close();	
	};
	
};
