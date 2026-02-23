#include <iostream>

struct Node {
    int val;
    Node* next;
};

struct linkedList {
    Node* head=nullptr;
};

void insert(linkedList& , int);
void printList(linkedList);



void insert(linkedList& ll , int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;
    if (ll.head == nullptr || val < ll.head->val) {
        newNode->next = ll.head;
        ll.head = newNode;
        return;
    }
    Node* last = ll.head;
    while (last->next && last->next->val<val) {
        last = last->next;
    }
    Node* temp=last->next;
    newNode->next = temp;
    last->next = newNode;
}

void printList(linkedList l) {
    Node* current = l.head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    linkedList ll ;
    std::cout << "Enter Linked List Size: ";
    int size;
    std::cin >> size;
    std::cout << "Enter Linked List Elements: ";
    for (int i = 0; i < size; i++) {
        int val;
        std::cin >> val;
        insert(ll , val);
        std::cout << "Current sorted LL : " ;
        printList(ll);
    }
    return 0;
}