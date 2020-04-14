#pragma once
#include <list>
#include <iostream>
#include<fstream>
#include "Entity.h"
#include "RepoTemplate.h"
using namespace std;


template<class T>class RepositoryFile :public RepositoryTemplate<Car>
{
private:
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	int addElem(const T&);
	int deleteElem(const T&);
	void updateElem(const T&, const T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<Car>()
{
	fis = "";
}
template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName)
{
	loadFromFile(fileName);
	//RepositoryTemplate::clearElem();
	//fis = fileName;
	//ifstream f(fileName);
	//string linie;
	//char* name = new char[10];
	//char* numar = new char[10];
	//char* status = new char[10];
	//while (!f.eof()) {
	//	f >> name >> numar >> status;
	//	if (name != "") {
	//		Car e(name, numar, status);
	//		//elem.push_back(e);
	//		RepositoryTemplate::addElem(e);

	//	}
	//}
	//delete[] name;
	//delete[] numar;
	//delete[] status;
	//f.close();
}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName)
{
	//elem.clear();
	RepositoryTemplate::clearElem();
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
			//elem.push_back(e);
			RepositoryTemplate::addElem(e);
		}
	}
	delete[] name;
	delete[] numar;
	delete[] status;
	f.close();
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	ofstream f(fis);
	list<Car>::iterator it;
	list<Car>elem = RepositoryTemplate::getAll();
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		f << *it;
	}
	f.close();
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{

}

template<class T>
int RepositoryFile<T>::addElem(const T& e) {
	int r = RepositoryTemplate::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryFile<T>::deleteElem(const T& e) {
	int r = RepositoryTemplate::deleteElem(e);
	if (r != 0) {
		saveToFile();
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepositoryFile<T>::updateElem(const T& e, const T n)
{
	RepositoryTemplate::updateElem(e, n);
	saveToFile();
}
//#pragma once
//#include "Entity.h"
//#include <list>
//#include "RepoSTL.h"
//using namespace std;
//
//class RepositoryFile: public RepositorySTL
//{
//private:
//	//list<Car>elem;
//	const char* fis;
//public:
//	RepositoryFile();
//	RepositoryFile(const char* fileName);
//	void loadFromFile(const char* fileName);
//	void saveToFile();
//	//void addElem(Car);
//	//void updateElem(Car, const char*, const char*, const char*);
//	//int findElem(Car);
//	//int deleteElem(Car);
//	//Car getItemFromPos(int);
//	//list<Car> getAll();
//	//int getSize();
//	~RepositoryFile();
//};

