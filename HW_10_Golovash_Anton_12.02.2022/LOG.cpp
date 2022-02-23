#include<string>
#include<time.h>// <ctime>
#include"FILE.h"
#include <sstream>
using namespace std;

class Log
{
public:
	Log();
	~Log();
	static void Append(string event, string path)
	{
		time_t now = time(nullptr);
		tm timeNow = *localtime(&now);
		stringstream ss;
		ss << "time:\t" << put_time(&timeNow, "%m:%d:%Y %T") << "\t"
			<< "event:\t" << event << "\n";
		File::Append(ss.str(), path);
	}
};