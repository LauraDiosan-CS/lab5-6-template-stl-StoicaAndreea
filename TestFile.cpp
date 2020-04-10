#include "TestFile.h"
#include <assert.h> 
#include <iostream>


TestRepositoryFile::TestRepositoryFile()
{

	assert(repo.getSize() == 0);
}

void TestRepositoryFile::testLoadFromFile()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.getSize() == 4);
}

void TestRepositoryFile::testAddElem()
{
	repo.loadFromFile("TestProj.txt");
	repo.addElem(Car("aaa","bbb","free"));
	assert(repo.getSize() == 5);
	repo.saveToFile();
}

void TestRepositoryFile::testFindElem()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.findElem(Car("aaa", "bbb", "free")) == 4);
	assert(repo.findElem(Car("abc", "aaa", "free")) == -1);
	repo.saveToFile();
}

void TestRepositoryFile::testDelElem()
{
	repo.loadFromFile("TestProj.txt");
	repo.deleteElem(Car("aaa", "bbb", "free"));
	assert(repo.getSize() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testGetAll()
{
	repo.loadFromFile("TestProj.txt");
	list<Car> rez = repo.getAll();
	assert(rez.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testUpdateElem()
{
	repo.loadFromFile("TestProj.txt");
	repo.updateElem(Car("bbb", "aaa", "free"), "abc", "aaa", "free");
	assert(repo.findElem(Car("abc", "aaa", "free")) == 0);
	repo.saveToFile();
}

void TestRepositoryFile::testElemAtPos()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.getItemFromPos(0) == Car("abc", "aaa", "free"));
	repo.saveToFile();
}

void TestRepositoryFile::testSize()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.getSize() == 4);
}

void TestRepositoryFile::testSaveToFile()
{
	repo.loadFromFile("TestProj.txt");
	int n = repo.getSize();
	repo.addElem(Car("aaa", "aaa", "free"));
	repo.saveToFile();
	repo.loadFromFile("TestProj.txt");
	assert(repo.getAll().size() == (n + 1));

}


TestRepositoryFile::~TestRepositoryFile()
{
}
