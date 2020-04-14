#include"RepoFile.h"
//#include<iostream>
//#include <fstream>
//#include <cstddef>
//#include <string>
//using namespace std;
//
//template<class T>
//RepositoryFile<T>::RepositoryFile():RepositoryTemplate<Car>()
//{
//	fis = "";
//}
//template<class T>
//RepositoryFile<T>::RepositoryFile(const char* fileName)
//{
//	fis = fileName;
//	ifstream f(fileName);
//	string linie;
//	char* name = new char[10];
//	char* numar=new char[10];
//	char* status=new char[10];
//	while (!f.eof()) {
//		f >> name >> numar >> status;
//		if (name != "") {
//			Car e(name, numar, status);
//			//elem.push_back(e);
//			RepositoryTemplate::addElem(e);
//
//		}
//	}
//	delete[] name;
//	delete[] numar;
//	delete[] status;
//	f.close();
//}
//
//template<class T>
//void RepositoryFile<T>::loadFromFile(const char* fileName)
//{
//	//elem.clear();
//	RepositoryTemplate::clearElem();
//	fis = fileName;
//	ifstream f(fileName);
//	char* name = new char[10];
//	char* numar = new char[10];
//	char* status = new char[10];
//	while (!f.eof()) 
//	{
//		f >> name >> numar >> status;
//		if (strcmp(name, "") != 0)
//		{
//			Car e(name, numar, status);
//			//elem.push_back(e);
//			RepositoryTemplate::addElem(e);
//		}
//	}
//	delete[] name;
//	delete[] numar;
//	delete[] status;
//	f.close();
//}
//
//template<class T>
//void RepositoryFile<T>::saveToFile()
//	{
//		ofstream f(fis);
//		list<Car>::iterator it;
//		list<Car>elem = RepositoryTemplate::getAll();
//		for (it = elem.begin(); it != elem.end(); ++it)
//		{
//			f << *it;
//		}
//		f.close();
//	}
//
//template<class T>
//RepositoryFile<T>::~RepositoryFile()
//{
//
//}
//
//template<class T>
//int RepositoryFile<T>::addElem(const T& e) {
//	int r= RepositoryTemplate::addElem(e);
//	if (r != 0) {
//		saveToFile();
//		return 1;
//	}
//	return 0;
//}
//
//template<class T>
//int RepositoryFile<T>::deleteElem(const T& e) {
//	int r = RepositoryTemplate::deleteElem(e);
//	if (r != 0) {
//		return 0;
//		saveToFile();
//	}
//	else
//		return -1;
//}
//template<class T>
//void RepositoryFile<T>::updateElem(const T& e, const T n)
//{
//	RepositoryTemplate::updateElem(e, n);
//	saveToFile();
//}