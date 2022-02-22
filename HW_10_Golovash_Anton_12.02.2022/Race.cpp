#include "Race.h"
#include <iostream>
#include <mutex>
using namespace std;

Race::Race()
{
}

Race::~Race()
{
}

void Race::wrightToFile(const string path)
{
	mutex wrightingMutex;
	wrightingMutex.lock();
	cout << "(wrightToFile) ID - " << this_thread::get_id() << endl;
	wrightingMutex.unlock();
}

void Race::readFromFile(const ifstream& path)
{
	mutex readingMutex;
	readingMutex.lock();
	//ifstream file(path.c_str());

	cout << "(readFromFile) ID - " << this_thread::get_id() << endl;

	char stringbuffer[50]; // buffer for intermediate storage of text read from a file

	while (!path.eof())
	{
		path.getline(stringbuffer, 50); // reading a string from a file
		cout << stringbuffer << endl; // output to the console of the read string
	}

	path.close(); // closing the file

	readingMutex.unlock();
}

void Race::Wright()
{
}

void Race::Read()
{
}

void Race::Action()
{
	cout << "(Action) ID - " << this_thread::get_id() << endl;

}

void Race::Run()
{
	cout << "(Run) ID - " << this_thread::get_id() << endl;

}
