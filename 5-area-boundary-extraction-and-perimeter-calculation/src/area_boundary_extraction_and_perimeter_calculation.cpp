// Copyright 2018 Zeyu Zhong
// Lincese(MIT)
// Author: Zeyu Zhong
// Date: 2018.5.5

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char **argv) {
    Mat image = imread("../../5-area-boundary-extraction-and-perimeter-calculation/images/origin.bmp", -1);
    imshow("origin", image);
    Mat L1, L2;
    image.copyTo(L1);
    image.copyTo(L2);

    for (int i = 0; i < L1.rows - 1; i++)
        for (int j = 0; j < L1.cols - 1; j++) {
            L1.at<uchar>(i, j) = 0;
            L2.at<uchar>(i, j) = 0;
        }
    for (int i = 1; i < image.rows - 1; i++)
        for (int j = 1; j < image.cols - 1; j++) {
            int f[9];
            f[0] = image.at<uchar>(i, j + 1);
            f[1] = image.at<uchar>(i - 1, j + 1);
            f[2] = image.at<uchar>(i - 1, j);
            f[3] = image.at<uchar>(i - 1, j - 1);
            f[4] = image.at<uchar>(i, j - 1);
            f[5] = image.at<uchar>(i + 1, j - 1);
            f[6] = image.at<uchar>(i + 1, j);
            f[7] = image.at<uchar>(i + 1, j + 1);
            f[8] = image.at<uchar>(i, j);
            if ((f[8] != f[6]) || (f[8] != f[2]) || (f[8] != f[4]) || (f[8] != f[0]))
                L1.at<uchar>(i, j) = 255;
            if ((f[8] != f[6]) || (f[8] != f[2]) || (f[8] != f[4]) || (f[8] != f[0]) || (f[8] != f[3]) || (f[8] != f[1]) || (f[8] != f[5]) || (f[8] != f[7]))
                L2.at<uchar>(i, j) = 255;
        }
    int Perimeter1 = 0;
    int Perimeter2 = 0;
    for (int i = 0; i < L1.rows - 1; i++)
        for (int j = 0; j < L1.cols - 1; j++) {
            if (L1.at<uchar>(i, j) == 255)
                Perimeter1 = Perimeter1 + 1;
            if (L2.at<uchar>(i, j) == 255)
                Perimeter2 = Perimeter2 + 1;
        }
    std::cout << "four_neighborhoods: " << Perimeter1 << "   "
              << "eight_neighborhoods: " << Perimeter2;
    imshow("origin", image);
    imshow("four_neighborhoods", L1);
    imshow("eight_neighborhoods", L2);
    imwrite("../../5-area-boundary-extraction-and-perimeter-calculation/output/four_neighborhoods.bmp", L1);
    imwrite("../../5-area-boundary-extraction-and-perimeter-calculation/output/eight_neighborhoods.bmp", L2);
    waitKey(0);
    return 0;
}
