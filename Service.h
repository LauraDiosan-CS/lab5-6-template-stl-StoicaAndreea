#pragma once
#include"RepoFile.h"
#include "RepoTemplate.h"
#include "Entity.h"
using namespace std;

class Service
{
private:
	int max;
	RepositoryFile repo;
	//RepositoryTemplate repo;
	//RepositoryFile undo[100];
	int psize;
	int maxc;
	int cars;
public:
	Service();
	//Service(const RepoTemplate<Car>&);
	Service(const RepositoryFile&);
	void setRepo(const RepositoryFile&);
	void addCar(Car&);
	int delCar(Car&);
	list<Car> getAll();
	Car updateCar(Car, const char*, const char*, const char*);
	int findElem(Car);
	Car getItemFromPos(int);
	int getSize();
	int size();
	void intrare(Car &);
	void iesire(Car &);
	int maxCars();
	//int undoList();
	~Service();
};



