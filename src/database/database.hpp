#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
	public:
		Database(const std::string& db_name);
		~Database();
	private:
		void CreateTables();
		bool execute(const std::string& sql);
	protected:
		sqlite3 *db;
};

#endif
