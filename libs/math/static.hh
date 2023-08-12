
#include <algorithm>
#include <vector>
#include <iostream>
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
  /**
   * Describe
   * ----
   * Mean is a measure of sum of vector value
   * division by size of array
   * 
   * Params
   * ----
   * param arr is represents an input array of values
  */
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
float variance(std::vector<T>& arr,int ddof=0) {
  /**
   * Describetion
   * ---
   * variance is a statical model for measure of dispresion,in
   * other word it is a measure of how of a random variabel.
   * variance can be impact to data distribution and skewness
   * 
   * Params
   * ---
   * param arr represents an input array of values
   * param ddof indicates whether to calculate mode Population 
   * or Sample.
  */
  float sum = 0;
  for (int i = 0; i < arr.size(); ++i) {
    sum += qadiriyah:: power(arr[i]-mean(arr), 2);
  }
  return sum/(arr.size()-ddof);
}

/**
 * @brief Calculate the standard deviation of a vector of values.
 * 
 * @tparam T The data type of the values.
 * @param arr The vector of values.
 * @return The calculated standard deviation.
 */
template <typename T>
float StandardDev(std::vector<T>& arr,int ddof=0) {
  /**
   * Description
   * ----
   * Standard Deviation is measure how many individual data
   * point is away from the mean of dataset.it's calculated
   * using the formula
   * 
   * Params
   * ---
   * param arr is represents an input array of values
   * param ddof indicates whether to calculate the mode for
   * a population or sample.
  */
  float sum = 0;
  for (int i = 0; i < arr.size(); ++i) {
    sum += qadiriyah:: power(arr[i] - mean(arr), 2);
  }
  return qadiriyah::square_value(sum/(arr.size() - ddof));
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
float Covariance(std::vector<T>& arrX,std::vector<T>& arrY,int ddof=0) {
  /**
   * Description
   * ----
   * Covariance is a measure similiar variability of two data independent.
   * if Covariance more than 0 relation is strong,if else covariance less than 0 relation is weak
   * else no have releation
   * 
   * Params
   * ----
   * param arrX is represents an input array of values
   * param arrY is represents an input array of values
   * param ddof indicates whether to calculate the mode for
   * a population or sample.
  */
  if (arrX.size() != arrY.size()){
    std::cerr<<"Size X and Y is not Same";
  }
  float result = 0;
  for (int i = 0; i < arrX.size(); ++i) {
    result += ((arrX[i] - mean(arrX)) * (arrY[i] - mean(arrY)));
  }
  return result/(arrX.size()-ddof);
}

template <typename T>
float Correlation(std::vector<T>& arrX,std::vector<T>& arrY){
  /**
   * Correlation is a statical relationship between each of
   * data indepedent with data dependent.
   * is same with Covariance if score is less than zero is weak
   * relation,if else 0< score < 1 is strong else is no have relation
   * Params
   * ----
   * param arrX is represents an input array of values
   * param arrY is represents an input array of values
   * param ddof indicates whether to calculate the mode for
   * a population or sample.
  */

  // to check size arr X and arr Y is same

  if(arrX.size()!=arrY.size()){
    std::cerr<<"The Size is Not Same\n";
  }
  if (StandardDev(arrX) == 0 || StandardDev(arrY) == 0) {
        return 0;  // Avoid division by zero
  }
  return Covariance(arrX,arrY)/(StandardDev(arrX) * StandardDev(arrY));
}
