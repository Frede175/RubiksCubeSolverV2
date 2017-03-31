#include "stdafx.h"
#include "Camera.h"


Camera::Camera(int cameraID) {
	camera = cv::VideoCapture(cameraID);
	width = -1;
	height = -1;

	if (!camera.isOpened()) {
		std::cout << "Failed to open camera! \n";
	} else {

		//cv::namedWindow("Control", cv::WND_PROP_AUTOSIZE);


		cv::namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

		

		//Create trackbars in "Control" window
		cv::createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
		cv::createTrackbar("HighH", "Control", &iHighH, 179);

		cv::createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
		cv::createTrackbar("HighS", "Control", &iHighS, 255);

		cv::createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
		cv::createTrackbar("HighV", "Control", &iHighV, 255);



		camera.set(cv::CAP_PROP_FRAME_WIDTH, 10000);
		camera.set(cv::CAP_PROP_FRAME_HEIGHT, 10000);
		width = (int)camera.get(cv::CAP_PROP_FRAME_WIDTH);
		height = (int)camera.get(cv::CAP_PROP_FRAME_HEIGHT);
		camera.set(cv::CAP_PROP_CONTRAST, 7000);
		//camera.set(cv::CAP_PROP_ISO_SPEED, 255);
		camera.set(cv::CAP_PROP_SATURATION, 7400);

		overlay = cv::Mat(cv::Size(width, height), CV_8UC1);


	}
}



Camera::~Camera() {
	if (camera.isOpened()) camera.release();
}

cv::Mat Camera::getImage() {
	camera.read(lastImage);
	return lastImage;
}

void Camera::loop() {
	while (true) {
		cv::Mat cameraFrame;
		camera.read(cameraFrame);
		lastImage = cameraFrame;
		/*
		createRectFromCenter(cv::Point(width / 2 - 19 * scale, height / 2 - 19 * scale), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2, height / 2 - 19 * scale), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2 + 19 * scale, height / 2 - 19 * scale), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2 - 19 * scale, height / 2), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2 + 19 * scale, height / 2), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2 - 19 * scale, height / 2 + 19 * scale), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2, height / 2 + 19 * scale), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2 + 19 * scale, height / 2 + 19 * scale), &cameraFrame);
		createRectFromCenter(cv::Point(width / 2, height / 2), &cameraFrame);
		*/

		drawColors(&cameraFrame, getColors(&cameraFrame));
		imshow("cam", cameraFrame);
		char key;
		if ((key = (char)cv::waitKey(30)) >= 0)
			if (key == 27) break;
	}
}

unsigned char * Camera::getColors(cv::Mat * image) {
	
	cv::Mat imgHSV;
	unsigned char colors[9] = {255, 255, 255, 255, 255, 255, 255, 255, 255};

	cv::cvtColor(*image, imgHSV, cv::COLOR_BGR2HSV);

	cv::Mat imgThreshold;

	inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThreshold);
	

	imshow("Bla", imgThreshold);
	for (int i = 0; i < 6; i++) {
		cv::inRange(imgHSV, cv::Scalar(colorBonds[i][0][0], colorBonds[i][0][1], colorBonds[i][0][2]), cv::Scalar(colorBonds[i][1][0], colorBonds[i][1][1], colorBonds[i][1][2]), imgThreshold);
		for (int y = -1; y <= 1; y++) {
			for (int x = -1; x <= 1; x++) {
				int index = (y + 1) * 3 + x + 1;
				imshow(colorStrings[i], imgThreshold);
				cv::Rect rect = getRectFromCenter(getCenter(x, y));
				cv::Mat mask = imgThreshold(rect);
				cv::Scalar avg = cv::mean(mask);
				if (avg.val[0] > 20 && colors[index] == 255) {
					colors[index] = i;
				}

			}
		}
	}
	/*


	for (int i = 0; i < 9; i++) {
		if (colors[i] != 255) {
			std::cout << "I:" << i << " color: " << colorStrings[colors[i]] << "\n";
		}
	}
	*/
	return colors;

}

void Camera::createRectFromCenter(cv::Point center, cv::Mat * frame) {
	cv::rectangle(*frame, getRectFromCenter(center), cv::Scalar(255,255,255,255));
}

void Camera::drawColors(cv::Mat * frame, unsigned char * arr) {

	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			int index = (y + 1) * 3 + x + 1;
			cv::Rect rect = getRectFromCenter(getCenter(x, y));
			if (arr[index] >= 0 && arr[index] < 6) {
				cv::rectangle(*frame, rect, colors[arr[index]], -1);
				std::cout << "Color: " << colorStrings[arr[index]] << "\n";
			} else {
				cv::rectangle(*frame, rect, cv::Scalar(255, 255, 255, 255));
			}
		}
	}

}

cv::Point Camera::getCenter(int x, int y) {
	return cv::Point(width / 2 + x * 19 * scale, height / 2 + y * 19 * scale);
}

cv::Rect Camera::getRectFromCenter(cv::Point center) {
	return cv::Rect(center.x - 7 * scale / 2, center.y - 7 * scale / 2, 7 * scale, 7 * scale);
}
