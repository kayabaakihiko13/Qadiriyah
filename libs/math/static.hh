
#include <algorithm>
#include <vector>

#include "../math/math.hh"

/**
 * @brief Calculate the mean (average) of a vector of values.
 * 
 * @tparam T The data type of the values.
 * @param arr The vector of values.
 * @return The calculated mean.
 */
template <typename T>
float mean(std::vector<T>& arr) {
  float result = 0;
  for (int i = 0; i < arr.size(); ++i) {
    // sum up all values
    result += arr[i];
  }
  // divide by the number of values to get the mean
  result /= arr.size();
  return result;
}

/**
 * @brief Calculate the median of a vector of values.
 * 
 * @tparam T The data type of the values.
 * @param arr The vector of values.
 * @return The calculated median.
 */
template <typename T>
T _median(std::vector<T>& arr) {
  // sort value in vector from smallest to biggest
  std::sort(arr.begin(), arr.end());
  int size_arr = arr.size();
  // for even size
  if (size_arr % 2 == 0) {
    int cursor = size_arr / 2 - 1;

    T result = static_cast<float>(arr[cursor] + arr[cursor + 1]) / 2.0f;

    return result;
  }
  // this for odd size
  else {
    T result = arr[size_arr / 2];
    return result;
  }
}

/**
 * @brief Calculate the mode (most frequent value) of a vector of values.
 * 
 * @tparam T The data type of the values.
 * @param arr The vector of values.
 * @return The calculated mode.
 */
template <typename T>
T _mode(std::vector<T>& arr) {
  // sorrting from smallest to biggest
  std::sort(arr.begin(), arr.end());
  T max_element = arr[0];
  int max_count = 1;
  int current_count = 1;
  T current_element = arr[0];
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] == arr[i - 1]) {
      // Current element is the same as the previous one
      current_count++;

      // Check if the current element has a higher count than the maximum element
      if (current_count > max_count) {
        // Update max_count if current_count is larger
        max_count = current_count;
        // Update max_element with the current element
        max_element = arr[i];
      }
    } else {
      // Reset the count for the new element
      current_count = 1;
    }
  }
  // areturn the mode
  return max_element;
}

/**
 * @brief Calculate the variance of a vector of values.
 * 
 * @tparam T The data type of the values.
 * @param arr The vector of values.
 * @return The calculated variance.
 */
template <typename T>
float variance(std::vector<T>& arr) {
  // calculate the mean of the values
  float mean_values = mean(arr);
  float result = 0;
  for (int i = 0; i < arr.size(); ++i) {
    float diff = arr[i] - mean_values;
    // sum of squared deifference from the mean
    result += pow(diff, 2);
  }
  // Divide by the number of values to get the variance
  result /= arr.size();
  return result;
}

/**
 * @brief Calculate the standard deviation of a vector of values.
 * 
 * @tparam T The data type of the values.
 * @param arr The vector of values.
 * @return The calculated standard deviation.
 */
template <typename T>
float StandardDev(std::vector<T>& arr) {
  // Calculate the mean of the values
  float mean_value = mean(arr);
  float result = 0;
  for (int i = 0; i < arr.size(); ++i) {
    float diff = pow(arr[i] - mean_value, 2);
    // Sum of squared differences from the mean
    result += diff;
  }
  // Divide by the number of values
  result /= arr.size();

  // Calculate the square root of the result using square_value function from qadiriyah namespace
  return qadiriyah::square_value(result);
}

/**
 * @brief Calculate the covariance between two vectors of values.
 * 
 * @tparam T The data type of the values.
 * @param arrX The first vector of values.
 * @param arrY The second vector of values.
 * @return The calculated covariance.
 */
template <typename T>
float Covariance(std::vector<T>& arrX, std::vector<T>& arrY) {
  // Calculate the mean of the first vector
  float mean_x = mean(arrX);
  // Calculate the mean of the second vector
  float mean_y = mean(arrY);
  float result = 0;
  for (int i = 0; i < arrX.size(); ++i) {
    float diffX = (arrX[i] - mean_x);
    float diffY = (arrY[i] - mean_y);
    // Sum of products of differences from means
    result += (diffX * diffY);
  }
  // Divide by the number of values
  result /= arrX.size();
  return result;
}
