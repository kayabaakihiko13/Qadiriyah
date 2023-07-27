#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <iostream>
#include <vector>

template <typename T>
T sum_vec(const std::vector<T>& numbers) {
    T result = 0;
    for (const T& number : numbers) {
        result += number;
    }
    return result;
}


int factorial_number(int number) {
    if (number < 0) {
        std::cerr << "Number must be non-negative.\n" << std::endl;
        return -1;
    }

    if (number == 0 || number == 1) {
        return 1;
    }

    int factorial = 1;
    for (int i = 2; i <= number; ++i) {
        factorial *= i;
    }

    return factorial;
}

template <typename T>
T power(T number, double rank) {
    if (rank < 0) {
        return 1.0 / power(number, -rank);
    } else if (rank > 0 && rank < 1) {
        return 1.0 / power(number, 1.0 / rank);
    } else {
        T result = 1;
        for (int i = 0; i < rank; ++i) {
            result *= number;
        }
        return result;
    }
}

int combi(int n, int k) {
    int numerator = factorial_number(n);
    int denominator = factorial_number(k) * factorial_number(n - k);
    return numerator / denominator;
}

int permutation(int n, int k = 0) {
    if (k == 0) {
        k = n;
    }
    int numerator = factorial_number(n);
    int denominator = factorial_number(n - k);
    return numerator / denominator;
}

double e() {
    int n = 10;
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result += 1.0 / factorial_number(i);
    }
    return result;
}

double exponent(double x) {
     // Use std::exp() for exponentiation
    return power(e(),x);
}

template <typename T>
T abs(T value) {
    if (value < 0) {
        return -value;
    } else {
        return value;
    }
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


#endif
