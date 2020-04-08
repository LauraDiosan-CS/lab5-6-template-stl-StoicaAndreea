#pragma once
#include"Entity.h"
#include<list>
#include<iterator>
using namespace std;

class RepositorySTL {
protected:
	list<Car> elem;
public:
	RepositorySTL();
	void addElem(Car);
	int findElem(Car);
	int deleteElem(Car);
	void updateElem(Car, const char*, const char*, const char*);
	Car getItemFromPos(int);
	list<Car>getAll();
	int getSize();
	~RepositorySTL();
};