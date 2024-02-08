
#include <iostream>

class Node {
public:
    int data{};
    Node* next{};
    Node* prev{};
};

class NodeOperation {
public:
    void push(class Node** headRef, int data) {
        class Node* newNode = new Node();
        newNode->data = data;
        newNode->next = *headRef;
        newNode->prev = NULL;

        if (*headRef != NULL) {
            (*headRef)->prev = newNode;
        }

        *headRef = newNode;
    }

    void printList(class Node* node) {
        while (node != NULL) {
            std::cout << node->data << ' ';
            node = node->next;
        }

        std::cout << std::endl;
    }
};

char userInput() {
    std::cout << "Choose which approach to use: " << std::endl;
    std::cout << "A) Brute force" << std::endl
              << "B) Stack" << std::endl;
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

class Node* bruteForce() {

}

class Node* stack() {

}

void chooseApproach() {
    char choice{userInput()};
    class NodeOperation* temp = new NodeOperation();
    
    std::cout << "The result of approach ";

    switch (choice) {
        case('A') : {
            std::cout << "A:" << std::endl;
            temp->printList(bruteForce());
            break;
        }

        case('B') : {
            std::cout << "B:" << std::endl;
            temp->printList(stack());
            break;
        }
    }
}

int main() {
    class Node* head{NULL};
    class NodeOperation* temp = new NodeOperation();

    // insert values into linked list
    int arr[7] = {3, 7, 13, 17, 19, 23, 29};

    for (auto i : arr) {
        temp->push(&head, i);
    }

    // start of solution
    

    return 0;
}