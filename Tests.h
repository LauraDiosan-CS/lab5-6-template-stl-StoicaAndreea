#pragma once
#include"RepoTemplate.h"
#include"Service.h"
class Tests {
private:
	RepositoryFile repof;
	RepositoryTemplate<Car> repo;
	Service serv;
public:
	Tests();
	void testDomain();
	void testRepoTemplate();
	void testService();
	~Tests();
};