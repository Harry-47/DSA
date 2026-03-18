#include <iostream>

int main() {
    int arr[] {1, 3, 5, 7, 9};
    int n {sizeof(arr) / sizeof(arr[0])};
    int target {7};
    bool found {false};

    for (int i {0}; i < n; ++i) {
        if (arr[i] == target) {
            std::cout << "Element found at index " << i << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
