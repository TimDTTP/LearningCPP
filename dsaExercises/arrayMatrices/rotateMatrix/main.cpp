
#include <iostream>

/*
 * Note: It is mildly infuriating that you cannot initialize a c-style array
 *  with another c-style array
 * Hence, arr is not init as a member variable and is used detachly from the
 *  class function
 */

const int ROW = 5;
const int COL = 5;

enum class Direction {
  clockwise,
  counter_clockwise,
};

class UserArray {
private:
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
      for (int i{beginCol}; i <= endCol; ++i) {
        curr = arr[beginRow][i];
        arr[beginRow][i] = prev;
        prev = curr;
      }

      ++beginRow;

      // shift right column down
      for (int i{beginRow}; i <= endRow; ++i) {
        curr = arr[i][endCol];
        arr[i][endCol] = prev;
        prev = curr;
      }

      --endCol;

      // shift bottom row left
      for (int i{endCol}; i >= beginCol; --i) {
        curr = arr[endRow][i];
        arr[endRow][i] = prev;
        prev = curr;
      }

      --endRow;

      // shift left column up
      for (int i{endRow}; i >= beginRow; --i) {
        curr = arr[i][beginCol];
        arr[i][beginCol] = prev;
        prev = curr;
      }

      ++beginCol;
    }
  }

  // rotate array counter cw
  void counterClockwise(int arr[ROW][COL], int endRow, int endCol) {
    // implement same steps above, except opposite direction
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

      // shift top row left
      prev = arr[beginRow + 1][endCol];
      for (int i{endCol}; i >= beginCol; --i) {
        curr = arr[beginRow][i];
        arr[beginRow][i] = prev;
        prev = curr;
      }

      ++beginRow;

      // shift left column down
      for (int i{beginRow}; i <= endRow; ++i) {
        curr = arr[i][beginCol];
        arr[i][beginCol] = prev;
        prev = curr;
      }

      ++beginCol;

      // shift bottom row right
      for (int i{beginCol}; i <= endCol; ++i) {
        curr = arr[endRow][i];
        arr[endRow][i] = prev;
        prev = curr;
      }

      --endRow;

      // shift right column up
      for (int i{endRow}; i >= beginRow; --i) {
        curr = arr[i][endCol];
        arr[i][endCol] = prev;
        prev = curr;
      }

      --endCol;
    }
  }

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
    std::cout << '\n';
  }

  // array rotation interface
  void rotateArray(int arr[ROW][COL], Direction direction) {
    if (direction == Direction::clockwise)
      clockwise(arr, ROW - 1, COL - 1);
    else if (direction == Direction::counter_clockwise)
      counterClockwise(arr, ROW - 1, COL - 1);
  }
};

int main() {
  Direction clockwise{Direction::clockwise};
  Direction counterClockwise{Direction::counter_clockwise};
  int arr[ROW][COL] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10},
                       {11, 12, 13, 14, 15},
                       {16, 17, 18, 19, 20},
                       {21, 22, 23, 24, 25}};

  UserArray matrixOperation = UserArray();

  matrixOperation.printArray(arr);

  matrixOperation.rotateArray(arr, counterClockwise);
  matrixOperation.printArray(arr);

  return 0;
}
