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



		camera.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
		camera.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
		camera.set(cv::CAP_PROP_SETTINGS, 1);
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
	if (!camera.isOpened()) return;
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

		unsigned char arr[9];
		getColors(cameraFrame, arr);

		//drawColors(&cameraFrame, arr);
		for (int y = -1; y <= 1; y++) {
			for (int x = -1; x <= 1; x++) {
				int index = (y + 1) * 3 + x + 1;
				cv::Rect rect = getRectFromCenter(getCenter(x, y));
				if (arr[index] < 6)  cv::rectangle(cameraFrame, rect, targetColorsBGR[arr[index]], -1);
			}
		}

		
		imshow("cam", cameraFrame);
		char key;
		if ((key = (char)cv::waitKey(30)) >= 0)
			if (key == 27) break;
	}
}

void Camera::getColors(cv::Mat image, unsigned char * arr) {
	
	cv::Mat imgHSV;

	cv::cvtColor(image, imgHSV, cv::COLOR_BGR2HSV_FULL);

	cv::Mat imgThreshold;

	inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThreshold);
	

	imshow("Bla", imgThreshold);
	//for (int i = 0; i < 6; i++) {
		//cv::inRange(imgHSV, cv::Scalar(colorBonds[i][0][0], colorBonds[i][0][1], colorBonds[i][0][2]), cv::Scalar(colorBonds[i][1][0], colorBonds[i][1][1], colorBonds[i][1][2]), imgThreshold);
		/*for (int y = -1; y <= 1; y++) {
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
		}*/
	
	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			int index = (y + 1) * 3 + x + 1;
			
			//imshow(colorStrings[i], imgThreshold);
			cv::Rect rect = getRectFromCenter(getCenter(x, y));
			cv::Scalar avghsv = cv::mean(imgHSV(rect));
			cv::Scalar avgbgr = cv::mean(image(rect));
			//imshow("rgb" + std::to_string(index), mask);
			arr[index] = getColor(avghsv, avgbgr);

			//if (x == 0 && y == 0) std::cout << "H: " << avghsv.val[0] << "S: " << avghsv.val[1] << "V: " << avghsv.val[2] << "\n";


			//std::cout << index << "\n";
		}
	}




	//}
	/*


	for (int i = 0; i < 9; i++) {
		if (colors[i] != 255) {
			std::cout << "I:" << i << " color: " << colorStrings[colors[i]] << "\n";
		}
	}
	*/
	//return colors;

}

void Camera::calibrate() {

	
	cv::Mat cameraFrame;
	cv::Mat imgHSV;
	int side = 0;
	//bool calibrated = false;

	while (side < 6) {
		camera.read(cameraFrame);
		cv::cvtColor(cameraFrame, imgHSV, cv::COLOR_BGR2HSV);
		//TODO START debug
		for (int y = -1; y <= 1; y++) {
			for (int x = -1; x <= 1; x++) {
				int index = (y + 1) * 3 + x + 1;
				cv::Rect rect = getRectFromCenter(getCenter(x, y));
				cv::rectangle(cameraFrame, rect, cv::Scalar(255, 255, 255, 255));
			}
		}
		//TODO END debug		
		imshow("Cam", cameraFrame);
		char key = (char)cv::waitKey(30);
		if (key == 97) { //A is pressed
			cv::Rect rect = getRectFromCenter(getCenter(0, 0));
			cv::Scalar color = cv::mean(imgHSV(rect));;
			cColors[side][0] = cv::Scalar(color - cv::Scalar(5, 100, 100));
			cColors[side][1] = cv::Scalar(color + cv::Scalar(5, 100, 100));

			std::cout << "Side: " << side << " " << cColors[side][0] << ", " << cColors[side][1] << "\n";
			side++;

		} else if (key == 27) break;

	}
	

}

void Camera::createRectFromCenter(cv::Point center, cv::Mat * frame) {
	cv::rectangle(*frame, getRectFromCenter(center), cv::Scalar(255,255,255,255));
}

void Camera::drawColors(cv::Mat * frame, unsigned char * arr) {

	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			int index = (y + 1) * 3 + x + 1;
			cv::Point center = getCenter(x, y);
			std::cout << "Index: " << index << " arr[index]: " << unsigned(arr[index]) << "\n";
			if (arr[index] < 6) cv::putText(*frame, colorStrings[arr[index]], center, 0, 1, cv::Scalar(255,255,255));
		}
	}

}

unsigned char Camera::getColor(cv::Scalar hsv, cv::Scalar bgr) {
	/*
	std::cout << round((float)bgr.val[0] / (float)bgr.val[1]) << "\n";
	if (round((float)bgr.val[0] / (float)bgr.val[2]) > 2 && round((float)bgr.val[0] / (float)bgr.val[1]) >= 2) return 4; //BLUE
	else if (round((float)bgr.val[1] / (float)bgr.val[2]) > 2) return 3; //GREEN

	if (hsv.val[0] > 150) return 1; //RED
	else if (hsv.val[0] < 20 && hsv.val[1] < 150) return 0; //WHITE
	else if (hsv.val[0] < 20) return 2; //ORANGE
	else if (hsv.val[0] < 50) return 5; //YELLOW


	return 255;
	*/
/*
	cv::Scalar rgb(bgr[2], bgr[1], bgr[0]);

	for (int i = 0; i < 6; i++) {
		if (hsv[0] > cColors[i][0][0] && hsv[0] < cColors[i][1][0] && hsv[1] > cColors[i][0][1] && hsv[1] < cColors[i][1][1] && hsv[2] > cColors[i][0][2] && hsv[2] < cColors[i][1][2]) return i;
	}

	*/


	unsigned char index = 255;
	int min_d = 0;


	for (int i = 0; i < 6; i++) {
		int d = (hsv[0] - targetColors[i][0])*(hsv[0] - targetColors[i][0]) +
			(hsv[1] - targetColors[i][1])*(hsv[1] - targetColors[i][1]) +
			(hsv[2] - targetColors[i][2])*(hsv[2] - targetColors[i][2]);


		if (d < min_d || index == 255) {
			index = i;
			min_d = d;
		}
	}

	std::cout << "Color index: " << unsigned(index) << "\n";

	return index;
}

cv::Point Camera::getCenter(int x, int y) {
	return cv::Point(width / 2 + x * 19 * scale, height / 2 + y * 19 * scale);
}

cv::Rect Camera::getRectFromCenter(cv::Point center) {
	return cv::Rect(center.x - 6 * scale / 2, center.y - 6 * scale / 2, 6 * scale, 6 * scale);
}
