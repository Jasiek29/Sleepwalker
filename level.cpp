#include "level.hpp"


Level::Level(int nr,Interlude in,Ingame lv)

{
	number = nr;
	intro = in;
	level = lv;
	
};

void Level::run()


{
	intro.run();
	level.run();
	
	
	
	};



Level::~Level()

{
	
};
