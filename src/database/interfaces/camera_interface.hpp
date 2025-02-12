#ifndef CAMERA_INTERFACE_H
#define CAMERA_INTERFACE_H

#include <string>
struct CameraInterface {
	int id;
	std::string ip;
	int port;
	std::string user;
	std::string password;
	int width;
	int height;
	std::string description;
	std::string url_detection;
	std::string url_recording;
	std::string model;
	int switch_port;
	int motion_detection;
	int online;
};

#endif
