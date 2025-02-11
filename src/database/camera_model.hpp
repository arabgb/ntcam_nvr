#include "database.hpp"
#include "interfaces/camera_interface.hpp"
#include <vector>
class CameraModel : private Database {
	public:
		std::vector<CameraInterface> getCameras();
};
