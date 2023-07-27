
#include <vector>
#include <algorithm>

template <typename T> float mean(std::vector<T>&arr){
    float result = 0;
    for (int i =0;i<arr.size();++i){
        result += arr[i];
    }
    result /= arr.size();
    return result;
}

// median
template <typename T> T _median(std::vector<T>&arr){
    // sort value in vector from smallest to biggest
    std::sort(arr.begin(),arr.end());
    int size_arr = arr.size(); 
    // for even size
    if (size_arr%2 == 0){
        int cursor = size_arr / 2;

        T result = arr[cursor] + arr [cursor + 1];

        result /= 2;

        return result;
    }
    // this for odd size
    else{
        T result = arr[size_arr / 2];
        return result;
    }
}
// 
template <typename T> T _mode(std::vector<T>&arr){
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