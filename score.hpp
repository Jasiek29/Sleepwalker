class Score {
	
	public:
	
	Score();
	Score(std::string nname, int result);
	~Score();
	
	void setName(std::string nom);
	void setScore(int scr);
	
	std::string getName();
	int getScore();
	
	private:
	
	std::string name;
	int score;
	
	
};
