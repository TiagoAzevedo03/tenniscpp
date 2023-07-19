#include "functions.h"

using namespace std;

Database::Database(){
	sqlite3_open("tennis.db", &db);
}

static int callback_players(void *unused, int n, char **data, char **col){
	for (int i = 0; i < n; i++){
		cout << data[i] << endl;
	}
	return 0;
}
void Database::selectPlayers(){
	sqlite3_exec(db, "SELECT name FROM Player", callback_players, NULL, NULL);
}

void Database::close(){
	sqlite3_close(db);
}
