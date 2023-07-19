#include "menu.h"

using namespace std;

Menu::Menu(){}

void Menu::runMenu(){
	int option;
	
	while (true){
		cout << "0. Exit" << endl;
		cout << "1. Insert data" << endl;
		cout << "2. Search data" << endl;
		
		cout << "Choose an option: ";
		cin >> option;
		
		switch(option){
			case 0: 
				exit(0);
				break;
			case 1:
				menuInsert();
				break;
			case 2:
				menuSelect();
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}
}

void Menu::menuInsert(){
	int option = -1;
	Database db;
	
	while (option != 0){
		cout << "0. Back" << endl;
		
		cout << "Choose an option: ";
		cin >> option;
		
		switch(option){
			case 0: 
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}
}

void Menu::menuSelect(){
	int option = -1;
	Database db;
	
	while (option != 0){
		cout << "0. Back" << endl;
		cout << "1. Select players" << endl;
		
		cout << "Choose an option: ";
		cin >> option;
		
		switch(option){
			case 0: 
				break;
			case 1:
				db.selectPlayers();
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}
}
