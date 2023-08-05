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

TEST(MeanVectTest,VectorOffloat){
    // calculate them mean of the numbers in vectors
    std::vector<float> numbers = {1.0,2.0,3.0,4.0,6.0};
    // Calculate the sum of the
    float actual = mean(numbers);
    float expected = 3.2;
    EXPECT_EQ(expected,actual);
}

TEST(MedianVecTest,OddVectorOfInteger){
    // make vector unit testing
    std::vector<int> numbers = {1,2,3,4,5};
    
    int expected = 3;
    int actual = _median(numbers);
    
    EXPECT_EQ(expected,actual);
}

TEST(MedianVecTest,EvenVectorOfFloat){
    std::vector<float> numbers = {1.0,2.0,3.0,4.0,5.0,6.0};
    // expected value is
    float expected = 3.5;
    float actual = static_cast<float>(_median(numbers));

    EXPECT_EQ(expected,actual);
}

TEST(ModeVecTest,VectorOfInteger){
    // make units test vector
    std::vector<int> numbers = {1,2,2,3,4,4,4,4,5};
    int expected = 4;
    int actual = _mode(numbers);
    EXPECT_EQ(expected,actual);
}

TEST(ModeVecTest,VectorOfFloat){
    std::vector<float> numbers = {1.0,2.0,2.0,3.0,3.0,3.0,4.0,4.0,5.0,5.0};
    float expected = 3;
    float actual = _mode(numbers);
    EXPECT_EQ(expected,actual);
}

TEST(ModeVecTest,VectorOfString){
    std::vector<std::string> units = {"a","a","a","b","c"};
    std::string expected = "a";
    std::string actual= _mode(units);
    EXPECT_EQ(expected,actual);

}