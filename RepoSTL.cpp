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
/*
bool RepositorySTL::findElem(int nr) {
	list<Car>::iterator it;
	it = elem[nr];
	if (it != elem.end()) return true;
	return false;
}*/
/*
Car RepositorySTL::getItemFromPos(int i) {
	list<Car>::iterator it;
	it = elem.find(i);
	return it;
}
*/