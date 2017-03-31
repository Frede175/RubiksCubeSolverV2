#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class Camera {
public:
	Camera(int cameraID);
	~Camera();
	cv::Mat getImage();
	void loop();
	//Should output an array with colors 
	unsigned char * getColors(cv::Mat * image); 

private:
	cv::VideoCapture camera;
	int width, height;
	cv::Mat lastImage;
	cv::Mat overlay;


	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;




	int scale = 7;
	void createRectFromCenter(cv::Point center, cv::Mat * frame);
	void drawColors(cv::Mat * frame, unsigned char * arr);
	cv::Point getCenter(int x, int y); // this is the coordinates form -1 to 1
	cv::Rect getRectFromCenter(cv::Point center);
    const char * colorStrings[6] = {
		"White",
		"Red",
		"Orange",
		"Green",
		"Blue",
		"Yellow"
	};


	const cv::Scalar colors[6] = {
		cv::Scalar(255,255,255,255),
		cv::Scalar(255,255,0,0),
		cv::Scalar(255,255,128,0),
		cv::Scalar(255,0,255,0),
		cv::Scalar(255,0,0,255),
		cv::Scalar(255,255,255,51)
	};


	unsigned char colorBonds[6][2][3] = {
		{ //White
			{0,0,230},
			{0,255,255}
		},
		{ //RED
			{ 151,128,128 },
			{ 180,255,255 }
		},
		{ //Orange
			{ 10,128,128 },
			{ 15,255,255 }
		},
		{ //Green
			{ 46,128,128 },
			{ 100,255,255 }
		},
		{ //Blue
			{ 101,128,128 },
			{ 150,255,255 }
		},
		{ //Yellow
			{ 16,128,128 },
			{ 45,255,255 }
		}
	};
};






#endif // !CAMERA_H
