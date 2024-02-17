
#include <iostream>
#include <limits>

class Node {
public:
    int data{};
    Node* next{};
};

class NodeOperations {
public:
    void push(class Node** headRef, int data) {
        class Node* newNode = new Node();
        newNode->data = data;
        newNode->next = *headRef;

        if (*headRef != NULL) {
            class Node* temp = *headRef;

            while (temp->next != *headRef) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
        else {
            newNode->next = newNode;
        }

        *headRef = newNode;
    }

    void print(class Node* head) {
        class Node* temp{head};

        if (head != NULL) {
            do {
                std::cout << temp->data << ' ';
                temp = temp->next;
            }
            while (temp != head);
        }

        std::cout << std::endl;
    }
};

char chooseApproach() {
    char choice{};

    std::cout << "Choose an approach to use:" << std::endl;
    std::cout << "A) Swap pointers" << std::endl
              << "B) Swap values" << std::endl;
    std::cout << "Enter: ";
    std::cin >> choice;

    if (!std::cin) {
        if (std::cin.eof()) {
            exit(0);
        }

        std::cin.clear();
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << '\n' << std::endl;

    return choice;
}

class Node* swapPointers(class Node* head) {
    class Node* ptrFirst{head};

    // reach penultimate
    while ((head->next->next) != ptrFirst) {
        head = head->next;
    }

    // change last's pointer to second
    (head->next->next) = ptrFirst->next;
    
    // change first's pointer to last node
    ptrFirst->next = head->next;

    // change penultimate pointer to first
    head->next = ptrFirst;

    // ptrFirst->next now returns to beginning of linked list
    head = ptrFirst->next; 

    return head;
}

class Node* swapValues(class Node* head) {
    class Node* ptrFirst{head};
    int temp{ptrFirst->data};

    while ((head->next) != ptrFirst) {
        head = head->next;
    }

    // swap values
    ptrFirst->data = head->data;
    head->data = temp;
    
    return ptrFirst;
}

void solution(class Node* head) {
    class NodeOperations* temp = new NodeOperations();
    std::cout << "The current linked list: " << std::endl
              << "> ";
    
    temp->print(head);

    switch (chooseApproach()) {
        case ('A') : {
            std::cout << "Result of approach A!" << std::endl
                      << "> ";
            temp->print(swapPointers(head));
            break;
        }
        case ('B') : {
            std::cout << "Result of approach B!" << std::endl
                      << "> ";
            temp->print(swapValues(head));
            break;
        }
    }
}

int main() {
    int arr[7] = {3, 7, 11, 13, 17, 19, 23};
    class Node* head{NULL};
    class NodeOperations* temp = new NodeOperations();

    for (auto i : arr) {
        temp->push(&head, i);
    }

    solution(head);

    return 0;
}