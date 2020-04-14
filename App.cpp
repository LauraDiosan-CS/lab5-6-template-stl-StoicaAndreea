#include"Tests.h"
#include"RepoTemplate.h"
#include"Service.h"
#include"UI.h"
#include"TestFile.h"
int main() {
	cout << "start" << endl;
	Tests test;
	test.testDomain();
	test.testRepoTemplate();
	test.testService();
	//########repo file tests################
	TestRepositoryFile testf;
	testf.testLoadFromFile();
	testf.testAddElem();
	testf.testFindElem();
	testf.testDelElem();
	testf.testGetAll();
	testf.testUpdateElem();
	testf.testElemAtPos();
	testf.testSize();
	cout << "succes" << endl;
	//RepositoryTemplate<Car> rep;
	RepositoryFile<Car> repo("Elem.txt");
	Service serv(repo);
	UI ui(serv);
	ui.showUI();

	return 0;
}
