

class Ship : public sf::Drawable , public sf::Transformable {


public:

Ship();



Room roomarray[24];

int switch_roomr();
int switch_rooml();

int occupy_ID;
int destination_ID;
//zzerac czas w pomieszczeniach;
sf::Clock time_eater;



void drain_time();
bool check_time();
// Level 4 only
void share_time();


private:

virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};
