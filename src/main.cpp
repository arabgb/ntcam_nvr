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
	for (int i=0; i < cameras.size(); i++)
	{
		std::cout << cameras[i].id << ": " << cameras[i].description << std::endl;
	}
	std::cout << "Getting camera of id 3" << std::endl;
	auto camera = model.getCamera(3);
	if (camera.has_value()) {
		std::cout << camera->description << std::endl;
	}
	else {
		std::cout << "Cannot find the camera!" << std::endl;
	}
}
