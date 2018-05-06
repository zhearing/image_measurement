SET(PROJECT_NAME image-thresholding-and-image-refinement)

PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11")
SET(CMAKE_BUILD_TYPE RELEASE)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(image-thresholding ./src/image_thresholding.cpp)
ADD_EXECUTABLE(image-refinement  ./src/image_refinement.cpp)

TARGET_LINK_LIBRARIES(image-thresholding ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(image-refinement ${OpenCV_LIBS})
