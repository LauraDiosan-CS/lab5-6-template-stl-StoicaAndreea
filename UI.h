#pragma once
#include "Service.h"
class UI {
private:
	Service s;
public:
	UI(Service& serv) : s(serv) {};
	void addProj();
	void findProj();
	void showUI();
	void delProj();
	void showAll();
	//void undoProj();
	void updateProj();
	void intra();
	void iesi();
	void set();
	~UI();
};