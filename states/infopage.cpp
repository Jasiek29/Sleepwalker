class Infopage : public State

{
	public:
	~Infopage() {};
	Infopage(){};
	Infopage(sf::RenderWindow * wind) : State(wind)
	
	{

		};

	
	
	
	protected:


	
	sf::Text tit;
	

	
	sf::Font standard_font;

	
	virtual void init()
	
	
	{
	
		
		
		if (!standard_font.loadFromFile("fonts/Unique.ttf"))
{
    // error...
}
		

		
		tit.setFont(standard_font); 


		tit.setString("This game is a result of a personal game jam,\nthat lasted for about a month.\n I tried to invent a simple game mechanic based on binary decision making.\nYou control a dude in a dreamlike\nlabirynth of rooms with arrow keys and A key.\nThis is the very first project\n I publicly released so please \"Don't be cruel\". I hope you enjoy the result.\nIf you have any feedback I will be happy to receive it at:\njabs29@gmail.com\n\nJan Taras\n\nPress ESC to leave");


		tit.setCharacterSize(20);

		
		// dla centrowania obiektow
		
		sf::FloatRect tempt = tit.getGlobalBounds();

		
		tit.setOrigin(sf::Vector2f(tempt.width/2,tempt.height/2));

		
		tit.setPosition(400,150);


		
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
		
		
	
		};
		
		
	virtual void draw(){
		
		window->clear(sf::Color::Black);
		
		window->draw(tit);

		
		window->display();
		
		
		
		};
	
	
	
};
