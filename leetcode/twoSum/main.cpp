
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // length of vector
        const int vSize{ static_cast<int>(nums.size()) };

        // solution vector
        vector<int> solution(2);

        // coarse matching
        if (target > nums[vSize]) { start = vSize / 2; }

        // fine matching
        for (int i{ start }; (vSize - 1) > i; ++i) {
            for (int j{ i + 1 }; vSize > j; ++j) {
        
                if ((nums[i] + nums[j]) == target) {
                    solution[0] = i;
                    solution[1] = j;

                    return solution;
                }
            }
        }

        return solution;
    }


    void print(std::vector<int> v) {
        std::cout << v[0] << ", " << v[1] << '\n';
    }
};


int main() {
    vector<int> test{ 1, 2, 3, 4, 5, 6 };
    const int target{ 3 };

    Solution answer{};

    vector<int> solution{ answer.twoSum(test, target) };
    
    answer.print(solution);

    return 0;
}