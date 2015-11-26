class Jabs : public State

{
	public:
	~Jabs() {};
	Jabs(){};
	Jabs(sf::RenderWindow * wind) : State(wind)
	
	{
		fadein_time = 1 ;
		stable_time = 1 ;
		fadeout_time = 1;
		};

	
	
	
	protected:
	
	float fadein_time;
	float fadeout_time;
	float stable_time;
	
	float dt;
	
	sf::Text explain;
	
	
	sf::RectangleShape darken;
	
	sf::Text tit;
	
	sf::Texture tex;
	sf::Sprite spr;

	
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


		tit.setString("Made by");

		explain.setFont(standard_font);
		explain.setString("Just a bored slacker");
		explain.setCharacterSize(36);
		explain.setPosition(260,320);

		tit.setCharacterSize(24);

		
		// dla centrowania obiektow
		
		sf::FloatRect tempt = tit.getGlobalBounds();

		
		tit.setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));

		
		tit.setPosition(400,120);


if (!tex.loadFromFile("gfx/jabslogo.png"))
	
	{
		std::cout<<"Fuckup"<<std::endl;
		}

		spr.setTexture(tex);
		spr.setPosition(334,144);

		
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
		window->draw(spr);
		window->draw(explain);
		
		if(dt<fadein_time || dt>fadein_time+stable_time)window->draw(darken);
		
		window->display();
		
		
		
		};
	
	
	
};
