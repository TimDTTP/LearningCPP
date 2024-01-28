
#include <algorithm>
#include <iostream>
#include <array>

struct ValidPair {
    bool pair{};
    int valOne{};
    int valTwo{};
};

void printResult(const ValidPair& result) {
    if (result.pair == true) {
        std::cout << "Valid pair found!\n";
        std::cout << '[' << result.valOne << ", " << result.valTwo << "]\n\n";
    }
    else {
        std::cout << "No valid pair in array\n\n";
    }
}

// approach #1
ValidPair nestedLoop(const std::array<int, 5>& arr, int target) {
    ValidPair solution{};
    for (int i{0}; i <= (arr.size() - 1); ++i) {
        for (int k{i + 1}; k <= (arr.size() - 1); ++k) {
            solution.pair = ((arr[i] + arr[k]) == target);
            if (solution.pair) {
                solution.valOne = arr[i];
                solution.valTwo = arr[k];

                return solution;
            }
        }
    }

    return solution;
}

// approach #2
ValidPair twoPointer(const std::array<int, 5>& arr, int target) {
    ValidPair solution{};
    std::array<int, 5> temp{arr};
    
    // sort array
    std::sort(temp.begin(), temp.end());

    int pointerOne{0};
    int pointerTwo{temp.size() - 1};
    while (((temp[pointerOne] + temp[pointerTwo]) != target) && (pointerOne < pointerTwo)) {
        if ((temp[pointerOne] + temp[pointerTwo]) > target) {
            --pointerTwo;
        }

        if ((temp[pointerOne] + temp[pointerTwo]) < target) {
            ++pointerOne;
        }
    }
    solution.pair = ((temp[pointerOne] + temp[pointerTwo]) == target);

    if (solution.pair) {
        solution.valOne = temp[pointerOne];
        solution.valTwo = temp[pointerTwo];
    }

    return solution;
}

// approach #3
ValidPair hashing(const std::array<int, 5>& arr, int target) {

}

int main() {
    std::array<int, 5> arr{0, -1, 2, -3, 1};
    int target{ -2 };

    // approach #1
    ValidPair first{nestedLoop(arr, target)};
    printResult(first);

    // approach #2
    ValidPair second{twoPointer(arr, target)};
    printResult(second);


    return 0;
}