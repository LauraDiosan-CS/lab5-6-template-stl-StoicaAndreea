#pragma once
#include"Entity.h"
#include<list>
#include<iterator>
using namespace std;

class RepositorySTL {
private:
	list<Car> elem;
public:
	RepositorySTL();
	void addElem(Car);
	//bool findElem(int);
	//void deleteElem(Entity);
	//void updateElem(Entity, const char*, int);
	//Car getItemFromPos(int);
	list<Car>getAll();
	int getSize();
	~RepositorySTL();
};