#include "../../libs/scientific/differential.hh"
#include "gtest/gtest.h"

TEST(DifferentialTest, DifferentialFunctionTest) {
  float(*func)(float) = [](float x) { return x * x; };
  float x = 2.0f;
  float expected = 3.8147;
  float tolerance = 1e-4;
  float derivative_value = differential::derivative(func, x);
  EXPECT_NEAR(derivative_value, expected, tolerance);
}