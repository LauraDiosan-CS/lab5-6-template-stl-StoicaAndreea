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
	//std::list<Car>::iterator it = rep.getAll().begin();
	assert(rep.getAll().front() == e1);
	assert(rep.getAll().back() == e4);
}
Tests::~Tests() {
}