#include "database.hpp"
#include "schema.hpp"
#include <iostream>
#include <string>

Database::Database(const std::string &db_name) : db(nullptr) {
  std::cout << "Openning database " << db_name << std::endl;
  if (sqlite3_open(db_name.c_str(), &db) != SQLITE_OK) {
    std::cerr << " Cannot open/create database file" << std::endl;
  }

  else {
    // create tables if not exisit
    Database::CreateTables();
  }
}

Database::~Database() {
  if (db) {
    sqlite3_close(db);
  }
}

void Database::CreateTables() {
	Schema schema;
	// creating all tables;
	Database::execute(schema.getCamerasTable());
	Database::execute(schema.getSettingsTable());
	Database::execute(schema.getMotionPositionsTable());
	Database::execute(schema.getPositionPoints());
	Database::execute(schema.getRecordingTable());
}

bool Database::execute(const std::string &sql) {
  char *errMsg = nullptr;
  if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
    std::cerr << "SQL error: " << errMsg << std::endl;
  }
  return true;
}
