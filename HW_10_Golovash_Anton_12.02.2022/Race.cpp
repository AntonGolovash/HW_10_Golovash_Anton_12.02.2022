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

void Race::Wright()
{
	mutex mtx;
	mtx.lock();
	cout << "(Wright) ID - " << this_thread::get_id() << endl;

	mtx.unlock();
}

void Race::Read()
{
	cout << "(Read) ID - " << this_thread::get_id() << endl;

}

void Race::Action()
{
	cout << "(Action) ID - " << this_thread::get_id() << endl;

}

void Race::Run()
{
	cout << "(Run) ID - " << this_thread::get_id() << endl;

}
