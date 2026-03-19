#include <iostream>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int ans = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            ans = mid;
            right = mid -1;
        } 
        else if (arr[mid] < target) {
            left = mid + 1;

        } 
        else {
            right = mid - 1;

        }
    }
    
    return ans; // Target not found
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Element found at index " << binarySearch(arr,n,40);
    return 0;
}