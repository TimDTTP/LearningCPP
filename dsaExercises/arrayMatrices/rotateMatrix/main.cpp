
#include <iostream>

const int ROW = 5;
const int COL = 5;

class Solution {
public:
  void printArray(int arr[ROW][COL]) {
    for (int a{0}; a < ROW; a++) {
      for (int b{0}; b < COL; b++) {
        std::cout << arr[a][b];

        // justified
        if (arr[a][b] < 10) {
          std::cout << "  ";
        } else {
          std::cout << ' ';
        }
      }
      std::cout << std::endl;
    }
  }

  void printRow(int arr[ROW][COL], int r) {
    std::cout << "Row: " << r << '\n';
    for (int i{0}; i < ROW; ++i) {
      std::cout << arr[r][i] << ' ';
    }
    std::cout << '\n';
  }

  void printCol(int arr[ROW][COL], int c) {
    std::cout << "Column: " << c << '\n';
    for (int i{0}; i < ROW; ++i) {
      std::cout << arr[i][c] << '\n';
    }
    std::cout << '\n';
  }

  // rotate clockwise
  void clockwise(int arr[ROW][COL], int endRow, int endCol) {
    int beginRow{0};
    int beginCol{0};

    /*
     * beginRow - Iterator for row starting at the beginning
     * endRow - Iterator for row starting at the end
     * beginCol - Iterator for column starting at the beginning
     * endCol - Iterator for column starting at the end
     */

    // placeholder for values
    int prev, curr;

    while (beginRow < endRow && beginCol < endCol) {
      if (beginRow + 1 == endRow || beginCol + 1 == endCol) {
        break;
      }

      // shift top row right
      prev = arr[beginRow + 1][beginCol];
      for (int i{beginCol}; i < endCol; ++i) {
        curr = arr[beginRow][i];
        arr[beginRow][i] = prev;
        prev = curr;
      }

      // TODO: Left off here

      // shift right column down

      // shift bottom row left

      // shift left column up
    }
  }
};

int main() {
  int arr[ROW][COL] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10},
                       {11, 12, 13, 14, 15},
                       {16, 17, 18, 19, 20},
                       {21, 22, 23, 24, 25}};

  Solution cursor = Solution();

  return 0;
}
