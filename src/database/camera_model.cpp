#include "camera_model.hpp"
#include "interfaces/camera_interface.hpp"
#include <iostream>
#include <optional>
#include <ostream>
#include <sqlite3.h>
#include <string>
#include <vector>
CameraModel::CameraModel(sqlite3 *db) : db(db) {}

std::vector<CameraInterface> CameraModel::getCameras(int motion) {
  std::vector<CameraInterface> cameras;
  if (db) {
    std::string sql("select * from cameras");
    if (motion != -1) {
      sql = "select * from cameras where motion_detection=" +
            std::to_string(motion);
    }
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
      while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cameras.emplace_back(CameraInterface{
            .id = sqlite3_column_int(stmt, 0),
            .ip = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
            .port = sqlite3_column_int(stmt, 2),
            .user =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)),
            .password =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)),
            .width = sqlite3_column_int(stmt, 5),
            .height = sqlite3_column_int(stmt, 6),
            .description =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7)),
            .url_detection =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8)),
            .url_recording =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9)),
            .model =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10)),
            .switch_port = sqlite3_column_int(stmt, 11),
            .motion_detection = sqlite3_column_int(stmt, 12),
            .online = sqlite3_column_int(stmt, 13)});
      }
    }
    sqlite3_finalize(stmt);
  }
  return cameras;
}

std::optional<CameraInterface> CameraModel::getCamera(int id) {
    std::optional<CameraInterface> camera;
  if (db) {
    std::string sql("select * from cameras where id=" + std::to_string(id));
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc == SQLITE_OK) {
      if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
          std::cout << "#!";
        camera = CameraInterface{
            .id = sqlite3_column_int(stmt, 0),
            .ip = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
            .port = sqlite3_column_int(stmt, 2),
            .user =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)),
            .password =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)),
            .width = sqlite3_column_int(stmt, 5),
            .height = sqlite3_column_int(stmt, 6),
            .description =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7)),
            .url_detection =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8)),
            .url_recording =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9)),
            .model =
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10)),
            .switch_port = sqlite3_column_int(stmt, 11),
            .motion_detection = sqlite3_column_int(stmt, 12),
            .online = sqlite3_column_int(stmt, 13)};
      }
    }
    sqlite3_finalize(stmt);
  }
  return camera;
}
