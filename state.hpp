



class State 

{
	public:
	
	sf::RenderWindow * window;
	State(){};
	State(sf::RenderWindow * wind);
	virtual ~State(){};
	

	void run();
	void reset();
	protected:
	
	bool has_ended;
	
	
	virtual void init()=0;
	virtual void update()=0;
	virtual void draw()=0;
	
	
	
	
	
	
	
	
};


