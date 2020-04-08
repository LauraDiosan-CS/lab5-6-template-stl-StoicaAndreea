#pragma once
#include "RepoFile.h"
class TestRepositoryFile
{
private:
	RepositoryFile repo;
public:
	TestRepositoryFile();
	void testLoadFromFile();
	void testAddElem();
	void testFindElem();
	void testDelElem();
	void testGetAll();
	void testUpdateElem();
	void testElemAtPos();
	void testSize();
	void testSaveToFile();
	~TestRepositoryFile();
};


