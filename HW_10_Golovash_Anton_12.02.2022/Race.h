#pragma once
class Race
{
public:
	Race();
	~Race();
	void wrightToFile(const string);
	void readFromFile(const ifstream&);
	void Wright();
	void Read();
	void Action();
	void Run();

private:

};