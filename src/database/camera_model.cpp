#include "camera_model.hpp"
#include "interfaces/camera_interface.hpp"
#include <sqlite3.h>
#include <string>
#include <vector>

std::vector<CameraInterface> CameraModel::getCameras() {
  if (db) {
    std::string sql("select * from cameras");
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
      while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) 
      {
        int id = sqlite3_column_int(stmt, 0);
        printf("ID: %d\n", id);
      }
    }
  }
}
