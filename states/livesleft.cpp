class Livesleft : public State

{
	public:
	~Livesleft() {};
	Livesleft(){};
	Livesleft(int *lives_nr,sf::RenderWindow * wind) : State(wind)
	
	{
		lives = lives_nr;
		fadein_time = 1 ;
		stable_time = 1 ;
		fadeout_time = 1;
		};

	
	
	
	protected:
	
	int* lives;
	float fadein_time;
	float fadeout_time;
	float stable_time;
	
	float dt;
	
	
	sf::RectangleShape darken;
	
	sf::Text tit;
	
	
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
		std::string temple ;
		
		std::stringstream ss;
		ss << lives;
		if(*lives==0) temple =  "No lives left";
		if(*lives==2) temple =  "2 lives left";
		if(*lives==1) temple =  "1 life left";
		
		
		tit.setString(temple);


		tit.setCharacterSize(24);

		
		// dla centrowania obiektow
		
		sf::FloatRect tempt = tit.getGlobalBounds();

		
		tit.setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));

		
		tit.setPosition(400,150);



		
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

		if(dt<fadein_time || dt>fadein_time+stable_time)window->draw(darken);
		
		window->display();
		
		
		
		};
	
	
	
};
