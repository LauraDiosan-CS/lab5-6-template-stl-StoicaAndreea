#pragma once
#include"RepoSTL.h"
#include"Service.h"
class Tests {
private:
	RepositoryFile repof;
	RepositorySTL repo;
	Service serv;
public:
	Tests();
	void testDomain();
	void testRepoSTL();
	void testService();
	~Tests();
};