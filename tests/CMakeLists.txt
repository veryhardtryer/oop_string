set(TEST_NAME string_unit_tests)

enable_testing()

add_executable(${TEST_NAME} unit.cpp)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

target_link_libraries(${TEST_NAME} PRIVATE gtest_main string_lab)