
#include <iostream>
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

        if ((newNode->next) == NULL) {
            
        }

        *headRef = newNode;
    }
};

int main() {
    int arr[7] = {3, 7, 11, 13, 17, 19, 23};

    return 0;
}