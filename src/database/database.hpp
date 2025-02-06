#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
	public:
		Database(const std::string& db_name);
		~Database();
	private:
		sqlite3 *db;
		void CreateTables();
		bool execute(const std::string& sql);
};

#endif
