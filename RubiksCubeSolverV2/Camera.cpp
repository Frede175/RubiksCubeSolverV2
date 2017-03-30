#include "stdafx.h"
#include "Camera.h"

Camera::Camera(int cameraID) {
	camera = cv::VideoCapture(cameraID);
	if (!camera.isOpened()) {
		std::cout << "Failed to open camera! \n";
	}
}

void Camera::loop() {
	if (camera.isOpened()) {
		while (true) {
			cv::Mat cameraFrame;
			camera.read(cameraFrame);
			imshow("cam", cameraFrame);
			if (cv::waitKey(30) >= 0)
				break;
		}
	}


}
