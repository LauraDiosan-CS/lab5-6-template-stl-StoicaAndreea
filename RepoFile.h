#pragma once
#include "Entity.h"
#include <list>
#include "RepoSTL.h"
using namespace std;

class RepositoryFile: public RepositorySTL
{
private:
	//list<Car>elem;
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void saveToFile();
	//void addElem(Car);
	//void updateElem(Car, const char*, const char*, const char*);
	//int findElem(Car);
	//int deleteElem(Car);
	//Car getItemFromPos(int);
	//list<Car> getAll();
	//int getSize();
	~RepositoryFile();
};


