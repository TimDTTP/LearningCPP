
#include <array>
#include <algorithm>
#include <iostream>
#include <vector>

using intArr7 = std::array<int, 7>;

class Rotate {
public:
    // print array
    void printArray(const intArr7& arr) {
        for (const int i : arr) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }

    // print vector
    void printVector(std::vector<int> vec) {
        for (int i : vec) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }

    // Approach: Traversal
    void traversal(intArr7 arr, int size) {
        int last = arr[size - 1];
        for (int i{size-1}; i>0; --i) {
            arr[i] = arr[i-1];
        }
        arr[0] = last;

        printArray(arr);
    }

    // Approach: Pointer
    void pointer(intArr7 arr, int size) {
        int start = 0;
        int end = size - 1;
        
        for (int i{start}; i <= end; ++i) {
            std::swap(arr[i], arr[end]);
            
            ++start;
        }

        printArray(arr);
    }

    // Approach: Reversal Algorithm
    void reversal(intArr7 arr, int size) {
        // potential to perform multiple rotations
        // this case is only 1 for uniformity
        int numRotations{1};

        // reverse up to pivot point
        std::reverse(arr.begin(), arr.end() - numRotations);

        // reverse pivot to end
        // however, is redundant since we are only rotating 1 time
        std::reverse(arr.end() - numRotations, arr.end());

        // final reverse for solution
        std::reverse(arr.begin(), arr.end());

        printArray(arr);
    }
};

int main() {
    intArr7 arr = {1, 2, 3, 4, 5, 6, 7};

    Rotate cursor = Rotate();

    std::cout << "Original array: " << std::endl;
    cursor.printArray(arr);
    std::cout << std::endl;

    std::cout << "Rotated arrays: " << std::endl;
    cursor.traversal(arr, arr.size());
    cursor.pointer(arr, arr.size());
    cursor.reversal(arr, arr.size());

    return 0;
}