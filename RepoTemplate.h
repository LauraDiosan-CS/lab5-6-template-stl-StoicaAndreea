//#pragma once
//#include"Entity.h"
//#include<list>
//#include<iterator>
//using namespace std;
//
//class RepositorySTL {
//protected:
//	list<Car> elem;
//public:
//	RepositorySTL();
//	void addElem(Car);
//	int findElem(Car);
//	int deleteElem(Car);
//	void updateElem(Car, const char*, const char*, const char*);
//	Car getItemFromPos(int);
//	list<Car>getAll();
//	int getSize();
//	~RepositorySTL();
//};
#pragma once
#include"Entity.h"
#include<iterator>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>class RepositoryTemplate {
protected:
	list<T> elem;
public:
	RepositoryTemplate<T>() {}
	int addElem(const T&);
	int deleteElem(const T&);
	int findElem(const T&);
	int getSize();
	void updateElem(const T& s, const T nou);
	list<T> getAll();
	T getItemFromPos(int);
	~RepositoryTemplate();
};





template<class T>
int RepositoryTemplate<T>::addElem(const T& e)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it == elem.end())
	{
		elem.push_back(e);
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::deleteElem(const T& e)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::findElem(const T& e)
{
	typename list<T>::iterator it;
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

template<class T>
int RepositoryTemplate<T>::getSize()
{
	return elem.size();
	return 0;
}

template<class T>
void RepositoryTemplate<T>::updateElem(const T& vechi, const T nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);

}

template<class T>
list<T> RepositoryTemplate<T>::getAll()
{
	return elem;
	return list<T>();
}

template<class T>
T RepositoryTemplate<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
}

template <class T> RepositoryTemplate<T>::~RepositoryTemplate()
{
}