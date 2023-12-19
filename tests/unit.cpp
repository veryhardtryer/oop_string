#include <gtest/gtest.h>
#include <iostream>
#include <istream>

#include <lab_string.hpp>
#include <dynamic_array.hpp>

using namespace stdlike;

using StringArray = Array<String>;

TEST(STRING, JustWork) {
  String a;
  String b(5);
  String c("Hello, string!");
  String d(c);

  a = b;
  ASSERT_EQ(a, b);
  a = std::move(b);
  ASSERT_FALSE(a == b);
  ASSERT_EQ(c, d);
}

TEST(STRING, Compare) {
  String a("aaaab");
  String a_copy(a);
  String b("abcd");
  String c("dcba");

  ASSERT_EQ(a, a_copy);
  ASSERT_TRUE(a < b);
  ASSERT_TRUE(b > c);
}

TEST(STRING, Features) { 
  String a = GenerateRandom(100);
  String b = GenerateRandom(100);

  ASSERT_TRUE(a != b);
}

TEST(STRING, Stream) {
  String a = "Hello, world\n";
  std::istringstream stream;
  stream << a;
  String view = stream.str().c_str();
  ASSERT_EQ(a, view);
}

#ifdef __GNUC__
TEST(STRINGARRAY, Algorithm) {
  StringArray a;
  for(size_t i = 0; i < 8; ++i) {
    a.PushBack(GenerateRandom(rand() % 30));
  }
}
#endif

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}