#include "functions.h"

using namespace std;

bool exists = false;

Database::Database(){
	sqlite3_open("tennis.db", &db);
}


static int callback_players(void *unused, int n, char **data, char **col){
	for (int i = 0; i < n; i++){
		cout << data[i] << endl;
	}
	return 0;
}

void Database::selectPlayers(){ //funcao de testes
	sqlite3_exec(db, "SELECT name FROM Player where nacionality like 'Portugal'", callback_players, 0, 0);
}


static int checkExists(void *unused, int n, char **data, char **col){
	if (n > 0) exists = true;
	return 0;
}

bool Database::checkDate(string date){
	return date[2] == '-' && date[5] == '-';
}

bool Database::insertPlayer(){
	string name, country, date;
	cout << "Insert the player name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Insert the country: ";
	cin >> country;
	cout << "Insert the date of birth (format dd-mm-yyyy): ";
	cin >> date;
	
	while (!checkDate(date)){
		cout << "Invalid format." << endl << "Insert a valid date (dd-mm-yyyy) :";
		cin >> date;
	}
	
	string test = "SELECT name FROM Player where nacionality like '" + country + "' and date like '" + date + "' and name like '" + name + "'";
	sqlite3_exec(db, test.c_str(), checkExists, 0, 0);
	if (exists){
		cout << "Player already exists in the database" << endl;
		return false;
	}
	
	string statement = "INSERT INTO Player (name, date, nacionality) VALUES ('" + name + "', '" + date + "', '" + country + "')";
	int status = sqlite3_exec(db, statement.c_str(), 0, 0, 0);
	
	if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    
    cout << "Player inserted!" << endl;
    return true;
}





void Database::close(){
	sqlite3_close(db);
}
