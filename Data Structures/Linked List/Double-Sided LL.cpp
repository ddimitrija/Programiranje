#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* prev;
};

struct linkedList {
    Node* head=nullptr;
};

void insert(linkedList& , int);
void remove(linkedList&, int );
bool search(linkedList&, int );
void printList(linkedList);


void insert(linkedList& ll , int val , int pos) {
    if (ll.head == nullptr) {
        ll.head = new Node();
        ll.head->val = val;
        ll.head->next = ll.head->prev = nullptr;
        return;
    }
    if (pos == 0) {
        Node* newNode= new Node();
        newNode->val = val;
        newNode->prev = nullptr;
        newNode->next = ll.head;
        ll.head = newNode;
        return;
    }
    Node* temp=ll.head;
    int index=1;
    while (temp->next&&index<pos-1) {
        temp = temp->next;
        index++;
    }
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next) newNode->next->prev = newNode;
}

void remove(linkedList& ll, int val) {
    Node* temp = ll.head;
    while (temp) {
        if (temp->val == val) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

bool search(linkedList& ll, int val) {
    Node* temp = ll.head;
    while (temp) {
        if (temp->val == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
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
    linkedList ll;
    std::cout << "Enter Linked List Size: ";
    int size;
    std::cin >> size;
    std::cout << "Enter First Linked List Element : ";
    for (int i = 0; i < size; i++) {
        int val , pos;
        std::cin >> val >> pos;
        insert(ll , val , pos);
    }
    printList(ll);
    std::cout << "Enter which element to remove : " ;
    int value;
    std::cin >> value;
    remove(ll, value);
    std::cout << "Enter which element to search : ";
    int searchValue;
    std::cin >> searchValue;
    if (search(ll , searchValue)) {
        std::cout << "Element found!" << std::endl;
    }
    else {
        std::cout << "Element not found!" << std::endl;
    }
    printList(ll);
    return 0;
}