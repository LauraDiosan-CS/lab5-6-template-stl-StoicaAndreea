#include"Tests.h"
#include"RepoSTL.h"
#include"Service.h"
#include"UI.h"
#include"Tests.h"
int main() {
	cout << "start" << endl;
	Tests test;
	test.testDomain();
	test.testRepoSTL();
	cout << "succes" << endl;

	return 0;
}
