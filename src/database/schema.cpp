#include "schema.hpp"
#include <string>

std::string Schema:: getSettingsTable() {
  // return raw string stream (require c++11 and later)
  return R"(
	CREATE TABLE IF NOT EXISTS settings (
        id integer PRIMARY KEY,
        NVR_IP string DEFAULT 'localhost' NOT NULL,
        NVR_PORT integer DEFAULT 4838 NOT NULL );
  )";
}
std::string Schema::getCamerasTable() {
  // return raw string stream (require c++11 and later)
  return R"(
	CREATE TABLE IF NOT EXISTS cameras (
	id integer PRIMARY KEY,
	ip string NOT NULL,
	port integer NOT NULL,
	user string NOT NULL,
	password string NOT NULL,
	width integer NOT NULL,
	height integer NOT NULL,
	description string NOT NULL,
	url_detection string NOT NULL,
	url_recording string NOT NULL,
	model string NOT NULL,
	switch_port integer NOT NULL,
	motion_detection intger DEFAULT 1 NOT NULL,
	online integer DEFAULT 0 NOT NULL );
  )";
}
std::string Schema::getMotionPositionsTable() {
  // return raw string stream (require c++11 and later)
  return R"(
        CREATE TABLE IF NOT EXISTS motion_positions (
        id integer PRIMARY KEY,
        camera_id integer NOT NULL,
        enable integer DEFAULT 1 NOT NULL,
        sensetivity integer DEFAULT 70 NOT NULL,
        notification integer DEFAULT 1 NOT NULL,
        continue_on_ignore_point integer DEFAULT 1 NOT NULL );
  )";
}
std::string Schema::getPositionPoints() {
  // return raw string stream (require c++11 and later)
  return R"(
        CREATE TABLE IF NOT EXISTS position_points (
        id integer PRIMARY KEY,
        motions_position_id integer NOT NULL,
        p_type integer NOT NULL,
        p1_x integer NOT NULL,
        p1_y integer NOT NULL,
        p2_x integer NOT NULL,
        p2_y integer NOT NULL );
  )";
}
std::string Schema::getRecordingTable() {
  // return raw string stream (require c++11 and later)
  return R"(
	CREATE TABLE IF NOT EXISTS recording (
        id integer PRIMARY KEY,
        camera_id integer NOT NULL,
        motions_position_id integer NOT NULL,
        vid_path string NOT NULL,
        anim_path string NOT NULL,
        vid_size integer NOT NULL,
        anim_size integer NOT NULL,
        motion_date timestamp NOT NULL );
  )";
}

