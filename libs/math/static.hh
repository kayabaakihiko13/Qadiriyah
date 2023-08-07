
#include <algorithm>
#include <vector>

#include "../math/math.hh"

template <typename T>
float mean(std::vector<T>& arr) {
  float result = 0;
  for (int i = 0; i < arr.size(); ++i) {
    result += arr[i];
  }
  result /= arr.size();
  return result;
}

// median
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
//
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
        max_count = current_count;
        max_element = arr[i];
      }
    } else {
      // Reset the count for the new element
      current_count = 1;
    }
  }

  return max_element;
}

template <typename T>
float variance(std::vector<T>& arr) {
  float mean_values = mean(arr);
  float result = 0;
  for (int i = 0; i < arr.size(); ++i) {
    float diff = arr[i] - mean_values;
    result += pow(diff, 2);
  }
  result /= arr.size();
  return result;
}

template <typename T>
float StandardDev(std::vector<T>& arr) {
  float mean_value = mean(arr);
  float result = 0;
  for (int i = 0; i < arr.size(); ++i) {
    float diff = pow(arr[i] - mean_value, 2);
    result += diff;
  }
  result /= arr.size();

  return qadiriyah::square_value(result);
}

template <typename T>
float Covariance(std::vector<T>& arrX, std::vector<T>& arrY) {
  float mean_x = mean(arrX);
  float mean_y = mean(arrY);
  float result = 0;
  for (int i = 0; i < arrX.size(); ++i) {
    float diffX = (arrX[i] - mean_x);
    float diffY = (arrY[i] - mean_y);
    result += (diffX * diffY);
  }
  result /= arrX.size();
  return result;
}
