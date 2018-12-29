#include <iostream>  
#include <fstream>  
#include <stdlib.h> //srand()��rand()����  
#include <time.h> //time()����  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/objdetect/objdetect.hpp>  
#include <opencv2/ml/ml.hpp>  

using namespace std;
using namespace cv;

int CropImageCount = 0; //�ü������ĸ�����ͼƬ����  

int main()
{
	Mat src;
	string ImgName;
	char saveName[256];//�ü������ĸ�����ͼƬ�ļ���  
	ifstream fin("NegativeSample.txt");//��ԭʼ������ͼƬ�ļ��б�  
	//ifstream fin("subset.txt");  

	//һ��һ�ж�ȡ�ļ��б�  
	while (getline(fin, ImgName))
	{
		cout << "����" << ImgName << endl;
		ImgName = "C:/Users/Administrator/Desktop/Negative Sample/" + ImgName;
		src = imread(ImgName);//��ȡͼƬ  
		//cout<<"��"<<src.cols<<"���ߣ�"<<src.rows<<endl;  

		//ͼƬ��СӦ���������ٰ���һ��150*150�Ĵ���  
		if (src.cols >= 150 && src.rows >= 150)
		{
			srand(time(NULL));//�������������  

			////��ÿ��ͼƬ������ü�20��56*64��С�Ĳ������˵ĸ�����  
			//for (int i = 0; i<20; i++)
			//{
			//	int x = (rand() % (src.cols - 56)); //���Ͻ�x����  
			//	int y = (rand() % (src.rows - 64)); //���Ͻ�y����  
			//	//cout<<x<<","<<y<<endl;  
			//	Mat imgROI = src(Rect(x, y, 56, 64));
			//	sprintf(saveName, "%06d.jpg", ++CropImageCount);//���ɲü����ĸ�����ͼƬ���ļ���  
			//	imwrite(saveName, imgROI);//�����ļ�  
			//}
			//��ÿ��ͼƬ������ü�20��40*52��С�Ĳ������˵ĸ�����  
			for (int i = 0; i<20; i++)
			{
				int x = (rand() % (src.cols - 40)); //���Ͻ�x����  
				int y = (rand() % (src.rows - 52)); //���Ͻ�y����  
				//cout<<x<<","<<y<<endl;  
				Mat imgROI = src(Rect(x, y, 40, 52));
				sprintf(saveName, "%06d.jpg", ++CropImageCount);//���ɲü����ĸ�����ͼƬ���ļ���  
				imwrite(saveName, imgROI);//�����ļ�  
			}
		}
	}

	system("pause");
	return 0;
}