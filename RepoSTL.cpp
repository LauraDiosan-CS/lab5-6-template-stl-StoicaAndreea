#include"RepoSTL.h"

RepositorySTL::RepositorySTL() {
}

void RepositorySTL::addElem(Car e) {
	//list<int, int>::iterator it;
	elem.push_back(e);
}

int RepositorySTL::getSize() {
	return elem.size();
}

list<Car> RepositorySTL::getAll() {
	return elem;}

RepositorySTL::~RepositorySTL() {
}

int RepositorySTL::findElem(Car e) {
	list<Car>::iterator it;
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

Car RepositorySTL::getItemFromPos(int i) {
	if (elem.size() > i)
	{
		std::list<Car>::iterator it = std::next(elem.begin(), i);
		return  *it;
	}
}
int RepositorySTL::deleteElem(Car e) {
	int i = findElem(e);
	if (i != -1)
	{
		std::list<Car>::iterator it = std::next(elem.begin(), i);
		elem.erase(it);
		return 0;
	}
	return -1;

}

void RepositorySTL::updateElem(Car e, const char* na, const char* nu, const char* st) {
	int i = findElem(e);
	if (i != -1) {
		std::list<Car>::iterator it = std::next(elem.begin(), i);
		it->setName(na);
		it->setNumar(nu);
		it->setStatus(st);
	}
}