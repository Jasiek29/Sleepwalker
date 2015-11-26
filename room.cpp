#include "room.hpp"


Room::Room()

{
	
	ID =-1;
	colour = sf::Color(255,255,255);
	//czas w sekundach jaki mozna pozostac w pomieszczeniu
	time = 10;
	rroom_nr = -1;
	lroom_nr = -1;
	
};

Room::~Room()
{
    
}

void Room::setColour(sf::Color clr){
	
	colour = clr;
	
	};


	
	void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
		
		sf::Texture texture;
		sf::Texture door;
	
	if (!texture.loadFromFile("gfx/room.png"))
	
	{
		std::cout<<"Fuckup"<<std::endl;
		}
		
	if (!door.loadFromFile("gfx/door.png"))
	
	{
		std::cout<<"Fuckup"<<std::endl;
		}
		
		sf::Sprite tile;
		tile.setTexture(texture);
		tile.setScale(sf::Vector2f(2,2));
		tile.setColor(colour);
		
		sf::Sprite tur;
		tur.setTexture(door);
		tur.setOrigin(32,32);
		tur.setScale(sf::Vector2f(2.5,4));
		tur.setColor(sf::Color(64,64,64));
		tur.setPosition(735,240);

		//sf::Vector2f pos = getPosition();
        // apply the transform
        states.transform *= getTransform();
        
			//tile.setPosition(pos.x + 800 ,pos.y +  400 );
			
			target.draw(tile);
			if(!(rroom_nr==-1||rroom_nr>23))target.draw(tur);
			tur.setScale(sf::Vector2f(-2.5,4));
			tur.setPosition(65,240);
			if(!(lroom_nr==-1||lroom_nr>=23))target.draw(tur);

				
    };
	
	
