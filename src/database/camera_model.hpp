#include "database.hpp"
#include "interfaces/camera_interface.hpp"
#include <vector>
class CameraModel {
	public:
		CameraModel(sqlite3 *db);
		std::vector<CameraInterface> getCameras(int motion=-1);
		CameraInterface getCamera(int id);
	private:
		sqlite3 *db;
};
