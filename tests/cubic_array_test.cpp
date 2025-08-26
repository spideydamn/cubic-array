#include <lib/CubicArray.h>
#include <gtest/gtest.h>
#include <exception>
#include <sstream>


TEST(ArgParserTestSuite, EmptyTest) {
    CubicArray arr = CubicArray::make_array(2, 2, 2);

    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
            for (int z = 0; z < 2; ++z) {
                ASSERT_EQ((int)arr[x][y][z], 0);
            }
        }
    }
}


TEST(ArgParserTestSuite, PlusTest) {
    CubicArray arr = CubicArray::make_array(2, 2, 2);
    arr[0][0][0] = 131071;
    arr[1][1][0] = 131071;
    arr[0][1][1] = 0;
    arr[1][0][1] = 65536;
    CubicArray arr2 = CubicArray::make_array(2, 2, 2);
    arr2[0][0][0] = 0;
    arr2[1][1][0] = 1;
    arr2[0][1][1] = 1;
    arr2[1][0][1] = 65535;
    CubicArray arr3 = arr + arr2;

    ASSERT_EQ((int)arr3[0][0][0], 131071); ASSERT_EQ((int)arr3[0][0][1], 0);
    ASSERT_EQ((int)arr3[0][1][0], 0); ASSERT_EQ((int)arr3[0][1][1], 1);

    ASSERT_EQ((int)arr3[1][0][0], 0); ASSERT_EQ((int)arr3[1][0][1], 131071);
    ASSERT_EQ((int)arr3[1][1][0], 0); ASSERT_EQ((int)arr3[1][1][1], 0);
}

TEST(ArgParserTestSuite, MinusTest) {
    CubicArray arr = CubicArray::make_array(2, 2, 2);
    arr[0][0][0] = 131071;
    arr[1][1][0] = 131071;
    arr[0][1][1] = 0;
    arr[1][0][1] = 65536;
    CubicArray arr2 = CubicArray::make_array(2, 2, 2);
    arr2[0][0][0] = 131071;
    arr2[1][1][0] = 65536;
    arr2[0][1][1] = 1;
    arr2[1][0][1] = 1;
    CubicArray arr3 = arr - arr2;
    ASSERT_EQ((int)arr3[0][0][0], 0); ASSERT_EQ((int)arr3[0][0][1], 0);
    ASSERT_EQ((int)arr3[0][1][0], 0); ASSERT_EQ((int)arr3[0][1][1], 131071);

    ASSERT_EQ((int)arr3[1][0][0], 0); ASSERT_EQ((int)arr3[1][0][1], 65535);
    ASSERT_EQ((int)arr3[1][1][0], 65535); ASSERT_EQ((int)arr3[1][1][1], 0);
}

TEST(ArgParserTestSuite, MultTest) {
    CubicArray arr = CubicArray::make_array(2, 2, 2);
    arr[0][0][0] = 228;
    arr[1][1][0] = 65535;
    arr[0][1][1] = 65536;
    arr[1][0][1] = 131071;
    arr[1][1][1] = 131072;

    CubicArray arr2 = arr * 2;
    ASSERT_EQ((int)arr2[0][0][0], 456); ASSERT_EQ((int)arr2[0][0][1], 0);
    ASSERT_EQ((int)arr2[0][1][0], 0); ASSERT_EQ((int)arr2[0][1][1], 0);

    ASSERT_EQ((int)arr2[1][0][0], 0); ASSERT_EQ((int)arr2[1][0][1], 131070);
    ASSERT_EQ((int)arr2[1][1][0], 131070); ASSERT_EQ((int)arr2[1][1][1], 0);
}

TEST(ArgParserTestSuite, OutputTest) {
    CubicArray arr = CubicArray::make_array(2, 2, 2);
    arr[0][0][0] = 228;
    arr[1][1][0] = 65535;
    arr[0][1][1] = 65536;
    arr[1][0][1] = 131071;
    arr[1][1][1] = 131072;

    std::stringstream string_stream;
    string_stream << arr;

    std::stringstream expected;
    expected << 228 << ' ' << 0 << '\n' << 0 << ' ' << 65536 << '\n' << '\n' << 0 << ' ' << 131071 << '\n' << 65535 << ' ' << 0;

    ASSERT_EQ(string_stream.str(), expected.str());
}