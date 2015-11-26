
class Interlude : public State

{
	public:
	~Interlude() {};
	Interlude(){};
	Interlude(std::string titl,std::string subtitl,sf::RenderWindow * wind) : State(wind)
	
	{
		title = titl;
		subtitle = subtitl;
		fadein_time = 1 ;
		stable_time = 1 ;
		fadeout_time = 1;
		};

	
	
	
	protected:
	
	float fadein_time;
	float fadeout_time;
	float stable_time;
	
	float dt;
	
	std::string title;
	std::string subtitle;
	
	sf::RectangleShape darken;
	
	sf::Text tit;
	sf::Text subtit;
	
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
		subtit.setFont(standard_font); 


		tit.setString(title);
		subtit.setString(subtitle);

		tit.setCharacterSize(24);
		subtit.setCharacterSize(18);
		
		// dla centrowania obiektow
		
		sf::FloatRect tempt = tit.getGlobalBounds();
		sf::FloatRect temps = subtit.getGlobalBounds();
		
		tit.setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));
		subtit.setOrigin(sf::Vector2f(temps.width/2,temps.height/2));
		
		tit.setPosition(400,150);
		subtit.setPosition(400,180);
		
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
		window->draw(subtit);
		
		if(dt<fadein_time || dt>fadein_time+stable_time)window->draw(darken);
		
		window->display();
		
		
		
		};
	
	
	
};
