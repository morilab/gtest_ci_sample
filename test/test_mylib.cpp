#include <gtest/gtest.h>
#include "../src/mylib.h" // テスト対象のヘッダーファイルをインクルード

// ✅ add 関数のテスト
TEST(MyLibTest, Addition) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
}

// ✅ isEven 関数のテスト
TEST(MyLibTest, EvenCheck) {
    EXPECT_TRUE(isEven(2));
    EXPECT_TRUE(isEven(100));
    EXPECT_FALSE(isEven(3));
    EXPECT_FALSE(isEven(-1));
}

// 🔹 Google Test のメイン関数 (省略可能)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

