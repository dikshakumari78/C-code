#include "gtest/gtest.h"
#include "DynamicArray.h"

class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> array;

    void SetUp() override {
        array.push_back(1);
        array.push_back(2);
        array.push_back(3);
    }
};

TEST_F(DynamicArrayTest, SizeAfterPushBack) {
    EXPECT_EQ(array.size(), 3);
}

TEST_F(DynamicArrayTest, AccessElements) {
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
}

TEST_F(DynamicArrayTest, ResizeAndPushBack) {
    array.push_back(4);
    array.push_back(5);
    EXPECT_EQ(array.size(), 5);
    EXPECT_EQ(array[3], 4);
    EXPECT_EQ(array[4], 5);
}

TEST_F(DynamicArrayTest, PopBackReducesSize) {
    array.pop_back();
    EXPECT_EQ(array.size(), 2);
    EXPECT_EQ(array[1], 2);
}

TEST_F(DynamicArrayTest, PopBackEmptyArrayThrowsException) {
    DynamicArray<int> emptyArray;
    EXPECT_THROW(emptyArray.pop_back(), std::out_of_range);
}

TEST_F(DynamicArrayTest, AccessOutOfRangeThrowsException) {
    EXPECT_THROW(array[5], std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
