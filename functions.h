#ifndef FUNCTIONS_MENU_H
#define FUNCTIONS_MENU_H

#include "sqlite3.h"
#include <iostream>

class Database {
	public:
		Database();
		void selectPlayers();
		void close();
	private:
		sqlite3 *db;
};

#endif
