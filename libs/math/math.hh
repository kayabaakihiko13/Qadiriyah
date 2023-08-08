#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

// #include <cmath>
#include<cmath>
#include <initializer_list>
#include <iostream>
#include <vector>

namespace qadiriyah {

/**
 * @brief Calculate the sum of a vector of numbers.
 * 
 * @tparam T The data type of the numbers.
 * @param numbers The vector of numbers to sum.
 * @return The sum of the numbers.
 */
template <typename T>
T sum_vec(const std::vector<T> &numbers) {
  // initialize the sum to 0
  T result = 0;
  // iterate over the numbers in the vector and add them to the sum
  for (const T &number : numbers) {
    result += number;
  }
  // return result
  return result;
}

/**
 * @brief Calculate the sum of numbers in an initializer list.
 * 
 * @tparam T The data type of the numbers.
 * @param numbers The initializer list of numbers to sum.
 * @return The sum of the numbers.
 */
template <typename T>
T sum_vec(std::initializer_list<T> numbers) {
  T result = 0;
  for (const T &number : numbers) {
    result += number;
  }
  return result;
}

/**
 * @brief Calculate the factorial of a non-negative integer.
 * 
 * @param number The non-negative integer.
 * @return The factorial of the input number.
 */
inline int calculate_factorial(int number) {
  // check if the input value is non negaive
  if (number < 0) {
    // return -1 for invalid input
    return -1;
  }
  // initialize the factorial to 1
  int factorial = 1;
  for (int i = 2; i <= number; ++i) {
    // multiply factorial by each integer up to 'number'
    factorial *= i;
  }
  // return the calculated factorial
  return factorial;
}

/**
 * @brief Calculate the power of a number with support for negative bases and integer exponents.
 * 
 * @tparam T The data type of the number.
 * @param number The base number.
 * @param rank The exponent.
 * @return The result of the power operation.
 */
template <typename t>
t power(t number, double rank) {
  if (number < 0 && rank == static_cast<int>(rank)) {
    int intrank = static_cast<int>(rank);
    if (intrank % 2 == 0) {
      return std::pow(std::abs(number), intrank);
    } else {
      return -std::pow(std::abs(number), intrank);
    }
  } else {
    return std::pow(number, rank);
  }
}

/**
 * @brief Calculate combinations (n choose k).
 * 
 * @param n The total number of items.
 * @param k The number of items to choose.
 * @return The calculated combination value.
 */
inline int combi(int n, int k) {
  // know the contents of the numerator,call factorial with value param n
  int numerator = calculate_factorial(n);
  // know the contents of the denominator,call favtorial with param n and k
  int denominator = calculate_factorial(k) * calculate_factorial(n - k);
  return numerator / denominator;
}

/**
 * @brief Calculate permutations (n P k).
 * 
 * @param n The total number of items.
 * @param k The number of items to choose (default is n).
 * @return The calculated permutation value.
 */
inline int permutation(int n, int k = 0) {
  // if value params k equal zero,k value is equal with n
  if (k == 0) {
    k = n;
  }
  // know the contents of the numerator,call factorial with value param n
  int numerator = calculate_factorial(n);
  // know the contents of the denominator,call favtorial with param n and k
  int denominator = calculate_factorial(n - k);
  return numerator / denominator;
}

/**
 * @brief Calculate the value of Euler's number (e) using a Taylor series approximation.
 * 
 * @return The value of Euler's number.
 */
inline double e() {
  // the name of algorithm is talyor series
  // this variabel iterable for result be good and approach
  // with a real value
  int n = 10;
  double result = 1.0;
  for (int i = 1; i <= n; ++i) {
    result += 1.0 / calculate_factorial(i);
  }
  return result;
}

/**
 * @brief Calculate the value of e raised to the power of x.
 * 
 * @param x The exponent.
 * @return The result of e^x.
 */
inline double exponent(double x) {
  /*
   * @brief exponent is math formula from
   * equation power of euler number and param
   * of x
   */
  return power(e(), x);
}

/**
 * @brief Calculate the absolute value of a number.
 * 
 * @tparam T The data type of the value.
 * @param value The input value.
 * @return The absolute value of the input.
 */
template <typename T>
T abs(T value) {
  // if value less than 0,the value be negative
  if (value < 0) {
    // this return same like -1 * value
    return -value;
  } else {
    return value;
  }
}

/**
 * @brief Calculate the binomial expansion of (x + 1)^n using combinations and powers.
 * 
 * @param x The base value.
 * @param n The exponent.
 * @return The result of the binomial expansion.
 */
inline long int binomial(int x, int n) {
  // binominal is a polynominal that is the sum of two monominal
  double result = 0;
  for (int k = 0; k <= n; ++k) {
    // calculate every combination and power rank value
    result += combi(n, k) * power(x, k);
  }
  return result;
}

/**
 * @brief Calculate the natural logarithm using Mercator's series approximation.
 * 
 * @tparam T The data type of the input.
 * @param x The input value.
 * @return The calculated natural logarithm.
 */
template <typename T>
double natural_log(T x) {
  /**
   * @brief natural logarithm is math formula
   * from equation from Mercator' Series with base
   * constant eular value.
  */

  // euler constant value
  const double epsilon = 1e-10;

  double yn = x - 1.0;
  double yn1 = yn;
  yn = yn1;
  do {
    yn1 = yn + 2 * (x - exponent(yn)) / (x + exponent(yn));
  } while (abs(yn - yn1) > epsilon);
  return yn1;
}

/**
 * @brief Calculate the square root using the Newton-Raphson method.
 * 
 * @tparam T The data type of the input.
 * @param x The input value.
 * @return The calculated square root.
 */
template <typename T>
float square_value(T x) {
  // Increase the number of iterations for better accuracy
  const int iterations = 20;
  // Initialize as float
  float r = static_cast<float>(x);
  if (x < 0) {
    std::cerr << "Value must be greater than or equal to 0.\n";
  } else {
    for (int i = 1; i <= iterations; ++i) {
      // Use static_cast to ensure float division
      r = (r + x / r) / 2;
    }
  }
  return r;
}

/**
 * @brief Calculate the logarithm with a specified base using the natural logarithm.
 * 
 * @tparam T The data type of the inputs.
 * @param X The input value.
 * @param base The desired base.
 * @return The calculated logarithm.
 */
template <typename T>
float log_base(T X, int base) {
    /**
   * @brief the logarithm is a mathematical function
   * defined by equation from Mercator's series,
   * with the base being the constant Eular's value.
  */
  if (base < 0) {
    std::cerr << "Base value must greater than or equal to\n";
  }
  // the calculate division of natural log param X and base
  return natural_log(X) / natural_log(base);
}

/**
 * @brief Calculate the base-10 logarithm using the natural logarithm.
 * 
 * @tparam T The data type of the input.
 * @param x The input value.
 * @return The calculated base-10 logarithm.
 */
template <typename T>
double log10(T x) {
  if (x < 0) {
    std::cerr << "Value lower than 0 can't be calculate" << std::endl;
  }
  // calculate division of natural logarith x value with 10 as base
  return natural_log(x) / natural_log(10);
}

/**
 * @brief Calculate the nth Fibonacci number.
 * 
 * @param n The index of the Fibonacci number to calculate.
 * @return The calculated nth Fibonacci number.
 */
inline long int fibonacci(int n) {
  int a = 0, b = 1;
  for (int i = 2; i <= n; ++i) {
    int temp = a;
    a = b;
    b = temp + a;
  }
  return b;
}

/**
 * @brief Calculate the nth Bell number using dynamic programming.
 * 
 * @param n The index of the Bell number to calculate.
 * @return The calculated nth Bell number.
 */
inline long long int bell_num(int n) {
  int bell[n + 1][n + 1];
  bell[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    bell[i][0] = bell[i - 1][i - 1];
    for (int j = 1; j <= i; ++j) {
      //  Calculate Bell numbers using previous values
      bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
  }
  
  // return the calculated bell number
  return bell[n][0];
}
}  // namespace qadiriyah

#endif
