#include <iostream>
#include "database.hpp"
#include "camera_model.hpp"
#include <sqlite3.h>
int main() {
	Database database("database.db");
	// sqlite3 *db = database.getDatabase();
	CameraModel model(database.getDatabase());
	auto cameras = model.getCameras();
	// std::cout << cameras[0].user;
}
