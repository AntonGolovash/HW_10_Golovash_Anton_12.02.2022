#include <iostream>
#include <fstream>
#include <thread>
#include "Race.h"

using namespace std;

int main()
{
	//******************************************************

	ofstream addString;
	ifstream getWord;
	ifstream getString;

	addString.open("LOG_HW_10.txt"); // создаём объект класса ofstream для записи и связываем его с файлом C++_HW_10.txt
	
	if (addString.is_open())
	{
		addString << "Первая строчка в файле\n"; // запись строки в файл
		addString << "Вторая строчка в файле\n"; // запись строки в файл
		addString << "Третья строчка в файле\n"; // запись строки в файл
		addString << "Четвёртая строчка в файле\n"; // запись строки в файл
		addString << "Пятая строчка в файле\n"; // запись строки в файл
	}
	
	addString.close(); // закрываем файл

	//******************************************************
	
	setlocale(LC_ALL, "rus");
	char wordbuffer[50]; // буфер промежуточного хранения считываемого из файла текста
	
	getWord.open("LOG_HW_10.txt"); // открытие файла для чтения

	if (getWord.is_open())
	{
		while (!getWord.eof())
		{
			getWord >> wordbuffer; // считывание слова из файла
			cout << wordbuffer << endl; // печать считанного слова слово
		}
	}
	
	getWord.close(); // закрытие файла

	//******************************************************

	getString.open("LOG_HW_10.txt"); // открытие файла для чтения

	if (getString.is_open())
	{
		while (!getString.eof())
		{
			getString.getline(wordbuffer, 50); // считывание строки из файла
			cout << wordbuffer << endl; // печать считанной строки
		}
	}
	getString.close(); // закрытие файла

	//******************************************************

	int threadLimit = thread::hardware_concurrency();
	cout << "Limit of threads - " << threadLimit << endl;
	cout << "(Main) ID - " << this_thread::get_id() << endl;

	//******************************************************

	addString.open("C++_HW_10.txt", ios::app);

	if (addString.is_open())
	{
		addString << "Шестая строчка в файле\n"; // запись строки в файл
		addString << "Седьмая строчка в файле\n"; // запись строки в файл
		addString << "Восьмая строчка в файле\n"; // запись строки в файл
		addString << "Девятая строчка в файле\n"; // запись строки в файл
	}

	addString.close();

	//******************************************************

	//Race race;
	//thread WrightThread;
	//thread ReadThread;
	//thread ActionThread;
	//thread RunThread;

	//WrightThread.join();
	//ReadThread.join();
	//ActionThread.join();
	//RunThread.join();

	system("pause");
	return 0;
}
