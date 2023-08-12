#include <iostream>
#include <random>
#include <typeinfo>
#include <vector>

#include "../math/math.hh"
#include "../utils/constant.h"

/**
 * @brief Estimate the value of pi using the Leibniz formula.
 * 
 * @return The estimated value of pi.
 */
double estimate_pi() {
  const int iterable = 1000000;
  double result = 0.0;
  int sign = 1;
  for (int i = 0; i <= iterable; ++i) {
    // Calculate the sum using the Leibniz formula
    result += sign / (2.0 * i + 1.0);
    // Alternate the sign for each term
    sign *= -1;
  }
  // Multiply by 4 to get an estimate of pi
  return 4.0 * result;
}

/**
 * @brief Calculate the sine of an angle in radians.
 * 
 * @tparam T The data type of the input angle.
 * @param x The input angle in radians.
 * @return The calculated sine value.
 */
template <typename T>
double sin(T x) {
  // convert parameter from radians to degrees
  x *= (estimate_pi() / 180);
  int iterable = 4;
  double result = 0.0;
  for (int n = 0; n <= iterable; ++n) {
    result += (pow(-1, n) * (pow(x, 2 * n + 1) / (qadiriyah::calculate_factorial(2 * n + 1))));
  }
  return result;
}

/**
 * @brief Calculate the cosine of an angle in radians.
 * 
 * @tparam T The data type of the input angle.
 * @param x The input angle in radians.
 * @return The calculated cosine value.
 */
template <typename T>
double cos(T x) {
  // convert parameter from radians to degrees
  x *= (estimate_pi() / 180);
  int iterable = 4;
  double result = 0.0;
  for (int n = 0; n <= iterable; ++n) {
    result += (pow(-1, n) * (pow(x, 2 * n) / (qadiriyah::calculate_factorial(2 * n))));
  }
  return result;
}

/**
 * @brief Calculate the tangent of an angle in radians.
 * 
 * @tparam T The data type of the input angle.
 * @param x The input angle in radians.
 * @return The calculated tangent value.
 */
template <typename T>
double tan(T x) {
  // convert parameter from radians to degrees
  x *= (estimate_pi() / 180.0);

  int iterable = 4;
  double result = 0.0;
  int sign = 1;

  for (int n = 0; n <= iterable; ++n) {
    result += (sign * power(x, 2 * n - 1) / qadiriyah::calculate_factorial(2 * n - 1));
    sign -= sign;
  }

  return result;
}

/**
 * @brief Calculate the squared Euclidean distance between two vectors.
 * 
 * @tparam T The data type of the vector elements.
 * @param a The first vector.
 * @param b The second vector.
 * @return The calculated squared Euclidean distance.
 */
template <typename T>
double distance(const std::vector<T> &a, const std::vector<T> &b) {
  double result = 0.0;

  for (int i = 0; i < a.size(); ++i) {
    // Calculate the squared difference between elements and sum them up
    double calculate = square_value(sum(power(a[i] - b[i])));
    // Accumulate the squared differences
    result += calculate;
  }
  // Return the squared Euclidean distance
  return result;
}
