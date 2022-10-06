#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <array>
#include <tuple>

template<typename T, size_t N>
std::tuple<std::array<T,(N/2)>, std::array<T,(N-(N/2))>> split (const std::array<T,N>& arr) {
    //splits an array into 2, then returns a tuple with the 2 arrays as elements
    std::array<T,(N/2)> left_array {};
    std::array<T,(N-(N/2))> right_array {};

    for (size_t i{}; i < (N/2); i++)
        left_array[i] = arr[i];

    for (size_t i{}; i < (N-(N/2)); i++)
        right_array[i] = arr[(left_array.size()+i)];

    return {left_array, right_array};
};

template<typename T, size_t N1, size_t N2>
std::array<T,(N1+N2)> merge_arrays(std::array<T,N1>& left, std::array<T,N2>& right) {
    //Takes two arrays and merges them into one, sorting them in the process
    std::array<T,(N1+N2)> merged_list{};
    
    typename std::array<T,N1>::iterator left_it {left.begin()};
    typename std::array<T,N2>::iterator right_it {right.begin()};
    
    for (size_t i {}; i < merged_list.size(); i++) {
        if (left_it == left.end()){
            merged_list[i] = *right_it;
            right_it++;
        }
        else if (right_it == right.end()){
            merged_list[i] = *left_it;
            left_it++;
        }
        else if (*left_it > *right_it){
            merged_list[i] = *right_it;
            right_it++;
        }
        else if (*left_it <= *right_it) {
            merged_list[i] = *left_it;
            left_it++;
        }
    }

    return merged_list;
};

template <typename T, size_t N>
std::array<T,N> merge_sort (std::array<T,N>& arr) {
    //Sorts an array by dividing it into sub-arrays and then merging them back into one
    if (arr.size() < 2)
        return arr;

    else {
        //splits the array in 2 parts and assigns them to 2 new arrays
        std::tuple<std::array<T,(N/2)>, std::array<T,(N-N/2)>> splitted_arrs {split(arr)};
        std::array<T,(N/2)> leftHalf {std::get<0>(splitted_arrs)};
        std::array<T,(N-N/2)> rightHalf {std::get<1>(splitted_arrs)};

        //recursively repeats the function on the 2 sub-arrays, then merges them
        leftHalf = merge_sort(leftHalf);
        rightHalf = merge_sort(rightHalf);
        std::array<T,N> mergedArr {merge_arrays(leftHalf, rightHalf)};

        return mergedArr;
    }
};

#endif //_MERGE_SORT_H_