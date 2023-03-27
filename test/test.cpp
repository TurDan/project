#include "/src/gameLogic.cpp"
#include "gtest/gtest.h" 


TEST(CheckDuplicatesTest, AlreadyExist) {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    bool result = checkDuplicates(3, arr);
    EXPECT_TRUE(result);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
   
    return RUN_ALL_TESTS();
}

