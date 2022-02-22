#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include "Race.h"
#include "FILE.h"
#include "LOG.cpp"
using namespace std;

void writeToFile(int numberDegree, string path)
{
	mutex wrightingMutex;
	wrightingMutex.lock();

	File::Clear(path);
	string data{ "" };

	for (size_t i = 2, number = 0; i < numberDegree; i *= 2, number++)
	{
		cout << path << endl;
		this_thread::sleep_for(2000ms);
		data = to_string(number) + "^2->" + to_string(i);
		File::Append(data, path);
		cout << "Wrote the data:\t" << data << endl;
	}

	Log::Append("Success", File::GetPath("log.txt"));
	wrightingMutex.unlock();
}

size_t fileSize(const string path) // size of file 
{
	ifstream file(path.c_str());
	size_t s = 0; // char counter

	while (!file.eof()) // while not the end of file
	{
		file.get(); // reading by one char
		s++; // increasing char counter
	}

	file.close(); // file closing
	s--; // removing extra iteration
	return s; // returning char counter
};

int main()
{
	//******************************************************

	ofstream wrightString;// creating an object of class ofstream for WRIGHTING STRING
	
	ifstream readWord;// creating an object of class ifstream for READING WORD 
	
	ifstream readString;// creating an object of class ifstream for READING STRING

	const char* fileNamePointer = "C++_HW_10.txt";// creating the file name pointer

	//wrightString
	{
		wrightString.open(fileNamePointer);// linking addString with file C++_HW_10.txt

		if (wrightString.is_open())
		{
			wrightString << "Первая строчка в файле\n"; // wrighting the string in the file
			wrightString << "Вторая строчка в файле\n"; // wrighting the string in the file
			wrightString << "Третья строчка в файле\n"; // wrighting the string in the file
			wrightString << "Четвёртая строчка в файле\n"; // wrighting the string in the file
			wrightString << "Пятая строчка в файле\n"; // wrighting the string in the file
		}

		wrightString.close(); // closing the file
	}
	//wrightString
	// 
	//readWord
	{
		setlocale(LC_ALL, "rus");
		char wordbuffer[50]; // buffer for intermediate storage of text read from a file

		readWord.open(fileNamePointer); // opening file for reading

		if (readWord.is_open())
		{
			while (!readWord.eof())
			{
				readWord >> wordbuffer; // reading a word from a file
				cout << wordbuffer << endl; // output to the console of the read word
			}
		}

		readWord.close(); // closing the file
	}
	//readWord
	
	//readString
	{
		readString.open(fileNamePointer); // opening file for reading

		if (readString.is_open())
		{
			while (!readString.eof())
			{
				readString.getline(wordbuffer, 50); // reading a string from a file
				cout << wordbuffer << endl; // output to the console of the read string
			}
		}
		readString.close(); // closing the file
	}
	//readString

	int threadLimit = thread::hardware_concurrency();
	cout << "Limit of threads - " << threadLimit << endl;
	cout << "(Main) ID - " << this_thread::get_id() << endl;

	//wrightStringAppend
	{
		wrightString.open(fileNamePointer, wrightString.app);

		if (wrightString.is_open())
		{
			wrightString << "Шестая строчка в файле\n"; // wrighting the string in the file
			wrightString << "Седьмая строчка в файле\n"; // wrighting the string in the file
			wrightString << "Восьмая строчка в файле\n"; // wrighting the string in the file
			wrightString << "Девятая строчка в файле\n"; // wrighting the string in the file
		}
	}
	//wrightStringAppend

	cout << "Size of \"C++_HW_10.txt\" - " << fileSize("C++_HW_10.txt") << " bytes" << endl;

	//*******************

	//Race race;
	//thread WrightThread;
	//thread ReadThread;
	//thread ActionThread;
	//thread RunThread;

	//WrightThread.join();
	//ReadThread.join();
	//ActionThread.join();
	//RunThread.join();

	//*******************

	cout << "Thread count:\t" << thread::hardware_concurrency() << endl;
	//cout << File::GetPath("degree2048.txt") << endl;
	thread thread_1(writeToFile, 2048, File::GetPath("degree2048.txt"));
	thread thread_2(writeToFile, 1024, File::GetPath("degree1024.txt"));
	thread thread_3(writeToFile, 4096, File::GetPath("degree4096.txt"));

	thread_1.join();
	thread_2.join();
	thread_3.join();

	//*******************

	system("pause");
	return 0;
}
