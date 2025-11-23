#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


void insertBST(Node*& root ,int value) {
    if (!root) {
        root=new Node(value);
        return;
    }
    if (value < root->data) {
        insertBST(root->left,value);
    }
    else if (value > root->data) {
        insertBST(root->right,value);
    }
}

void DFSPreOrder(const Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    DFSPreOrder(root->left);
    DFSPreOrder(root->right);
}
void DFSInOrder(const Node* root) {
    if (!root) {
        return;
    }
    DFSInOrder(root->left);
    cout << root->data << " ";
    DFSInOrder(root->right);
}
void DFSPostOrder(const Node* root) {
    if (!root) {
        return;
    }
    DFSPostOrder(root->left);
    DFSPostOrder(root->right);
    cout << root->data << " ";
}

bool find(Node* root, int value) {
    if (!root) return false;
    if (root->data == value) return true;
    if (find(root->left, value)) return true;
    return find(root->right, value);
}

void DFSPreOrderNoRecursion(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
}
void DFSInOrderNoRecursion(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr!=nullptr || !s.empty()) {
        while (curr!=nullptr) {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }

}
void DFSPostOrderNoRecursion(Node* root) {
    if (!root) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* node=s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void BFS(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        cout << node->data << " "; 

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

void insertBT(Node*& root, int value) {
    Node* newNode = new Node(value);
    if (!root) {
        root = newNode;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr=q.front();
        q.pop();
        if (!curr->left) {
            curr->left = newNode;
            return;
        } else {
            q.push(curr->left);
        }
        if (!curr->right) {
            curr->right = newNode;
            return;
        } else {
            q.push(curr->right);
        }
    }
}

int sum(Node *root) {
    if (!root) return 0;
    return root->data + sum(root->left) + sum(root->right);
}



int main() {
    Node* rootBST = nullptr;
    Node* rootBT = nullptr;

    insertBST(rootBST, 15);
    insertBST(rootBST, 10);
    insertBST(rootBST, 25);
    insertBST(rootBST, 5);
    insertBST(rootBST, 12);
    insertBST(rootBST, 20);
    insertBST(rootBST, 30);

    cout << "BST Recursive DFS Preorder: ";
    DFSPreOrder(rootBST);
    cout << endl;

    cout << "BST Recursive DFS Inorder: ";
    DFSInOrder(rootBST);
    cout << endl;

    cout << "BST Recursive DFS Postorder: ";
    DFSPostOrder(rootBST);
    cout << endl;

    cout << "BST Non-recursive DFS Preorder: ";
    DFSPreOrderNoRecursion(rootBST);
    cout << endl;

    cout << "BST Non-recursive DFS Inorder: ";
    DFSInOrderNoRecursion(rootBST);
    cout << endl;

    cout << "BST Non-recursive DFS Postorder: ";
    DFSPostOrderNoRecursion(rootBST);
    cout << endl;

    cout << "BST BFS: ";
    BFS(rootBST);
    cout << endl;

    cout << "BST Sum of all nodes: " << sum(rootBST) << endl;

    cout << "Find 20 in BST: " << find(rootBST, 20) << endl;
    cout << "Find 100 in BST: " << find(rootBST, 100) << endl;

    insertBT(rootBT, 15);
    insertBT(rootBT, 10);
    insertBT(rootBT, 25);
    insertBT(rootBT, 5);
    insertBT(rootBT, 12);
    insertBT(rootBT, 20);
    insertBT(rootBT, 30);

    cout << "\nBT Recursive DFS Preorder: ";
    DFSPreOrder(rootBT);
    cout << endl;

    cout << "BT BFS: ";
    BFS(rootBT);
    cout << endl;

    cout << "BT Sum of all nodes: " << sum(rootBT) << endl;

    return 0;
}
