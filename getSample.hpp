#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

typedef struct handleT{
	cv::Rect box;
	cv::Mat image;
	cv::Point center;
}selectorParams;

void opencv_mouse_callback(int event, int x, int y, int, void* param);

cv::Rect selectRoi(const cv::String& windowName, cv::Mat img);