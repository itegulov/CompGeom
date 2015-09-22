cmake_minimum_required(VERSION 3.3)
project(CompGeom)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED)

find_package(GMP REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GMP_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/segment_intersection/segments_intersection_test.cpp
        src/segment_intersection/segments_intersection.h
        src/segment_intersection/segments_intersection.cpp
    src/geometry/point.h
    src/geometry/point.cpp
    src/geometry/segment.cpp
    src/geometry/segment.h)

add_executable(segments_intersection_test ${SOURCE_FILES})
target_link_libraries(segments_intersection_test ${Boost_LIBRARIES} ${GMP_LIBRARIES} ${GTEST_LIBRARY})