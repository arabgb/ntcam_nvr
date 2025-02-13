#include "database.hpp"
#include "interfaces/camera_interface.hpp"
#include <vector>
#include <optional>
class CameraModel {
	public:
		CameraModel(sqlite3 *db);
		std::vector<CameraInterface> getCameras(int motion=-1);
		std::optional<CameraInterface> getCamera(int id);
	private:
		sqlite3 *db;
};
