
#include <iostream>
#include <array>
#include <stack>

void solution(const std::array<int, 6>& nums, int size) {
    std::stack<int> maxes{};
    for (int i{size - 1}; i > 0; --i) {
        if (maxes.size() == 0) { maxes.push(nums[i]); }
        else if (nums[i] > maxes.top()) { maxes.push(nums[i]); }
    }

    // print solutions
    std::cout << "Leaders are...\n";
    while (maxes.size() != 0) {
        std::cout << maxes.top() << ' ';
        maxes.pop();
    }
}

int main() {
    std::array<int, 6> val{16, 17, 4, 3, 5, 2};

    solution(val, val.size());

}