#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat Enhancement(Mat image, double k)
{
	Mat image_enhancement;
	image.copyTo(image_enhancement);
	for (int i = 1; i < image.rows - 1; i++)
		for (int j = 1; j < image.cols - 1; j++)
		{
			image_enhancement.at<uchar>(i, j) = image.at<uchar>(i, j) + 4 * k*(image.at<uchar>(i, j) - (image.at<uchar>(i + 1, j) + image.at<uchar>(i - 1, j) + image.at<uchar>(i, j + 1) + image.at<uchar>(i, j - 1)) / 4);
		}
	return image_enhancement;
}

int main(int argc, char** argv)
{
	Mat image1 = imread("../images/lena.bmp", -1);
	Mat image2 = imread("../output/ave_image.bmp", -1);
	Mat image3 = imread("../output/salt_image.bmp", -1);

	double k = 0.8;
	namedWindow("origin", WINDOW_AUTOSIZE);
	imshow("origin", image1);
	namedWindow("origin_enhancement", WINDOW_AUTOSIZE);
	imshow("origin_enhancement", Enhancement(image1, k));
	imwrite("../output/origin_enhancement.bmp", Enhancement(image1, k));
	namedWindow("mid_image", WINDOW_AUTOSIZE);
	imshow("mid_image", image2);
	namedWindow("mid_image_enhancement", WINDOW_AUTOSIZE);
	imshow("mid_image_enhancement", Enhancement(image2, k));
	imwrite("../output/mid_image_enhancement.bmp", Enhancement(image2, k));
	namedWindow("salt_image", WINDOW_AUTOSIZE);
	imshow("salt_image", image3);
	namedWindow("salt_image_enhancement", WINDOW_AUTOSIZE);
	imshow("salt_image_enhancement", Enhancement(image3, k));
	imwrite("../output/salt_image_enhancement.bmp", Enhancement(image3, k));
	waitKey(0);
	return 0;
}
