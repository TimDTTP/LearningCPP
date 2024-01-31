
#include <iostream>
#include <array>

// binary search tree implementation
struct node {
    int key{};
    struct node *left{};
    struct node *right{};
};

struct node* newNode(int item) {
    struct node* temp{(struct node*)malloc(sizeof(struct node))};

    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) { return newNode(key); }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

// flush std::cin buffer
void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// forward declarations
int nestedLoop(const std::array<int,8>&, int);
int binarySearchTree(const std::array<int,8>&, int);
int mooresAlgo(const std::array<int,8>&, int);
int hashTable(const std::array<int,8>&, int);
int sorting(const std::array<int,8>&, int);

// which approach to use
void chooseApproach(const std::array<int, 8>& arr, int size) {
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
        case ('A') : {
            std::cout << "The result from approach A!" << std::endl;
            std::cout << nestedLoop(arr, size) << std::endl;
            return;
        }
        case ('B') : {
            std::cout << "Not implemented yet!" << std::endl;
            return;
        }
        case ('C') : {
            std::cout << "Not implemented yet!" << std::endl;
            return;
        }
        case ('D') : {
            std::cout << "Not implemented yet!" << std::endl;
            return;
        }
        case ('E') : {
            std::cout << "Not implemented yet!" << std::endl;
            return;
        }
    }
}

int nestedLoop(const std::array<int, 8>& arr, int size) {
    int maxFrequency{0};

    // past n/2, there cannot be a majority
    int upperBound{size/2};

    for (int i{0}; i < upperBound; i++) {
        int counter{1};
        for (int k{i + 1}; k < size; k++) {
            if (arr[i] == arr[k]) {counter++;}
        }

        if (counter > upperBound) {return arr[i];}
    }

    return -1;
}

int binarySearchTree(const std::array<int, 8>& arr, int size) {
    struct node* root{NULL};
    for (int i{0}; i < size; i++) {
        
    }
}
int main() {
    std::array<int, 8> arr{3, 4, 3, 2, 4, 4, 4, 4};

    chooseApproach(arr, arr.size());

    return 0;
}