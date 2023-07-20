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

static int callback_delete(void *unused, int n, char **data, char **col){
	if (n > 0) exists = true;
	for (int i = 0; i < n; i++){
		cout << col[i] << " : " << data[i] << endl;
		if (col[i] == "nacionality") cout << endl; //.........................................................................resolver
	}
	return 0;
}

static int check_id(void *unused, int n, char **data, char **col){
	if (n == 1) exists = true;
	return 0;
}

bool Database::deletePlayer(){
	string name;
	cout << "Insert the name of the player you want to delete: ";
	cin.ignore();
	getline(cin, name);
	
	string statement = "SELECT * FROM Player WHERE name LIKE '%" + name + "%'";
	int status = sqlite3_exec(db, statement.c_str(), callback_delete, 0, 0);
	
	if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    
    if (!exists){
		cout << "No players found" << endl;
    	return false;
    }
    exists = false;
    
    string id;
    cout << "Choose the id of the player you want to delete: ";
    cin >> id;
    
    statement = "SELECT * FROM Player WHERE id = " + id + " and name LIKE '%" + name + "%'";
    status = sqlite3_exec(db, statement.c_str(), check_id, 0, 0);
	
	if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    
    statement = "DELETE FROM Player WHERE id = " + id + " and name LIKE '%" + name + "%'";
    status = sqlite3_exec(db, statement.c_str(), 0, 0, 0);
    
    if (!exists){
    	cout << "Invalid id" << endl;
    	return false;
	}
    
    if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    cout << "Player deleted!" << endl;
    return true;
}

static int notfinished(void *unused, int n, char **data, char **col){
	for (int i = 0; i < n; i += 4){
		string id = data[0];
		string date = data[1];
		string p1 = data[2];
		string p2 = data[3];
		cout << "id " << id << ": " << p1 << " - " << p2 << endl << date << endl;
	}
	return 0;
}

static int players_name(void *unused, int n, char **data, char **col){
	for (int i = 0; i < n; i += 2){
		string p1 = data[0];
		string p2 = data[1];
		cout << "1. " << p1 << endl << "2. " << p2 << endl;
	}
	return 0;
}

bool Database::updateMatch(){
	string statement = "select id, date, (select name from player where id = idPlayer1), (select name from player where id = idPlayer2) from match where result is null order by match.date asc";
	sqlite3_exec(db, statement.c_str(), notfinished, 0, 0);
	
	cout << "Select the id of the match you want to update the result: ";
	string id; cin >> id;
	
	statement = "select id from match where id = " + id + " and result is null";
	sqlite3_exec(db, statement.c_str(), check_id, 0, 0);
	
	if (!exists){
		cout << "Invalid id" << endl;
		return false;
	}
	
	cout << "1. Cancelled" << endl;
	cout << "2. Surrender" << endl;
	cout << "3. Finished" << endl;
	cout << "Choose an option: ";
	int option; cin >> option;
	string result;
	
	if (option == 1){
		result = "Cancelled";
	}
	else if (option == 2){
		statement = "select (select name from player where id = idPlayer1), (select name from player where id = idPlayer2) from match where id = " + id;
		sqlite3_exec(db, statement.c_str(), players_name, 0, 0);
		cout << "Which player surrendered? ";
		int op2; cin >> op2;
		if(op2 == 1){
			result = "S1";
		}
		else result = "S2";
	}		
	else if (option == 3){
		cout << "Insert the result (format p1-p2): ";
		cin >> result;
	}
	else {
		cout << "Invalid option" << endl;
	}
	
	cout << result << endl;
	
	statement = "UPDATE Match SET result = '" + result + "' WHERE id = " + id;
	sqlite3_exec(db, statement.c_str(), 0, 0, 0);
	
	cout << "Match updated!" << endl;
	
	return true;
}



void Database::close(){
	sqlite3_close(db);
}
