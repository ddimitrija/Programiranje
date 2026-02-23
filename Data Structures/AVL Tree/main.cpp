#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        left = right = NULL;
        data = k;
        height = 1;
    }
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
int max(int a , int b) {
    return a > b ? a : b;
}

Node* RR(Node* n) {
    Node* x = n->left;
    Node* y = x->right;

    x->right = n;
    n->left = y;

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* LL(Node* n) {
    Node* x = n->right;
    Node* y = x->left;

    x->left = n;
    n->right = y;

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* insert(Node* node , int key) {
    if (!node) return new Node(key);
    if (key<node->data) {
        node->left=insert(node->left, key);
    }
    else if (key>node->data) {
        node->right=insert(node->right, key);
    }
    else return node;

    node->height=1+max(getHeight(node->left),getHeight(node->right));

    int balance=getBalance(node);
    if (balance>1 && key<node->left->data) {
        return LL(node);
    }
    if (balance<-1 && key>node->right->data) {
        return LL(node);
    }
    if (balance>1 && key>node->left->data) {
        node->left=LL(node->left);
        return LL(node);
    }
    if (balance<-1 && key<node->right->data) {
        node->right=LL(node->right);
        return LL(node);
    }

    return node;
}

void inorderprint(Node* node) {
    if (!node) return;
    inorderprint(node->left);
    std::cout << node->data << " ";
    inorderprint(node->right);
}

int main() {
    Node* root = new Node(10);
    int arr[] = {20 , 35 , 15 , 40 , 8 , 55};
    for (int x : arr) {
        root=insert(root, x);
    }
    inorderprint(root);
    return 0;
}
