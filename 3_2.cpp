
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "None") {
        return nullptr;
    }

    Node* root = new Node(stoi(arr[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != "None") {
            cur->left = new Node(stoi(arr[i]));
            q.push(cur->left);
        }
        i++;

        if (i < arr.size() && arr[i] != "None") {
            cur->right = new Node(stoi(arr[i]));
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(
        maxDepth(root->left),
        maxDepth(root->right)
    );
}

int main() {
    vector<string> arr;
    string s;

    while (cin >> s) {
        arr.push_back(s);
    }

    Node* root = buildTree(arr);

    cout << maxDepth(root) << endl;

    return 0;
}
