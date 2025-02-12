#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
	public:
		Database(const std::string& db_name);
		~Database();
		sqlite3 *getDatabase() const;
	private:
		void CreateTables();
		bool execute(const std::string& sql);
		sqlite3 *db;
};

#endif
