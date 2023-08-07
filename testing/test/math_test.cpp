#include "../../libs/math/math.hh"

#include "gtest/gtest.h"

using namespace qadiriyah;

TEST(SumVecTest, VectorOfIntegers) {
  // Create a vector of integers.
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // Calculate the sum of the numbers in the vector.
  int sum = sum_vec(numbers);

  // Assert that the sum is correct.
  EXPECT_EQ(sum, 15);
}

TEST(FactorialTest, PositiveNumber) {
  int number = 5;
  int expected = 120;
  int actual = calculate_factorial(number);
  EXPECT_EQ(expected, actual);
}

TEST(FactorialTest, ZeroNumber) {
  int number = 0;
  int expected = 1;
  int actual = calculate_factorial(number);
  EXPECT_EQ(expected, actual);
}

TEST(PowerTest, PositiveNumber) {
  double number = 2;
  double rank = 3;
  double expected = 8;
  double actual = power(number, rank);
  EXPECT_EQ(expected, actual);
}

TEST(PowerTest, NegativeNumber) {
  double number = -2;
  int rank = 3;
  double expected = -8;
  double actual = power(number, rank);
  EXPECT_EQ(expected, actual);
}

TEST(PowerTest, ZeroNumber) {
  double number = 0;
  double rank = 0;
  double expected = 1;
  double actual = power(number, rank);
  EXPECT_EQ(expected, actual);
}

TEST(CombiTest, PositiveNumber) {
  int n = 5;
  int k = 2;
  int expected = 10;
  int actual = combi(n, k);
  EXPECT_EQ(expected, actual);
}

TEST(CombiTest, NegativeNumber) {
  int n = -5;
  int k = -2;
  EXPECT_EQ(-1, combi(n, k));
}

TEST(CombiTest, ZeroNumber) {
  int n = 0;
  int k = 0;
  int expected = 1;
  int actual = combi(n, k);
  EXPECT_EQ(expected, actual);
}

TEST(PermutationTest, PositiveNumber) {
  int n = 5;
  int expected = 120;
  int actual = permutation(n);
  EXPECT_EQ(expected, actual);
}

TEST(PermutationTest, NegativeNumber) {
  int n = -5;
  EXPECT_EQ(-1, permutation(n));
}

TEST(PermutationTest, ZeroNumber) {
  int n = 0;
  int expected = 1;
  int actual = permutation(n);
  EXPECT_EQ(expected, actual);
}

TEST(BellNum,Iterable5){
  // this a iterable until
  int n = 5;
  int expected = 52;
  int actual = bell_num(n);
  EXPECT_EQ(expected,actual);
}
TEST (SquareValue,SquareInt){
  int n = 4;
  int expected = 2;
  int actual = square_value(n);
  EXPECT_EQ(expected,actual);
}