#include <iostream>
#include <cstddef>

template <typename T>
void sortt(T arr[], std::size_t size, bool (*cmp)(T, T)) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        for (std::size_t j = i + 1; j < size; ++j) {
            if (cmp(arr[j], arr[i])) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename T>
inline bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a > b;
}

int main() {
    int arr1[] = { 5, 2, 9, 1, 7 };
    double arr2[] = { 3.2, 1.1, 5.5, 2.8, 4.0 };

    std::size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    sortt(arr1, size1, ascending<int>);
    std::cout << "Int uzlazno: ";
    for (auto x : arr1) std::cout << x << " ";
    std::cout << "\n";

    sortt(arr1, size1, descending<int>);
    std::cout << "Int silazno: ";
    for (auto x : arr1) std::cout << x << " ";
    std::cout << "\n\n";

    sortt(arr2, size2, ascending<double>);
    std::cout << "Double uzlazno: ";
    for (auto x : arr2) std::cout << x << " ";
    std::cout << "\n";

    sortt(arr2, size2, descending<double>);
    std::cout << "Double silazno: ";
    for (auto x : arr2) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
