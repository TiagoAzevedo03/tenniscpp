#include "menu.h"

using namespace std;

Menu::Menu(){}

void Menu::runMenu(){
	int option;
	
	while (true){
		cout << "0. Exit" << endl;
		cout << "1. Edit data" << endl;
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
		cout << "1. Insert player" << endl;
		cout << "2. Insert match" << endl;
		cout << "3. Update match" << endl;
		cout << "4. Insert tournament" << endl;
		cout << "5. Delete player" << endl;
		cout << "Choose an option: ";
		cin >> option;
		
		switch(option){
			case 0: 
				break;
			case 1:
				db.insertPlayer();
				break;
			case 2:
				db.insertMatch();
				break;
			case 3:
				db.updateMatch();
				break;
			case 4:
				db.insertTournament();
				break;
			case 5:
				db.deletePlayer();
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
		cout << "1. Player profile" << endl;
		cout << "2. Select players from tournament" << endl;
		cout << "3. Select matches from player" << endl;
		cout << "4. Select matches from tournament" << endl;
		cout << "Choose an option: ";
		cin >> option;
		
		switch(option){
			case 0: 
				break;
			case 1:
				db.selectPlayer();
				break;
			case 2:
				db.compPlayers();
				break;
			case 3:
				db.matchesPlayer();
				break;
			case 4:
				db.matchesComp();
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}
}
