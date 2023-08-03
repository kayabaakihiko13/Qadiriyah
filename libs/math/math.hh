#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <vector>

namespace qadiriyah {

// calculate the sum of a vector of numbers
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

template <typename T>
T sum_vec(std::initializer_list<T> numbers) {
  T result = 0;
  for (const T &number : numbers) {
    result += number;
  }
  return result;
}

inline int calculate_factorial(int number) {
  // check if the input value is non negaive
  if (number < 0) {
    return -1;
  }
  // initialize the factorial to 1
  int factorial = 1;
  for (int i = 2; i <= number; ++i) {
    factorial *= i;
  }
  return factorial;
}

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

inline int combi(int n, int k) {
  int numerator = calculate_factorial(n);
  int denominator = calculate_factorial(k) * calculate_factorial(n - k);
  return numerator / denominator;
}

inline int permutation(int n, int k = 0) {
  if (k == 0) {
    k = n;
  }
  int numerator = calculate_factorial(n);
  int denominator = calculate_factorial(n - k);
  return numerator / denominator;
}

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

inline double exponent(double x) {
  /*
   * @brief exponent is math formula from
   * equation power of euler number and param
   * of x
   */
  return power(e(), x);
}

template <typename T>
T abs(T value) {
  if (value < 0) {
    return -value;
  } else {
    return value;
  }
}

inline long int binomial(int x, int n) {
  double result = 0;
  for (int k = 0; k <= n; ++k) {
    result += combi(n, k) * power(x, k);
  }
  return result;
}

template <typename T>
double natural_log(T x) {
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

// @brief square function is to calculate
// a square of value.
// @param x this a input value we wont calculate
// return a result decimal number

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

template <typename T>
float log_base(T X, int base) {
  if (base < 0) {
    std::cerr << "Base value must greater than or equal to\n";
  }
  return natural_log(X) / natural_log(base);
}

template <typename T>
double log10(T x) {
  if (x < 0) {
    std::cerr << "Value lower than 0 can't be calculate" << std::endl;
  }
  return natural_log(x) / natural_log(10);
}

inline long int fibonacci(int n) {
  int a = 0, b = 1;
  for (int i = 2; i <= n; ++i) {
    int temp = a;
    a = b;
    b = temp + a;
  }
  return b;
}

inline long long int bell_num(int n) {
  int bell[n + 1][n + 1];
  bell[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    bell[i][0] = bell[i - 1][i - 1];
    for (int j = 1; j <= i; ++j) {
      bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }
  }

  return bell[n][0];
}
}  // namespace qadiriyah

#endif
