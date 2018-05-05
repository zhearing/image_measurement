# Image Measuring Experiments

---

## Description

Five experiments of Image Measuring in USTC, including image smoothing,  image enhancement,  image edge detection,  image thresholding, image refinement, area measuring, area boundary extraction and perimeter calculation.


### Experiment 1 image smoothing & image enhancement

The experiment includes image smoothing and image enhancement. The methods of spatial neighborhood averaging, median filter, maximum value and minimum value filtering are used to realize the smooth processing of the collected gray image respectively, and the image sharpening method in the airspace is utilized. Sharpen the image (where α is a selectable factor for controlling the degree of sharpening) to remove noise and enhance detail information such as contour edges of the image.

### Experiment 2 image edge detection

In this experiment, the image edge detection uses the first-order differential operator priwitt operator and smoothed operator to perform edge detection on the grayscale image smoothed and enhanced in experiment 1.

### Experiment 3 image thresholding & image refinement

This experiment is the thresholding and refinement of the image. It mainly uses the grayscale histogram of the image to determine the corresponding segmentation threshold and divides the image into objects and backgrounds. In this experiment, we use the S.Watanabe method to select the threshold to binarize the image, and use the Deutsch method to refine the binarized image.

### Experiment 4 area measuring

This experiment is an area measurement of one of the examples of image measurement applications. It mainly uses the labeling method to calculate the local area in the image. In this experiment, the scanning labeling method was used to label the various figures in the image by using the labeling algorithm in the sense of 8 connections, so as to measure the area.

### Experiment 5 area boundary extraction & perimeter calculation

This experiment is one of the application examples of the regional boundary extraction and perimeter calculation, using the four-neighborhood method and the eight-neighborhood method to extract the boundary of the binarized image, and calculate the perimeter of the boundary.

---

## Dependencies

* OpenCV
* CMake

---

## Others

[Write-up Link](https://github.com/zhearing/image_measuring_experiments/raw/master/writeup.pdf)




