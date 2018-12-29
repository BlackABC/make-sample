#include "getSample.hpp"

int doGetmain(int argc, char** argv)
{
	std::string videoName = "C:/Users/Administrator/Desktop/photo_image_algorith/data/2018_01_10_11_18_42_infrared.avi";
	cv::VideoCapture cap(videoName);

	int index = 75;

	for (;;)
	{
		cv::Mat frame;
		cap.read(frame);

		cv::Rect roi = selectRoi("frame", frame);

		if (roi != cv::Rect(0, 0, 0, 0)){
			cv::Mat roiImg(frame, roi);
			//格式化字符串，格式化样本名
			char buffer[7] = { 0 };
			sprintf(buffer, "%06d", index);

			std::stringstream str;
			str << "C:/Users/Administrator/Desktop/test/" << buffer << ".jpg";
			cv::imwrite(str.str(), roiImg);
			index++;
		}
		//如此选择ROI，通过在视频帧中点击鼠标，返回此刻鼠标点击位置的坐标，
		if (cv::waitKey(1) == 27)
			break;
	}

	return 0;
}