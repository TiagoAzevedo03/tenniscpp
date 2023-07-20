#ifndef FUNCTIONS_MENU_H
#define FUNCTIONS_MENU_H

#include "sqlite3.h"
#include <iostream>

class Database {
	public:
		Database();
		bool selectPlayer();
		void close();
		bool insertPlayer();
		bool checkDate(std::string date);
		bool deletePlayer();
		bool updateMatch();
		bool insertMatch();
		bool insertTournament();
		bool matchesPlayer();
		bool matchesComp();
		bool compPlayers();
	private:
		sqlite3 *db;
};

#endif
