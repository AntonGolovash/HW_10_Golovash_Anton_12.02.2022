#include "File.h"

bool File::Append(string data, string path)
{
	if (path.empty())
	{
		ofstream file(path, ios::app);// append
		file << data;
		file.close();
		return true;
	}
	cerr << "Error File:\t" << path << endl;
	return false;
}

string File::GetFile(string path)// возврат данных из файла
{
	ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		cerr << "Error open file:\t" << path << endl;
		return "";
	}
	string result(istreambuf_iterator<char>{file}, istreambuf_iterator<char>{});
	return result;
}

void File::Clear(string path)
{
	ifstream file;
	file.open(path, ofstream::out | ofstream::trunc);
	if (!file.is_open())
	{
		cerr << "Error open file:\t" << path << endl;
		return;
	}
	file.close();
}

string File::GetPath(string name)
{
	return experimental::filesystem::absolute(name).generic_string();
}
