#include <gtest/gtest.h>
#include <iostream>
#include <istream>
#include <algorithm>

#include <lab_string.hpp>

#include <dynamic_array.hpp>
#include <dynamic_array.cpp>

using namespace stdlike;

using StringArray = Array<String>;

TEST(STRING, JustWork) {
  String a;
  String c("Hello, string!");
  String d(c);

  String f(10);
  a = std::move(f);
  ASSERT_FALSE(a == f);

  a = c;
  ASSERT_EQ(a, c);
  ASSERT_EQ(c, d);
  a = std::move(c);
  ASSERT_FALSE(a == c);
}

TEST(STRING, Compare) {
  String a("aaaab");
  String a_copy(a);
  String b("abcd");
  String c("dcba");

  ASSERT_EQ(a, a_copy);
  ASSERT_TRUE(a < b);
  ASSERT_TRUE(c > b);
}

TEST(STRING, Features) { 
  srand(static_cast<unsigned int>(std::time(0)));
  String a = GenerateRandom(100);
  String b = GenerateRandom(100);

  ASSERT_TRUE(a != b);
}

TEST(STRING, Stream) {
  String a = "Hello, world!";
  std::cout << "Test nothing, just printing string" << std::endl;
  std::cout << a << std::endl;
}

#ifdef __GNUC__
TEST(STRINGARRAY, Algorithm) {
  StringArray a;
  std::cout << "Test nothing, just printing strings\n" << std::endl;
  for(size_t i = 0; i < 8; ++i) {
    a.PushBack(GenerateRandom(rand() % 30));
  }

  std::cout << "Init order of strings:\n" << std::endl;
  for(auto s : a) {
    std::cout << s << std::endl;
  }
  std::cout << "================================\n" << std::endl;

  std::sort(a.begin(), a.end(), [](auto a, auto b){
    return a < b;
  });

  std::cout << "Alphabetical order of strings:\n" << std::endl;
  for(auto s : a) {
    std::cout << s << std::endl;
  }
  std::cout << "================================\n" << std::endl;

  std::sort(a.begin(), a.end(), [](auto a, auto b){
    return a.Size() < b.Size();
  });

  std::cout << "Length order of strings:\n" << std::endl;
  for(auto s : a) {
    std::cout << s << std::endl;
  }
  std::cout << "================================\n" << std::endl;

  auto f = a[rand() % 8];
  std::cout << "Try to find '" << f << "' string" << std::endl;
  auto it = std::find(a.begin(), a.end(), f);
  if(it != a.end()) {
    size_t pos = std::distance(a.begin(), it);
    std::cout << "position: " << pos << std::endl;
  }
}
#endif

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}