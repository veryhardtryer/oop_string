#include <gtest/gtest.h>

#include <iostream>

TEST(TMP, JustWork) {
  std::cout << "Hello, testing!" << std::endl;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}