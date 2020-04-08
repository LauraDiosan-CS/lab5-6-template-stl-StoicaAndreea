#pragma once
#include"RepoFile.h"
#include "RepoSTL.h"
#include "Entity.h"
using namespace std;

class Service
{
private:
	RepositoryFile repo;
	//RepositorySTL repo;
	//RepositoryFile undo[100];
	//int size = 0;
public:
	Service();
	Service(const RepositoryFile&);
	void setRepo(const RepositoryFile&);
	void addCar(Car&);
	int delCar(Car&);
	list<Car> getAll();
	Car updateCar(Car, const char*, const char*, const char*);
	int findOne(Car);
	Car getItemFromPos(int);
	int getSize();
	//int undoList();
	~Service();
};



