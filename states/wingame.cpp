class Wingame : public State

{
	public:
	~Wingame() {};
	Wingame(){};
	Wingame(int scr,sf::RenderWindow * wind) : State(wind)
	
	{
		your_score = scr;
		fadein_time = 1 ;
		stable_time = 1 ;
		fadeout_time = 1;
		};

	
	
	
	protected:

	float fadein_time;
	float fadeout_time;
	float stable_time;
	
	float dt;
	
	int your_score;
	
	sf::RectangleShape darken;
	
	sf::Text tit;
	sf::Text score;
	
	
	sf::Font standard_font;
	sf::Clock timer;
	
	virtual void init()
	
	
	{
		dt=0;
		
		
		if (!standard_font.loadFromFile("fonts/Unique.ttf"))
{
    // error...
}
		darken = sf::RectangleShape(sf::Vector2f(800,400));
		

		
		tit.setFont(standard_font); 
		score.setFont(standard_font); 

		std::stringstream ss;
		ss << your_score;
		std::string str = ss.str();
		
		
		tit.setString("Congrats! You beat the game\nIt took you:");
		
		score.setString(str + " seconds");


		tit.setCharacterSize(24);
		score.setCharacterSize(24);

		
		// dla centrowania obiektow
		
		sf::FloatRect tempt = tit.getGlobalBounds();
		sf::FloatRect tempr = score.getGlobalBounds();

		
		tit.setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));
		score.setOrigin(sf::Vector2f(tempr.width/2,tempr.height/2));

		
		tit.setPosition(400,150);
		score.setPosition(400,200);

		score.setColor(sf::Color(0,127,127));

		
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
				 has_ended = true;
				 
			 }
             
             
                
			}
		
		
		dt = timer.getElapsedTime().asSeconds();
		
		if(dt<fadein_time)
		
		{
			darken.setFillColor(sf::Color(0,0,0, 255-(255/fadein_time)*dt));
			}
			if(dt>fadein_time+stable_time)
		
		{
			darken.setFillColor(sf::Color(0,0,0, (255/fadeout_time)*(dt-fadein_time-stable_time)));
			}
		
		if(dt>fadein_time+stable_time+fadeout_time)has_ended=true;
		
		};
		
		
	virtual void draw(){
		
		window->clear(sf::Color::Black);
		
		window->draw(tit);
		window->draw(score);

		if(dt<fadein_time || dt>fadein_time+stable_time)window->draw(darken);
		
		window->display();
		
		
		
		};
	
	
	
};
