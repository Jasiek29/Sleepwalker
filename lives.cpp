#include "lives.hpp"

Lives::Lives(int a )

{
	
	number = a;
	
};

Lives::~Lives(){};

void Lives::decreaseLives()

{
	
	number--;
	
};

int Lives::getLivesNumber()

{
	
return number;
	
};


void Lives::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
		
		sf::Texture lamp;
		
if (!lamp.loadFromFile("gfx/lamp.png"))
	
	{
		std::cout<<"Fuckup"<<std::endl;
		}

		sf::Sprite life;
		life.setTexture(lamp);
		life.setScale(sf::Vector2f(6,6));


		//sf::Vector2f pos = getPosition();
        // apply the transform
        states.transform *= getTransform();
        
		for(int i =0;i<number;i++)
		{	
			life.setPosition(25*i,0);
			target.draw(life);
			
			}

				
    };
