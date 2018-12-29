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
			//��ʽ���ַ�������ʽ��������
			char buffer[7] = { 0 };
			sprintf(buffer, "%06d", index);

			std::stringstream str;
			str << "C:/Users/Administrator/Desktop/test/" << buffer << ".jpg";
			cv::imwrite(str.str(), roiImg);
			index++;
		}
		//���ѡ��ROI��ͨ������Ƶ֡�е����꣬���ش˿������λ�õ����꣬
		if (cv::waitKey(1) == 27)
			break;
	}

	return 0;
}