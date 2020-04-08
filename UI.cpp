#include "UI.h"
#include <iostream>
#include<string.h>
using namespace std;

UI::UI(Service& service)
{
	s = service;
}
void UI::addProj() {
	Car proj;
	cout << "Give the Car:";
	cin >> proj;
	try {
		s.addCar(proj);
		cout << "the Car has been successfully added" << endl;
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}



void UI::findProj() {
	Car proj;
	cout << "Give the Car:";
	cin >> proj;
	int rez = s.findOne(proj);
	if (rez >= 0) cout << "The Car has been found!" << endl;
	else cout << "The Car has not been found!" << endl;
}

void UI::delProj() {
	Car proj;
	cout << "Give the Car:" << endl;;
	cin >> proj;
	int rez = s.delCar(proj);
	if (rez == 0) cout << "the Car has been deleted!" << endl;
	else cout << "the Car has not been found!" << endl;
}

void UI::showAll() {
	list <Car>::iterator it;
	for (int i = 0; i<s.getSize();i++)
	{
		cout << s.getItemFromPos(i).getName() << " " << s.getItemFromPos(i).getNumar() << " " << s.getItemFromPos(i).getStatus() << endl;
	}
}
void UI::intra() {
	cout << s.size() << endl;
	//cout << max;
	Car proj;
	cout << "Give the Car:";
	cin >> proj;
	try {
		s.intrare(proj);
	}
	catch (exception e) {
		cout << "exception occuredddd!" << "->"; cout << e.what();
	}

}
/*
void UI::undoProj() {
	int rez = s.undoList();
	if (rez == 0) cout << "The undo was successfull!" << endl;
	else cout << "can't undo" << endl;
}*/
void UI::updateProj() {
	Car proj;
	cout << "Give the Car you want to update:";
	cin >> proj;
	cout << "Give the Car data:" << endl;
	char* na = new char[10];
	char* nr=new char[10];
	char* st=new char[10];
	int rez = s.findOne(proj);
	if (rez >= 0) {
		cout << "name: ";
		cin >> na;
		cout << "plate number: ";
		cin >> nr;
		int ok = 0;
		while (ok == 0) {
			cout << "status: " << endl;
			cout << "			a. free"<<endl;
			cout << "			b.occupied"<<endl;
			cin >> st;
			if ((strcmp(st, "free") == 0) or (strcmp(st, "occupied")==0)) ok = 1;
		}
		s.updateCar(proj, na, nr, st);
		cout << "The Car has been updated!";
	}
	else { cout << "The Car has not been found!"; }
}

void UI::showUI()
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "#####################~~ MENU ~~###################" << endl;
		cout << endl;
		cout << "OPTIONS: " << endl;
		cout << "	1. Add Car " << endl;
		cout << "	2. Search Car " << endl;
		cout << "	3. Delete Car " << endl;
		cout << "	4. Update Car " << endl;
		cout << "	5. Show Cars " << endl;
		cout << "	6. Get in the parking lot" << endl;
		//cout << "	6. UNDO" << endl;
		cout << "	0. EXIT!" << endl;
		cout << "option: (give the number):  ";
		int opt;
		cin >> opt;
		cout << endl;
		cout << endl;
		switch (opt) {
		case 1: {addProj(); break; }
		case 2: {findProj(); break; }
		case 3: {delProj(); break; }
		case 4: {updateProj(); break; }
		case 5: {showAll(); break; }
		case 6: {intra(); break; }
		//case 6: {undoProj(); break; }
		case 0: {gata = true; cout << "BYE BYE..." << endl; }
		}
	}
}
UI::~UI()
{

}
