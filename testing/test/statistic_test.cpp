#include "../../libs/math/static.hh"
#include "gtest/gtest.h"

TEST(MeanVectTest, VectorOfInteger) {
  // create a vector of integers
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // calculate the mean of the numbers in vectors
  float expected = 3.0;
  float actual = mean(numbers);
  EXPECT_EQ(expected, actual);
}

TEST(MeanVectTest, VectorOffloat) {
  // calculate them mean of the numbers in vectors
  std::vector<float> numbers = {1.0, 2.0, 3.0, 4.0, 6.0};
  // Calculate the sum of the
  float actual = mean(numbers);
  float expected = 3.2;
  EXPECT_EQ(expected, actual);
}

TEST(MedianVecTest, OddVectorOfInteger) {
    // make vector unit testing
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // this line for expected value from that calculation
    int expected = 3;
    // this line what the output from the function
    int actual = _median(numbers);

    EXPECT_EQ(expected, actual);
}

TEST(MedianVecTest, EvenVectorOfFloat) {
  std::vector<float> numbers = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    // this line for expected value from that calculation.
    float expected = 3.5;
    // this line what the output from the function
    float actual = static_cast<float>(_median(numbers));

  EXPECT_EQ(expected, actual);
}

TEST(ModeVecTest, VectorOfInteger) {
    // make units test vector
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 4, 4, 5};

    // this line for expeted value from Mode calculation
    int expected = 4;
    int actual = _mode(numbers);
  EXPECT_EQ(expected, actual);
}

TEST(ModeVecTest, VectorOfFloat) {
  std::vector<float> numbers = {1.0, 2.0, 2.0, 3.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0};
  float expected = 3;
  float actual = _mode(numbers);
  EXPECT_EQ(expected, actual);
}

TEST(ModeVecTest, VectorOfSChar) {
  // make vector is include character
  std::vector<std::string> units = {"a", "a", "a", "b", "c"};
  std::string expected = "a";
  std::string actual = _mode(units);
  EXPECT_EQ(expected, actual);
}

TEST(ModeVecTest, VectorOfString) {
  std::vector<std::string> units = {"apple", "orange", "manggo", "manggo"};
  std::string expected = "manggo";
  std::string actual = _mode(units);
  EXPECT_EQ(expected, actual);
}

TEST(VarVecTest, VecOfFloat) {
  std::vector<float> numbers = {1.0, 2.0, 3.0, 4.0};
  float expected = 1.25;
  float actual = variance(numbers);
  EXPECT_EQ(expected, actual);
}

TEST(VarVecTest, VecOfNegativeNumber) {
    // this line for unit test vakye for calculation Variation with
    // include negative number in array variabel
    std::vector<float> numbers = {1.0, -2.0, 3.0, 4.0};
    // this line for expected value from that calculation.
    float expected = 5.25;
    // this line what the output from the function
    float actual = variance(numbers);
    EXPECT_EQ(expected, actual);
}

TEST(CovVecTest, VecOfFloat) {
    // this line for unit test value for Covariance Test
    std::vector<float> x = {1.0, 2.0, 3.0, 4.0};
    std::vector<float> y = {2.0, 3.0, 4.0, 5.0};
    // this line expeted what the that calculation
    float expected = 1.25;
    float actual = Covariance(x, y);
    // the result
    EXPECT_EQ(expected, actual);
}
