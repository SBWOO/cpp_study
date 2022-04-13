#include <iostream>

#include <gtest/gtest.h>
#include "sum.h"

TEST(LIB_SUM_TEST, operation_test)
{
  EXPECT_EQ(2, sum(1, 1));
  EXPECT_EQ(5, sum(3, 2));
}
TEST(LIB_SUM_TEST, fault_test)
{
  EXPECT_NE(6, sum(1, 3));
  EXPECT_NE(7, sum(1, 5));
}

class QueueTest : public ::testing::Test {
protected:
  void SetUp() override {
    a = 1;
    b = 2;
    c = 3;
  }
  int a;
  int b;
  int c;
};

TEST_F(QueueTest, SUM_WORKS)
{
  EXPECT_EQ(3, sum(a, b));
  EXPECT_EQ(5, sum(b, c));
  EXPECT_EQ(6, sum(a, sum(b, c)));
}

