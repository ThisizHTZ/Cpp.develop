#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(StringUtils::Slice("Hello, World!", 7, 12), "World");
    EXPECT_EQ(StringUtils::Slice("Hello, World!", -6, -1), "World");
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize("hello"), "Hello");
    EXPECT_EQ(StringUtils::Capitalize("Hello"), "Hello");
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper("hello"), "HELLO");
    EXPECT_EQ(StringUtils::Upper("abcde"), "ABCDE");
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("HELLO"), "hello");
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("   Hello"), "Hello");
    EXPECT_EQ(StringUtils::LStrip("\t\n Hello"), "Hello");
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip("Hello   "), "Hello");
    EXPECT_EQ(StringUtils::RStrip("Hello\t\n "), "Hello");
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip("   Hello   "), "Hello");
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("Hello", 7, ' '), " Hello ");
    EXPECT_EQ(StringUtils::Center("Hello", 12, ' '), "    Hello   ");
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("Hello", 8, ' '), "Hello   ");
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("Hello", 8, ' '), "   Hello");
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("Hello World", "World", "abcd"), "Hello abcd");
}

TEST(StringUtilsTest, Split){
    auto result = StringUtils::Split("Hello World", " ");
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], "Hello");
    EXPECT_EQ(result[1], "World");
}

TEST(StringUtilsTest, Join){
    std::vector<std::string> vec = {"Hello", "World"};
    EXPECT_EQ(StringUtils::Join(" ", vec), "HelloWorld");
}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(StringUtils::ExpandTabs("Hello\tWorld", 4), "Hello    World");
    EXPECT_EQ(StringUtils::ExpandTabs("abc\t\t  abc", 4), "abc          abc");
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("Hello", "Holla", false), 2);
    EXPECT_EQ(StringUtils::EditDistance("Hello", "hello", true), 0);
    EXPECT_EQ(StringUtils::EditDistance("Hello", "hwweq", true), 4);
}
