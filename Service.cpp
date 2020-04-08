#include "Service.h"
//#include <algorithm> 

Service::Service()
{
	//size = 0;
}

Service::Service(const RepositoryFile& r)
{
	repo = r;
	//size = 0;
}

void Service::setRepo(const RepositoryFile& r)
{
	repo = r;
	//size = 0;
}


void Service::addCar(Car& p)
{
	//undo[size++] = repo;
	repo.addElem(p);
	repo.saveToFile();
}

int Service::delCar(Car& p)
{
	if (findOne(p) != -1) {
		//undo[size++] = repo;
		repo.deleteElem(p);
		repo.saveToFile();
		return 0;
	}
	return -1;
}

list<Car> Service::getAll()
{
	return repo.getAll();
}

Car Service::updateCar(Car p, const char* na, const char* nu, const char* st)
{
	//undo[size++] = repo;
	repo.updateElem(p, na,nu, st);
	repo.saveToFile();
	return p;
}

int Service::findOne(Car p)
{
	return repo.findElem(p);
}
Car Service::getItemFromPos(int i) {
	if (i >= 0 and i < repo.getSize())
		return repo.getItemFromPos(i);
	Car p;
	return p;
}

int Service::getSize() {
	return repo.getSize();
}
/*
int Service::undoList() {
	if (size == 0) return 1;
	else
	{
		repo = undo[size - 1];
		size--;
		repo.saveToFile();
		return 0;
	}
}*/
/*
//sorts Cars alphabetically
Car* ServiceSTL::sortByGitPath()
{
	Car all[] = repo.getAll();
	std::sort(all.begin(), all.end());
	return all;
}

bool myProjCompare(Car x, Car y) { return (x.getTotalNoOfCommits() > y.getTotalNoOfCommits()); }


//sorts descending after commits
Car* ServiceSTL::sortByTotalNoOfCommits()
{
	Car all = repo.getAll();
	std::sort(all.begin(), all.end(), myProjCompare);
	return all;
}

Car* ServiceSTL::filterByPathAndCommits(const char* gp, int c)
{
	Car* rez;
	for (int i = 0; i < repo.size(); i++)
	{
		Car* crt = repo.elemAtPos(i);
		if (strstr(crt.getGitPath(), gp) && crt.getTotalNoOfCommits() >= c)
			rez.push_back(crt);
	}
	return rez;
}
*/


Service::~Service()
{
}
