
#include <iostream>
#include <string>
#include <vector>

class Spreadsheet {
private:
  std::vector<std::vector<int>> sheet;

  std::pair<int, int> toCell(std::string cell) {
    return {cell[0] - 'A', std::stoi(cell.substr(1))};
  }

public:
  Spreadsheet(int rows) {
    sheet = std::vector<std::vector<int>>(26, std::vector<int>(rows + 1, 0));
  }

  void setCell(std::string cell, int value) {
    std::pair<int, int> coord{toCell(cell)};
    sheet[coord.first][coord.second] = value;
  }

  void resetCell(std::string cell) {
    std::pair<int, int> coord{toCell(cell)};
    sheet[coord.first][coord.second] = 0;
  }

  int getValue(std::string formula) {
    auto isCell = [](std::string &value) {
      return (std::isalpha(static_cast<unsigned char>(value[0])));
    };

    auto retrieve = [this](std::string &cell) {
      std::pair<int, int> coord{toCell(cell)};
      return sheet[coord.first][coord.second];
    };

    std::string substr;

    substr = formula.substr(1, formula.find('+') - 1);
    int a{(isCell(substr) ? retrieve(substr) : std::stoi(substr))};
    substr = formula.substr(formula.find('+') + 1);
    int b{(isCell(substr) ? retrieve(substr) : std::stoi(substr))};

    return a + b;
  }

  // TEST:
  void print() {
    for (int i{0}; i < sheet[0].size(); i++) {
      for (int j{0}; j < sheet.size(); j++) {
        std::cout << sheet[j][i] << ' ';
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  Spreadsheet *table = new Spreadsheet(4);

  table->setCell("A0", 6);
  table->setCell("X3", 9);
  table->print();
  std::cout << table->getValue("=A0+X3") << std::endl;
}
