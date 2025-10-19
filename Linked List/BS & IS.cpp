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
void insertionSort(linkedList&);
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

void insertionSort(linkedList& ll) {
    if (!ll.head) return;

    Node* i = ll.head->next;
    while (i) {
        Node* j = ll.head;
        while (j != i) {
            if (j->val > i->val) {
                int temp = j->val;
                j->val = i->val;
                i->val = temp;
            }
            j = j->next;
        }
        i = i->next;
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
    insertionSort(ll2);
    std::cout << "First Linked List sorted with BubbleSort: " ;
    printList(ll1);
    std::cout << "Second Linked List sorted with InsertionSort: ";
    printList(ll2);
    return 0;
}