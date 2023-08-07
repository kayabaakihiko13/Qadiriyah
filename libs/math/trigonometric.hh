#include <iostream>
#include <random>
#include <typeinfo>
#include <vector>

#include "../math/math.hh"
#include "../utils/constant.h"

double estimate_pi() {
  const int iterable = 1000000;
  double result = 0.0;
  int sign = 1;
  for (int i = 0; i <= iterable; ++i) {
    result += sign / (2.0 * i + 1.0);
    sign *= -1;
  }
  return 4.0 * result;
}

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

template <typename T>
double distance(const std::vector<T> &a, const std::vector<T> &b) {
  double result = 0.0;

  for (int i = 0; i < a.size(); ++i) {
    double calculate = square_value(sum(power(a[i] - b[i])));
    result += calculate;
  }

  return result;
}
