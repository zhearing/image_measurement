SET(PROJECT_NAME image_measuring_experiments)

PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11")
SET(CMAKE_BUILD_TYPE RELEASE)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

ADD_SUBDIRECTORY(1-image-smoothing-and-image-enhancement)
ADD_SUBDIRECTORY(2-image-edge-detection)
ADD_SUBDIRECTORY(3-image-thresholding-and-image-refinement)
ADD_SUBDIRECTORY(4-area-measuring)
ADD_SUBDIRECTORY(5-area-boundary-extraction-and-perimeter-calculation)

