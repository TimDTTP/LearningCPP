
#include <iostream>
#include <map>
#include <set>

class TaskManager {
public:
  struct taskProperties {
    int userId;
    int priority;
  };

  struct priorityOrder {
    int priority;
    int taskId;

    bool operator<(const priorityOrder &other) const {
      return ((priority != other.priority) ? (priority > other.priority)
                                           : (taskId > other.taskId));
    }
  };

private:
  std::map<int, taskProperties> m_table{};
  std::set<priorityOrder> m_set{};

public:
  TaskManager(std::vector<std::vector<int>> &tasks) {
    for (std::vector<int> i : tasks) {
      add(i[0], i[1], i[2]);
    }
  }

  void add(int userId, int taskId, int priority) {
    m_set.insert({priority, taskId});
    m_table[taskId] = {userId, priority};
  }

  void edit(int taskId, int newPriority) {
    m_set.erase({m_table[taskId].priority, taskId});
    m_set.insert({newPriority, taskId});
    m_table[taskId].priority = newPriority;
  }

  void rmv(int taskId) {
    m_set.erase({m_table[taskId].priority, taskId});
    m_table.erase(taskId);
  }

  int execTop() {
    int temp{};
    if (m_table.empty()) {
      return -1;
    }

    priorityOrder top{*m_set.begin()};
    temp = m_table[top.taskId].userId;
    rmv(top.taskId);

    return temp;
  }
};

class Test {
public:
  struct TestCase {
    std::vector<std::string> operation;
    std::vector<std::vector<int>> init;
    std::vector<std::vector<int>> values;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj;
    obj.operation = {"TaskManager", "add", "edit",   "execTop",
                     "rmv",         "add", "execTop"};
    obj.init = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    obj.values = {{4, 104, 5}, {102, 8}, {}, {101}, {5, 105, 15}, {}};
    obj.output = {-1, -1, -1, 3, -1, -1, 5};

    return obj;
  }

  void printVec(std::vector<int> vec) {
    std::cout << "[ " << vec[0];
    for (int i{1}; i < vec.size(); i++) {
      std::cout << ", " << vec[i];
    }
    std::cout << ']' << std::endl;
  }
};

class Run {
public:
  std::vector<int> execute(Test::TestCase input) {
    std::vector<int> output{};

    TaskManager *obj = new TaskManager(input.init);
    output.push_back(-1);
    obj->add(input.values[0][0], input.values[0][1], input.values[0][2]);
    output.push_back(-1);
    obj->edit(input.values[1][0], input.values[1][1]);
    output.push_back(-1);
    output.push_back(obj->execTop());
    obj->rmv(input.values[3][0]);
    output.push_back(-1);
    obj->add(input.values[4][0], input.values[4][1], input.values[4][2]);
    output.push_back(-1);
    output.push_back(obj->execTop());

    return output;
  }
};

int main() {
  Test testCur{Test()};
  Run runCur{Run{}};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{runCur.execute(unit)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    testCur.printVec(unit.output);
    std::cout << "Actual: ";
    testCur.printVec(output);
  }
  std::cout << std::endl;

  return 0;
}
