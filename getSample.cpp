#include "getSample.hpp"

void opencv_mouse_callback(int event, int x, int y, int, void* param)
{
	selectorParams* data = (selectorParams*)param;
	switch (event)
	{
	case cv::EVENT_LBUTTONDOWN:
		data->center = cv::Point(x, y);
		//车辆是56*64，行人是40*52，负样本大小150*150,测试图片大小280*320
		data->box = cv::Rect(data->center.x - 140, data->center.y - 160, 280, 320);
		break;

		// cleaning up the selected bounding box
	case cv::EVENT_LBUTTONUP:
		if (data->box.x < 0){
			data->center = cv::Point(0, 0);
			data->box = cv::Rect(0, 0, 0, 0);
			std::cout << "the center point is too left" << std::endl;
		}
		if (data->box.y < 0){
			data->center = cv::Point(0, 0);
			data->box = cv::Rect(0, 0, 0, 0);
			std::cout << "the center point is too top" << std::endl;

		}
		break;
	}
}

cv::Rect selectRoi(const cv::String& windowName, cv::Mat img)
{
	printf("Select an object to track and then press SPACE or ENTER button!\n");

	int key = 0;

	selectorParams selectorParams;

	//显示图像
	imshow(windowName, img);

	selectorParams.image = img.clone();

	setMouseCallback(windowName, opencv_mouse_callback, (void *)&selectorParams);

	// SPACE (32) ESC (27) or ENTER (13)
	while (!(key == 32 || key == 27 || key == 13)){
		// draw the selected object
		rectangle(
			selectorParams.image,
			selectorParams.box,
			cv::Scalar(255, 0, 0), 2, 1
			);

		// show the image bouding box
		imshow(windowName, selectorParams.image);

		// reset the image
		selectorParams.image = img.clone();

		//get keyboard event, extract lower 8 bits for scancode comparison
		key = cv::waitKey(1) & 0xFF;
	}

	return selectorParams.box;
}