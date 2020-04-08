#include "Tests.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
using namespace std;

Tests::Tests() {
}

void Tests::testDomain() {
	Car e1("pppp", "MS 74 SSC","liber");
	Car e2(e1);
	Car e3;
	assert(e3.getName()==NULL);
	assert(e3.getNumar() == NULL);
	assert(e3.getStatus() == NULL);
	e3 = e2;
	assert(strcmp(e3.getName(), "pppp") == 0);
	assert(strcmp(e2.getName(), "pppp") == 0);
	assert(e1 == e2);
	e2.setNumar("MS 74 AAA");
	assert(strcmp(e2.getNumar(), "MS 74 AAA") == 0);
}

void Tests::testRepoSTL() {
	Car e1("aaa", "MS 74 SSC","liber");
	Car e2("bbb", "MS 75 SSC","ocupat");
	Car e3("ccc", "MS 76 SSC", "liber");
	Car e4("ddd", "MS 77 SSC", "ocupat");
	RepositorySTL rep;
	rep.addElem(e1);
	rep.addElem(e2);
	rep.addElem(e3);
	rep.addElem(e4);   
	assert(rep.getSize() == 4);
	assert(rep.getAll().front() == e1);
	assert(rep.getAll().back() == e4);
	assert(rep.getItemFromPos(0) == e1);
	Car carsArray[] = { e1,e2,e3,e4 };
	list <Car> cars;
	cars = rep.getAll();
	list <Car>::iterator it;
	int i = 0;
	for (it = cars.begin(); it != cars.end() and i < 4; ++it)
	{
		assert(*it == carsArray[i]);
		//cout << carsArray[i].getName();
		i++;

	}
	Car e0("eee", "MS 77 SSA", "ocupat");
	Car e01("bbb", "aaa", "liber");
	assert(rep.findElem(e4) == 3);
	assert(rep.findElem(e0) == -1);
	rep.deleteElem(e3);
	assert(rep.findElem(e3) == -1);
	assert(rep.getSize() == 3);
	rep.updateElem(e1, "bbb", "aaa", "liber");
	assert(rep.getItemFromPos(0) == e01);
}

void Tests::testService() {
	repof.loadFromFile("servTest.txt");
	Service serv(repof);
	Car e1("aaa", "MS 74 SSC", "liber");
	Car e2("bbb", "MS 75 SSC", "ocupat");
	Car e3("ccc", "MS 76 SSC", "liber");
	Car e4("ddd", "MS 77 SSC", "ocupat");
	Car e0("eee", "MS 77 SSA", "ocupat");
	Car e01("bbb", "aaa", "liber");
	serv.addCar(e1);
	serv.addCar(e2);
	serv.addCar(e3);
	serv.addCar(e4);
	serv.addCar(e0);
	assert(serv.getSize() == 5);
	assert(serv.getItemFromPos(0) == e1);
	assert(serv.findOne(e2) == 1);
	int n = serv.delCar(e0);
	assert(serv.findOne(e0) == -1);
	serv.updateCar(e1, "aha", "aaa", "liber");
	assert(strcmp(serv.getItemFromPos(0).getName(), "aha") == 0);
	//serv.undoList();
	//assert(strcmp(serv.getItemFromPos(0).getName(), "aaa") == 0);
	//serv.undoList();
	//assert(serv.findOne(e0) == 4);
}
Tests::~Tests() {
}