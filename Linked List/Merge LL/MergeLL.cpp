#include <iostream>

struct Node {
    int val;
    Node* next;
};

struct linkedList {
    Node* head=nullptr;
};

void insert(linkedList& , int);
void bubbleSort(linkedList&);
void merge(linkedList&, linkedList&);
void printList(linkedList);


void insert(linkedList& ll , int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;
    if (ll.head == nullptr) {
        ll.head = newNode;
        return;
    }
    Node* last = ll.head;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
}

void bubbleSort(linkedList& ll) {
    Node* temp = ll.head;
    while (temp->next) {
        Node* temp1=ll.head;
        while (temp1->next) {
            if (temp1->next->val < temp1->val) {
                int t=temp1->val;
                temp1->val=temp1->next->val;
                temp1->next->val=t;
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}

void merge(linkedList& ll1, linkedList& ll2) {
    Node* temp2 = ll2.head;
    while (temp2) {
        Node* temp1 = ll1.head;
        if (temp2->val < ll1.head->val) {
            Node* newNode = new Node();
            newNode->val = temp2->val;
            newNode->next = ll1.head;
            ll1.head = newNode;
            temp2 = temp2->next;
        } else {
            while (temp1->next&&temp1->next->val<temp2->val) {
                temp1=temp1->next;
            }
            Node* newNode = new Node();
            newNode->val = temp2->val;
            newNode->next = temp1->next;
            temp1->next = newNode;
            temp2=temp2->next;
        }
    }
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
    linkedList ll1 , ll2;
    std::cout << "Enter Linked List Sizes: ";
    int size1 , size2;
    std::cin >> size1 >> size2;
    std::cout << "Enter First Linked List Elements: ";
    for (int i = 0; i < size1; i++) {
        int val;
        std::cin >> val;
        insert(ll1 , val);
    }
    bubbleSort(ll1);
    std::cout << "Enter Second Linked List Elements: ";
    for (int i = 0; i < size2; i++) {
        int val;
        std::cin >> val;
        insert(ll2 , val);
    }
    merge(ll1, ll2);
    printList(ll1);
    return 0;
}