#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	VideoCapture video;
	video.open("E:/video.mp4");//复制路径时候“\”改成“/”
	if (!video.isOpened())
	{
		cout << "open video failed!" << endl;
		return 0;
	}
	cout << "open video success!" << endl;
	Mat frame;
	namedWindow("video");
	for (;;)
	{
		if (!video.read(frame)) //判断是否为空，是下面读帧和转换颜色一样
		{
			break;
		}
		    // 读帧，解码
			//if (!video.grab())
			//{
			//	break;
			//}
			//转换颜色格式
			//if (!video.retrieve(frame))
			//{
			//	break;
			//}
			if (frame.empty())break;//另一种跳出循环的事列
		imshow("video", frame);
		waitKey(30);//
	}


	waitKey(0);
	return 0;

}