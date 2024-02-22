
#include <array>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

class ReverseArray {
private:
    void printArray(std::array<int, 7> arr, int size) {
        for (int i : arr) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }

    // Approach #1
    std::array<int, 7> extra(std::array<int, 7> arr, int size) {
        std::array<int, 7> temp;
        for (int i{0}; i < size; i++) {
            temp[(size-1)-i] = arr[i];
        }

        return temp;
    }

    // Approach #2
    std::array<int, 7> swap(std::array<int, 7> arr, int size) {
        int start = 0;
        int end = size - 1;

        while (arr[start] < arr[end]) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }

        return arr;
    }

    // Approach #3
    std::array<int, 7> methods(std::array<int, 7> arr, int size) {
        std::reverse(arr.begin(), arr.end());

        return arr;
    }

    // Approach #4
    void recursion(std::array<int, 7>& arr, int start, int end) {
        if (start >= end)
            return;
        
        // swap beginning and last
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // re-call function + 1
        recursion(arr, ++start, --end);
    }
    
    // Approach #5
    std::array<int, 7> usingStack(std::array<int, 7> arr, int size) {
        std::stack<int> tempStack;
        // push into stack
        for (int i : arr) {
            tempStack.push(i);
        }

        // pop and swap
        for (int i{0}; i < size; ++i) {
            arr[i] = tempStack.top();
            tempStack.pop();
        }

        return arr;
    }

public:
    void solution(std::array<int, 7> arr, int size) {
        printArray(extra(arr, size), size);
        printArray(swap(arr, size), size);
        printArray(methods(arr, size), size);

        int start = 0;
        int end = size - 1;
        std::array<int, 7> temp = arr;
        recursion(temp, start, end);
        printArray(temp, size);

        printArray(usingStack(arr, size), size);
    }
};

int main() {
    std::array<int, 7> arr = {1,2,3,4,5,6,7};
    ReverseArray cur = ReverseArray();

    cur.solution(arr, arr.size());

    return 0;
}