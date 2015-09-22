//
// Created by Daniyar Itegulov on 22/09/15.
//

#include <gtest/gtest.h>
#include "segments_intersection.h"

TEST(simple, vertical_and_horizontal_intersect) {
    ASSERT_TRUE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(0, -1), point(0, 1))));
}

TEST(simple, vertical_and_horizontal_not_intersect) {
    ASSERT_FALSE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(0, -1), point(0, -2))));
}

TEST(degenerate, point_on_segment) {
    ASSERT_TRUE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(0, 0), point(0, 0))));
}

TEST(degenerate, point_not_on_segment) {
    ASSERT_FALSE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(0, 1), point(0, 1))));
}

TEST(degenerate, segment_is_inside_other_segment) {
    ASSERT_TRUE(intersects(segment(point(-2, 0), point(2, 0)), segment(point(-1, 0), point(1, 0))));
}

TEST(degenerate, segments_coincide) {
    ASSERT_TRUE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(-1, 0), point(1, 0))));
}

TEST(degenerate, segments_touch_by_end) {
    ASSERT_TRUE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(1, 0), point(3, 0))));
}

TEST(degenerate, segments_touch_by_middle) {
    ASSERT_TRUE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(0, 1), point(0, 0))));
    ASSERT_TRUE(intersects(segment(point(0, -1), point(0, 1)), segment(point(1, 0), point(0, 0))));
}

TEST(degenerate, segments_touch_by_start) {
    ASSERT_TRUE(intersects(segment(point(-1, 0), point(1, 0)), segment(point(-3, 0), point(-1, 0))));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}