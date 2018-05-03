SET(PROJECT_NAME image-smoothing-and-image-enhancement)

PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11")
SET(CMAKE_BUILD_TYPE RELEASE)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(image-enhacement ./src/image-enhacement.cpp)
ADD_EXECUTABLE(image-smoothing  ./src/image-smoothing.cpp)

TARGET_LINK_LIBRARIES(image-enhacement ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(image-smoothing ${OpenCV_LIBS})