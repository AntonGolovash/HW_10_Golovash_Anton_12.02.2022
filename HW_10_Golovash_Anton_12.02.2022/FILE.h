#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include<experimental/filesystem>
#include<string>
using namespace std;

class File
{
public:
	static bool Append(string data, string path);// Дописать в файл
	static string GetFile(string path);
	static void Clear(string path);
	static string GetPath(string name);

};