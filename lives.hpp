

class Lives : public sf::Drawable , public sf::Transformable

{
	public:
	
	Lives(int a);
	Lives(){};
	~Lives();
	
	void decreaseLives();
	int getLivesNumber();
	
	protected:
	int number;
	
	private:
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
};
