#include "state.hpp"

 State::State(sf::RenderWindow * wind)

{

	window = wind;
	has_ended = false;
	

};

void State::run()

{
	init();
	while(!has_ended)
	
	{
		
		update();
		draw();
		
	}
	
};

void State::reset()
{
	
	has_ended = false;
	
};
	
	
	
	

