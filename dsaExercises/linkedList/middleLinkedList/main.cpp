
#include <iostream>
#include <vector>

class Node {
public:
    int data{};
    Node* next{};
};

class NodeOperation {
public:
    void push(class Node** headRef, int data) {
        class Node* newNode = new Node();
        newNode->data = data;
        newNode->next = *headRef;

        *headRef = newNode;
    }
};

int bruteForce(class Node* head) {
    std::vector<int> nums{};

    while (head != NULL) {
        nums.push_back(head->data);
        head = head->next;
    }

    return (nums[nums.size() / 2]);
}

int countingValues(class Node* head) {
    class Node* initialHead{head};
    int counter{};

    while (head != NULL) {
        counter++;
        head = head->next;
    }

    for (int i{0}; i < (counter / 2); i++) {
        initialHead = initialHead->next;
    }

    return initialHead->data;
}
int twoPointers(class Node* head) {
    class Node* fastPointer{head};

    while (fastPointer->next != NULL) {
        head = head->next;
        
        for (int i{0}; i < 2; i++) {
            fastPointer = fastPointer->next;

            if (fastPointer == NULL) {
                return head->data;
            }
        }
    }

    return head->data;
}

char userInput() {
    std::cout << "Choose which approach to use: " << std::endl;
    std::cout << "A) Brute force" << std::endl
              << "B) Counting values" << std::endl
              << "C) Two pointers" << std::endl;
    std::cout << "Enter: ";

    char userChoice{};
    std::cin >> userChoice;

    // input handling + clear buffer
    if (!std::cin) {
        if (std::cin.eof()) 
            exit(0);
        
        std::cin.clear();
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << '\n' << std::endl;

    return userChoice;
}

int main() {
    int arr[7] = {4, 6, 8, 1, 5, 9, 3};
    class Node* head = NULL;
    class NodeOperation* temp = new NodeOperation();

    for (auto i : arr) {
        temp->push(&head, i);
    }

    // start of solutions

    // which approach to use
    char choice{userInput()};

    // fork depending on choice
    std::cout << "The result of approach ";
    switch (choice) {
        case ('A') : {
            std::cout << "A:" << std::endl;
            std::cout << "Result: " << bruteForce(head) << std::endl;
            break;
        }
        case ('B') : {
            std::cout << "B:" << std::endl;
            std::cout << "Result: " << countingValues(head) << std::endl;
            break;
        }
        case ('C') : {
            std::cout << "C:" << std::endl;
            std::cout << "Result: " << twoPointers(head) << std::endl;
            break;
        }
    }

    return 0;
}