
#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <unordered_map>

// forward declarations
int nestedLoop(const std::array<int, 8> &, int);
int binarySearchTree(const std::array<int, 8> &, int);
int mooresAlgo(const std::array<int, 8> &, int);
int hashing(const std::array<int, 8> &, int);
int sorting(const std::array<int, 8> &, int);

// binary search tree implementation
struct node {
  int key{};
  int freq{};
  struct node *left{};
  struct node *right{};
};

struct node *newNode(int item) {
  struct node *temp{(struct node *)malloc(sizeof(struct node))};

  temp->key = item;
  temp->freq = 1;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

struct node *insert(struct node *node, int key, int &candidate,
                    int &candidateVal) {
  if (node == NULL) {
    if (candidateVal == 0) {
      candidateVal = 1;
    }

    return newNode(key);
  }

  if (key < node->key) {
    node->left = insert(node->left, key, candidate, candidateVal);
  } else if (key > node->key) {
    node->right = insert(node->right, key, candidate, candidateVal);
  }
  // if duplicate, increment count
  else {
    node->freq += 1;
  }

  if (candidateVal < node->freq) {
    candidate = node->key;
    candidateVal = node->freq;
  }

  return node;
}

// flush std::cin buffer
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// which approach to use
void chooseApproach(const std::array<int, 8> &arr, int size) {
  char clientChoice{};

  std::cout << "Choose which approach to use:" << std::endl;
  std::cout << "A) Nested loop" << std::endl;
  std::cout << "B) Binary search tree" << std::endl;
  std::cout << "C) Boyer Moore's voting algorithm" << std::endl;
  std::cout << "D) Hashmap" << std::endl;
  std::cout << "E) Sorting" << std::endl;
  std::cout << "\nChoice: ";

  std::cin >> clientChoice;

  if (!std::cin) {
    if (std::cin.eof())
      exit(0);

    std::cin.clear();
  }

  ignoreLine();

  std::cout << '\n';

  switch (clientChoice) {
  case ('A'): {
    std::cout << "The result from approach A!" << std::endl;
    std::cout << nestedLoop(arr, size) << std::endl;
    return;
  }
  case ('B'): {
    std::cout << "The result from approach B!" << std::endl;
    std::cout << binarySearchTree(arr, size) << std::endl;
    return;
  }
  case ('C'): {
    std::cout << "The result from approach C!" << std::endl;
    std::cout << mooresAlgo(arr, size) << std::endl;
    return;
  }
  case ('D'): {
    std::cout << "The result from approach D!" << std::endl;
    std::cout << hashing(arr, size) << std::endl;
    return;
  }
  case ('E'): {
    std::cout << "The result from approach E!" << std::endl;
    std::cout << sorting(arr, size) << std::endl;
    return;
  }
  }
}

int nestedLoop(const std::array<int, 8> &arr, int size) {
  int maxFrequency{0};

  // past n/2, there cannot be a majority
  int upperBound{size / 2};

  for (int i{0}; i < upperBound; i++) {
    int counter{1};
    for (int k{i + 1}; k < size; k++) {
      if (arr[i] == arr[k]) {
        counter++;
      }
    }

    if (counter > upperBound) {
      return arr[i];
    }
  }

  return -1;
}

int binarySearchTree(const std::array<int, 8> &arr, int size) {
  struct node *root{NULL};
  int candidate{};
  int candidateVal{};

  for (int i{0}; i < size; i++) {
    // add to tree
    root = insert(root, arr[i], candidate, candidateVal);
  }

  if (candidateVal > (size / 2)) {
    return candidate;
  } else {
    return -1;
  }
}

int mooresAlgo(const std::array<int, 8> &arr, int size) {
  int candidate{arr[0]};
  int vote{1};

  for (int i{1}; i < size; i++) {
    if (arr[i] == candidate) {
      vote++;
    } else {
      vote--;
    }

    if (vote == 0) {
      candidate = arr[i];
    }
  }

  // check if candidate is > (n/2)
  int countTest{};
  for (int i{0}; i < size; i++) {
    if (arr[i] == candidate) {
      countTest++;
    }
  }

  if (countTest <= (size / 2)) {
    return -1;
  }

  return candidate;
}

int hashing(const std::array<int, 8> &arr, int size) {
  std::unordered_map<int, int> hSet{};
  const int initialCount{1};

  for (int i{0}; i < size; i++) {
    hSet[arr[i]]++;
  }

  for (auto i : hSet) {
    if (i.second > (size / 2)) {
      return i.first;
    }
  }

  return -1;
}

int sorting(const std::array<int, 8> &arr, int size) {
  std::array<int, 8> tempArr{arr};
  std::sort(tempArr.begin(), tempArr.end());

  int current{0};
  int counter{0};
  for (auto i : tempArr) {
    if (i == current) {
      counter++;
    } else {
      current = i;
      counter = 1;
    }

    if (counter > (size / 2)) {
      return i;
    }
  }

  return -1;
}

int main() {
  std::array<int, 8> arr{3, 4, 3, 2, 4, 4, 4, 4};

  chooseApproach(arr, arr.size());

  return 0;
}
