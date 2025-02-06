#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include "database.hpp"

int main() {
	cv::Mat img_nz = cv::imread("/Users/nabohamad/Pictures/NZ.png", cv::IMREAD_COLOR);
	if (!img_nz.empty()) {
		cv::imshow("Picture Show", img_nz);
		cv::waitKey(0);
		return 0;
	}
	else {
		std::cout << "Error! cant read the image" << std::endl;
		return 0;
	}
}
