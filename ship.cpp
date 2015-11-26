#include "ship.hpp"


Ship::Ship(){

//default size = 24	

	for (int i=0;i<24;i++)
	
	{
		roomarray[i].lroom_nr = i-1;
		roomarray[i].ID = i ;
		roomarray[i].rroom_nr = i+1;
		roomarray[i].setColour(sf::Color(255*(i%2),10*i,127*(i%3)));
		}
	
	occupy_ID = 0;
	destination_ID = 23;
	
	
	
	
	
	};

 void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
		
        // apply the transform
        states.transform *= getTransform();

		for(int i =0;i<24;i++)
		
		{
			if(roomarray[i].ID == occupy_ID) {
				
			
			target.draw(roomarray[i]);
				
				
			}
			
			
		}

    }




int Ship::switch_roomr()

{
			if(occupy_ID==24)return 0;

	for(int i =0;i<23;i++ )
	
	{
		
		if(roomarray[i].ID==occupy_ID)
		
		{
			std::cout<<"Clicked"<<std::endl;
			std::cout<<occupy_ID<<std::endl;
			occupy_ID = roomarray[i].rroom_nr;
			//occupy_ID = i + 1;
			return 1;
				
		}	
		
	}
	return 0;
};


int Ship::switch_rooml()

{
	
	for(int i =1;i<24;i++ )
	
	{
		if(occupy_ID==0)return 0;
		
		
		if(roomarray[i].ID==occupy_ID)
		
		{
			std::cout<<"Clicked"<<std::endl;
			std::cout<<occupy_ID<<std::endl;
			//occupy_ID = i - 1;
			occupy_ID = roomarray[i].lroom_nr;
			return 1;
				
		}	
		
	}
	
	return 0;
};

void Ship::drain_time()

{
	
	
	float e = time_eater.getElapsedTime().asSeconds();
	roomarray[occupy_ID].time -= e;
	//std::cout<<roomarray[occupy_ID].time<<std::endl;
	time_eater.restart();
	};

bool Ship::check_time()


{
	if(roomarray[occupy_ID].time <= 0)return true;
	else return false;
	

};

//ZZrera czas dla wszystkich

void Ship::share_time() 

{
	float min=10;
	
	for(int i =0;i<24;i++ )
	
	{
		if (roomarray[i].time<min) min = roomarray[i].time;
		
	}
	
	for(int j =0;j<24;j++ )
	
	{
	roomarray[j].time = min;
	
}
	
};
