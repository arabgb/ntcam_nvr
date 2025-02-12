#include "camera_model.hpp"
#include "interfaces/camera_interface.hpp"
#include <sqlite3.h>
#include <string>
#include <vector>

CameraModel::CameraModel(sqlite3 *db) : db(db) {}

std::vector<CameraInterface> CameraModel::getCameras(int motion) {
  std::vector<CameraInterface> cameras;
  if (db) {
    std::string sql("select * from cameras");
    if (motion != -1) {
      sql = "select * from cameras where motion_detection=" + std::to_string(motion);
    }
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
      while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        printf("ID: %d\n", id);
        cameras.emplace_back(CameraInterface{.id = sqlite3_column_int(stmt, 0),
                             .ip = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
                             .port = sqlite3_column_int(stmt, 2),
                             .user = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)),
                             .password = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)),
                             .width = sqlite3_column_int(stmt, 5),
                             .height = sqlite3_column_int(stmt, 6),
                             .url_detection = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7)),
                             .url_recording = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8)),
                             .model = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9)),
                             .switch_port = sqlite3_column_int(stmt, 10),
                             .motion_detection = sqlite3_column_int(stmt, 11),
                             .online = sqlite3_column_int(stmt, 12)});
      }
    }
  }
  return cameras;
}
