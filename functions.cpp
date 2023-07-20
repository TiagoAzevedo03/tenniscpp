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
	sqlite3_exec(db, "SELECT name FROM Player WHERE nacionality LIKE 'Portugal'", callback_players, 0, 0);
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
	
	string test = "SELECT name FROM Player WHERE nacionality LIKE '" + country + "' AND date LIKE '" + date + "' AND name LIKE '" + name + "'";
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
	for (int i = 0; i < n; i += 3){
		string id, name, country;
		id = data[0];
		name = data[1];
		country = data[2];
		cout << id << ". " << name << " - " << country << endl;
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
	
	string statement = "SELECT id, name, nacionality FROM Player WHERE name LIKE '%" + name + "%'";
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
    
    statement = "SELECT * FROM Player WHERE id = " + id + " AND name LIKE '%" + name + "%'";
    status = sqlite3_exec(db, statement.c_str(), check_id, 0, 0);
	
	if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    
    statement = "DELETE FROM Player WHERE id = " + id + " AND name LIKE '%" + name + "%'";
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
	string statement = "SELECT id, date, (SELECT name FROM player WHERE id = idPlayer1), (SELECT name FROM player WHERE id = idPlayer2) FROM match WHERE result IS NULL ORDER BY match.date ASC";
	sqlite3_exec(db, statement.c_str(), notfinished, 0, 0);
	
	cout << "Select the id of the match you want to update the result: ";
	string id; cin >> id;
	
	statement = "SELECT id FROM match WHERE id = " + id + " AND result IS NULL";
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
		statement = "SELECT (SELECT name FROM player WHERE id = idPlayer1), (SELECT name FROM player WHERE id = idPlayer2) FROM match WHERE id = " + id;
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

static int edition(void *unused, int n, char **data, char **col){
	for (int i = 0; i < n; i += 3){
		string id = data[0];
		string year = data[1];
		string comp = data[2];
		cout << id << ". " << comp << " - " << year << endl;
	}
	return 0;
}

bool Database::insertMatch(){
	int status = sqlite3_exec(db, "SELECT id, year, (SELECT name FROM competition WHERE competition.id = idCompetition) FROM Edition", edition, 0, 0);
	if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
	cout << "For which tournament is this match? ";
	string id; cin >> id;
	
	cout << "Insert the name of the first player: ";
	string name; 
	cin.ignore();
	getline(cin, name);
	
	string statement = "SELECT id, name, nacionality FROM Player WHERE name LIKE '%" + name + "%'";
	sqlite3_exec(db, statement.c_str(), callback_delete, 0, 0);
	
	cout << "Select the id of the first player: ";
	string p1; cin >> p1;
	
	cout << "Insert the name of the second player: ";
	cin.ignore();
	getline(cin, name);
	
	statement = "SELECT id, name, nacionality FROM Player WHERE name LIKE '%" + name + "%'";
	sqlite3_exec(db, statement.c_str(), callback_delete, 0, 0);
	
	cout << "Select the id of the second player: ";
	string p2; cin >> p2;
	
	cout << "Insert the date of the game (format yyyy-mm-dd hh:mm:ss): ";
	string date; cin.ignore();
	getline (cin, date);
	
	statement = "INSERT INTO Match (idPlayer1, idPlayer2, idEdition, date) VALUES ('" + p1 + "', '" + p2 + "', '" + id + "', '" + date + "')";
	status = sqlite3_exec(db, statement.c_str(), 0, 0, 0);
	
	if (status != SQLITE_OK) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    
    cout << "Match inserted!" << endl;
    return true;
}



void Database::close(){
	sqlite3_close(db);
}
