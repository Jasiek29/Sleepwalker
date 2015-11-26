

class Room : public sf::Drawable , public sf::Transformable {

public:

Room();
~Room();
int ID;
int rroom_nr;
int lroom_nr;

sf::Color colour;

void set_r_nr(int nr){rroom_nr=nr;};
void set_l_nr(int nr){lroom_nr=nr;};
void setColour(sf::Color clr);

float time;

private:

virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



};
