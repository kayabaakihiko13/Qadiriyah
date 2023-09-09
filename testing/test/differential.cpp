#include "../../libs/scientific/differential.hh"
#include "gtest/gtest.h"

TEST(DifferentialTest, DerivativeFunction) {
  auto func = [](float x) { return x * x; };

  float x = 2.0f;
  float expected = 4.0f;
  float derivative_value = differential::derivative(func, x);
  EXPECT_EQ(derivative_value, expected);
}


TEST(DifferentialTest,PowerDerivativeFunction){

  int n = 6;
  float input_value = 2.0f;
  float result = differential::power_derivative(n,input_value);
  float expected = 192.0f;
  EXPECT_EQ(result,expected);

}

TEST(DifferentialTest,ProductDerivate){

  auto func1 = [](float x) {return x * x ;};
  auto func2 = [](float x) {return x * x *x; };
  float input_value = 2.0f;
  float result = differential::product_derivate(func1,func2,input_value);
  float expected = 64.0f;
  EXPECT_EQ(result,expected);

}

TEST(DifferentialTest,QuotientDerivate){
  auto func1 = [](float x) {return x * x;};
  auto func2 = [](float x) {return x;};
  float input_value = 2.0f;
  float result = differential::quotient_derivate(func1,func2,input_value);

}