class Level 

{
	public:
	Level(){};
	Level(int nr,Interlude in,Ingame lv);
	~Level();
	Interlude intro;
	Ingame level;
	void run();
	
	private:
	int number;
	
	
	
	};
