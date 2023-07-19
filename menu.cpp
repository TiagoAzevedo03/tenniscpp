#include "menu.h"

using namespace std;

Menu::Menu(){}

void Menu::runMenu(){
	Database db;
	cout << "Welcome!" << endl;
	cout << "1. Insert data" << endl;
	cout << "2. Search data" << endl;
	db.selectPlayers();
	
	db.close();
}
