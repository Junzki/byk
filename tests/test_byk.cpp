

#include <byk.h>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(FindBookByName, BasicAssertions) {
    auto result = byk::find_book_by_title("some-book");
    EXPECT_EQ(nullptr, result);
}
