#pragma once
#include"RepoFile.h"
#include "RepoTemplate.h"
#include "Entity.h"
using namespace std;

class Service
{
private:
	//RepositoryFile repo;
	RepositoryTemplate<Car> &repo;
	//RepositoryFile undo[100];
	int psize;
	int maxc;
	int cars;
public:
	int max;
	//Service();
	//Service(const RepoTemplate<Car>&);
	Service(RepositoryTemplate<Car>& r) :repo(r) { repo = r; max = 3;psize = 0;maxc = 0;cars = 0; };
	//void setRepo(const RepositoryTemplate<Car>&);
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
	void setMax(int);
	//int undoList();
	~Service();
};



