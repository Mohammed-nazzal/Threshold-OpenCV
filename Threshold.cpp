#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using  std::string;

using namespace cv;

int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_values = 255;

Mat src, src_gray, dst;

const char* windows_name = "Threshold";
const char* trackbar_type = "Type: \n 0:\ Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To zero \ 4: Zero Inverted";
const char* trackbar_value = "Values";

void Threshold_Demo(int, void*)
{
	threshold(src_gray, dst, threshold_value, max_BINARY_values, threshold_type);
	imshow(windows_name, dst);
}

int main(int argc, char* argv[])
{
	src = imread("imagen02.jpg", IMREAD_COLOR);

	cvtColor(src, src_gray, CV_RGB2GRAY);

	namedWindow(windows_name, CV_WINDOW_AUTOSIZE);

	createTrackbar(trackbar_type, windows_name, &threshold_type, max_type, Threshold_Demo);
	createTrackbar(trackbar_value, windows_name, &threshold_value, max_value, Threshold_Demo);

	//imshow("original", src);

	Threshold_Demo(0, 0);

	while (true)
	{
		int c = waitKey(20);
		if ((char)c == 27)
		{
			break;
		}
	}
}
