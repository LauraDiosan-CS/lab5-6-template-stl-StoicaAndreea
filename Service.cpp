#include "Service.h"
//#include <algorithm> 

Service::Service()
{
	max = 3;
	psize = 0;
	maxc = 0;
	cars = 0;
}

Service::Service(const RepositoryFile& r)
{
	max = 3;
	repo = r;
	psize = 0;
	maxc = 0;
	cars = 0;
}

void Service::setRepo(const RepositoryFile& r)
{
	repo = r;
	psize = 0;
	cars = 0;
}


void Service::addCar(Car& p)
{
	//undo[size++] = repo;
	list<Car> el;
	el = repo.getAll();
	list<Car>::iterator it;
	for (it = el.begin(); it != el.end(); ++it) {
		if (strcmp((*it).getNumar(), p.getNumar()) == 0) {
			throw exception("duplicate car");
		}
	}
	repo.addElem(p);
	repo.saveToFile();
}

int Service::delCar(Car& p)
{
	if (findElem(p) == -1) {
		throw exception("the car does not exist");
	}
		//undo[size++] = repo;
	else{
		if (strcmp(p.getStatus(), "occupied")==0){ throw exception("cannot delete a car from the parking lot"); }
		else {
			repo.deleteElem(p);
			repo.saveToFile();
			return 0;
		}
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

int Service::findElem(Car p)
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
int Service::size() {
	psize = 0;
	list<Car> el;
	el = repo.getAll();
	list<Car>::iterator it;
	for (it = el.begin(); it != el.end(); ++it) {
		if (strcmp((*it).getStatus(), "occupied")==0) {
			psize++;
		}
	}
	return psize;
}
void Service::intrare(Car & c) {
	list<Car> el;
	el = repo.getAll();
	list<Car>::iterator it;
	int ok = 0;
	for (it = el.begin(); it != el.end(); ++it) 
	{
		if (strcmp((*it).getNumar(), c.getNumar()) == 0) 
		{
			ok++;
		}
	}
	if (ok == 0) {
		throw exception("car not found in repo");
	}
	if (strcmp(c.getStatus(), "occupied") == 0) {
		throw exception("cannot enter the parking lot because the car is in the parking lot");
	}
	psize =size();
	if (max == psize){
		cars++;
		throw exception("cannot enter the parking lot because it is full"); }
	
	repo.updateElem(c, c.getName(), c.getNumar(), "occupied");
	repo.saveToFile();
}

void Service::iesire(Car& c) {
	list<Car> el;
	el = repo.getAll();
	list<Car>::iterator it;
	int ok = 0;
	for (it = el.begin(); it != el.end(); ++it)
	{
		if (strcmp((*it).getNumar(),c.getNumar()) == 0)
		{
			ok++;
		}
	}
	if (ok == 0) {
		throw exception("car not found in repo");
	}
	if (strcmp(c.getStatus(), "free") == 0) {
		throw exception("cannot exit the parking lot because the car is not in the parking lot");
	}
	if (cars > maxc) { maxc = cars; }
	cars=0;
	repo.updateElem(c, c.getName(), c.getNumar(), "free");
	repo.saveToFile();
}
int Service::maxCars() {
	return maxc;
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
