#include <iostream>
#include <array>
#include "merge_sort.h"

template <typename T, size_t N>
void printArray(std::array<T,N> arr) {
    for (T element : arr) {
        std::cout << element << std::endl;
    }
};

int main () {
    std::array<int,10> ourArr {11, 24, 39, 86, 44, 9, 12, 77, 98, 38};
    ourArr = merge_sort(ourArr);
    printArray(ourArr);

    std::array<std::string,5> names {"Matteo", "Brentegani", "Mario", "Luigi", "Peach"};
    names = merge_sort(names);
    printArray(names);

    return 0;
}