
#include <algorithm>
#include <string>
#include <vector>

class Solution {
private:
  bool static cmp(std::pair<std::string, int> first,
                  std::pair<std::string, int> second) {
    if (first.second > second.second)
      return true;
    else
      return false;
  };

public:
  std::string largestNumber(std::vector<int> &nums) {
    std::string out{""};
    std::vector<std::pair<std::string, int>> table;

    // add value : priority to table
    for (int num : nums) {
      std::pair<std::string, int> obj;
      obj.first = std::to_string(num);
      obj.second = num * (pow(10, (9 - obj.first.size() - 1)));
      table.push_back(obj);
    }

    // sort table by priority
    std::sort(table.begin(), table.end(), cmp);

    // iterate and append to string
    for (std::pair<std::string, int> vals : table) {
      out += vals.first;
    }

    return out;
  }
};
