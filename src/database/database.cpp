#include "database.hpp"
#include <iostream>
#include <string>

Database::Database(std::string db_name) {
	std::cout << "Openning database " << db_name << std::endl;
}
