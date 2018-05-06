// Copyright 2018 Zeyu Zhong
// Lincese(MIT)
// Author: Zeyu Zhong
// Date: 2018.5.3

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat Enhancement(Mat image, double alpha) {
    Mat image_enhancement;
    image.copyTo(image_enhancement);
    for (int i = 1; i < image.rows - 1; i++)
        for (int j = 1; j < image.cols - 1; j++)
            image_enhancement.at<uchar>(i, j) = image.at<uchar>(i, j) + 4 * alpha * (
            image.at<uchar>(i, j) - (image.at<uchar>(i + 1, j) + image.at<uchar>(i - 1, j) + image.at<uchar>(i, j + 1) + image.at<uchar>(i, j - 1)) / 4);
    return image_enhancement;
}

int main(int argc, char **argv) {
    Mat image = imread("../../1-image-smoothing-and-image-enhancement/images/lena.bmp", -1);
    Mat ave_image, salt_image;
    image.copyTo(ave_image);
    image.copyTo(salt_image);

    double alpha = 0.8;
    namedWindow("origin", WINDOW_AUTOSIZE);
    imshow("origin", image);

    namedWindow("origin_enhancement", WINDOW_AUTOSIZE);
    imshow("origin_enhancement", Enhancement(image, alpha));
    imwrite("../../1-image-smoothing-and-image-enhancement/output/origin_enhancement.bmp", Enhancement(image, alpha));

    namedWindow("mid_image", WINDOW_AUTOSIZE);
    imshow("mid_image", ave_image);

    namedWindow("mid_image_enhancement", WINDOW_AUTOSIZE);
    imshow("mid_image_enhancement", Enhancement(ave_image, alpha));
    imwrite("../../1-image-smoothing-and-image-enhancement/output/mid_image_enhancement.bmp", Enhancement(ave_image, alpha));

    namedWindow("salt_image", WINDOW_AUTOSIZE);
    imshow("salt_image", salt_image);

    namedWindow("salt_image_enhancement", WINDOW_AUTOSIZE);
    imshow("salt_image_enhancement", Enhancement(salt_image, alpha));
    imwrite("../../1-image-smoothing-and-image-enhancement/output/salt_image_enhancement.bmp", Enhancement(salt_image, alpha));

    waitKey(0);
    return 0;
}
