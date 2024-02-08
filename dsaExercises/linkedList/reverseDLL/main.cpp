
#include <iostream>
#include <stack>

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

    void append(class Node** headRef, int data) {
        class Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        class Node* last{*headRef};

        if (*headRef == NULL) {
            *headRef = newNode;
            return;
        }

        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        return;
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

class Node* bruteForce(class Node* headRef) {
    class Node* temp{headRef};

    while (headRef != NULL) {
        class Node* nextHolder{headRef->next};
        
        headRef->next = headRef->prev;
        headRef->prev = nextHolder;

        if ((headRef->prev) == NULL) {
            return headRef;
        }
        else {
            headRef = headRef->prev; 
        }
    }

    return headRef;
}

class Node* stack(class Node* headRef) {
    std::stack<int> numStack{};
    class Node* newHead{NULL};
    class NodeOperation* temp = new NodeOperation();

    // add to stack
    while (headRef != NULL) {
        numStack.push(headRef->data);

        headRef = headRef->next;
    }

    // append to new linked list
    while (numStack.size() != 0) {
        temp->append(&newHead, numStack.top());
        numStack.pop();
    }

    return newHead;
}

void solution(class Node* headRef) {
    class NodeOperation* temp = new NodeOperation();
    std::cout << "The following is the linked list: " << std::endl;
    temp->printList(headRef);
    std::cout << '\n';

    char choice{userInput()};
    
    std::cout << "The result of approach ";

    switch (choice) {
        case('A') : {
            std::cout << "A:" << std::endl;
            temp->printList(bruteForce(headRef));
            break;
        }

        case('B') : {
            std::cout << "B:" << std::endl;
            temp->printList(stack(headRef));
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
    solution(head);

    return 0;
}