#include <iostream>
#include <algorithm>

class BST{
    class Node{
        public:
        int value;
        Node* left;
        Node* right;
        Node(int value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    public:
    BST() {
        root = nullptr;
    }
    Node* root;
    Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

    int getDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    void midOrder(Node* node) {
        if (node == nullptr) {
            return;
        }
        midOrder(node->left);
        std::cout << node->value << " ";
        midOrder(node->right);
    }
};

int main() {
    int n;
    std::cin >> n;
    BST bst;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        bst.root = bst.insert(bst.root, num);
    }
    std::cout << bst.getDepth(bst.root) << std::endl;
    bst.midOrder(bst.root);
    return 0;
}