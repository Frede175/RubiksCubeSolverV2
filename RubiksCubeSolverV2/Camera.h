#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class Camera {
public:
	Camera(int cameraID);
	void loop(); //TODO REMOVE TEMP 
	void getColors();

private:
	cv::VideoCapture camera;



};


#endif // !CAMERA_H
