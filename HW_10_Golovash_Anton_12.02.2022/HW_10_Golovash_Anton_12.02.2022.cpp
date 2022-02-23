#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;

size_t fileSize(const string path)
{
	ifstream file(path.c_str());
	size_t s = 0;

	while (!file.eof())
	{
		file.get();
		s++;
	}

	file.close();
	s--;
	return s;
};

	int lineNumber = 1;

	void wrightToFile(const char* fileNamePointer)
	{
		setlocale(LC_ALL, "ru");

		mutex wrightingMutex;
		wrightingMutex.lock();

		ofstream wrightString;
		wrightString.open(fileNamePointer);

		if (wrightString.is_open())
		{
			wrightString << "Строка " << lineNumber << " в файле \"C++_HW_10.txt\"\n";

			cout << "(wrightToFile) ID - " << this_thread::get_id() << "\t";
			cout << "В файл записана строка номер - " << lineNumber << "\n";

			lineNumber++;

			this_thread::sleep_for(200ms);
		}
		wrightString.close();
		wrightingMutex.unlock();
	};

	void readFromFile(const char* fileNamePointer)
	{
		setlocale(LC_ALL, "ru");

		mutex readingMutex;
		readingMutex.lock();

		ifstream readString;
		readString.open(fileNamePointer);

		if (readString.is_open())
		{
			char* temporaryString = new char[256];
			temporaryString[255] = 0;

			while (!readString.eof())
			{
				readString.getline(temporaryString, 50, '\n');

				std::cout << "(readFromFile) ID - " << this_thread::get_id() << "\t";
				std::cout << temporaryString << endl;

				this_thread::sleep_for(100ms);
			}
			readString.close();
		}
		readingMutex.unlock();
	};

int main()
{
	const char* fileNamePointer = "C++_HW_10.txt";

	for (size_t i = 0; i < 10; i++)
	{
		thread thread_1(wrightToFile, fileNamePointer);
		this_thread::sleep_for(10ms);
		thread thread_2(readFromFile, fileNamePointer);
		thread_1.join();
		thread_2.join();
	}

	system("pause");
	return 0;
};
