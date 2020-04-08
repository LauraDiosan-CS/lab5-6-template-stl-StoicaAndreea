#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;

RepositoryFile::RepositoryFile():RepositorySTL()
{
	fis = "";
}

RepositoryFile::RepositoryFile(const char* fileName) : RepositorySTL()
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* name = new char[10];
	char* numar=new char[10];
	char* status=new char[10];
	while (!f.eof()) {
		f >> name >> numar >> status;
		if (name != "") {
			Car e(name, numar, status);
			//elem.push_back(e);
			elem.push_back(e);
		}
	}
	delete[] name;
	delete[] numar;
	delete[] status;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	char* numar = new char[10];
	char* status = new char[10];
	while (!f.eof()) 
	{
		f >> name >> numar >> status;
		if (strcmp(name, "") != 0)
		{
			Car e(name, numar, status);
			elem.push_back(e);
		}
	}
	delete[] name;
	delete[] numar;
	delete[] status;
	f.close();
}
void RepositoryFile::saveToFile()
	{
		ofstream f(fis);
		list<Car>::iterator it;
		for (it = elem.begin(); it != elem.end(); ++it)
		{
			f << *it;
		}
		f.close();
	}
RepositoryFile::~RepositoryFile()
{

}
/*
void RepositoryFile::addElem(Car e)
{
	elem.push_back(e);
}

void RepositoryFile::updateElem(Car e, const char* na, const char* nu, const char* st)
{
	int i = findElem(e);
	if (i != -1) {
		std::list<Car>::iterator it = std::next(elem.begin(), i);
		it->setName(na);
		it->setNumar(nu);
		it->setStatus(st);

	}

}

int RepositoryFile::findElem(Car e)
{
	list<Car>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if (*it == e)
		{
			return i;
		}
		i++;
	}
	return -1;
}

//sterge elementul e din repository, returneaza 0 la succes, -1 altfel
int RepositoryFile::deleteElem(Car e)
{
	int i = findElem(e);
	if (i != -1)
	{
		std::list<Car>::iterator it = std::next(elem.begin(), i);
		elem.erase(it);
		return 0;
	}
	return -1;
}

Car RepositoryFile::getItemFromPos(int i) {
	if (elem.size() > i)
	{
		std::list<Car>::iterator it = std::next(elem.begin(), i);
		return  *it;
	}
}

list<Car> RepositoryFile::getAll()
{
	return elem;
}

int RepositoryFile::getSize()
{
	return elem.size();
}
*/