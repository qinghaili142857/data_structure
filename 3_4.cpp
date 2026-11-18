#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class binaryTree {

	public:
	class Node{
		public:
		int value;
		Node* left;
		Node* right;
		Node(int val): value(val), left(nullptr), right(nullptr) {}
	};

	Node* root;
	void buildTree(const vector<string>& arr) {
		if(arr.empty() || arr[0] == "None") {
			return;
		}
		root = new Node(stoi(arr[0]));
		queue<Node*> q;
		q.push(root);

		int i = 1;
		while(!q.empty() && i < arr.size()) {
			Node* current = q.front();
			q.pop();

			if(i < arr.size() && arr[i] != "None") {
				current->left = new Node(stoi(arr[i]));
				q.push(current->left);
			}
			i++;

			if(i < arr.size() && arr[i] != "None") {
				current->right = new Node(stoi(arr[i]));
				q.push(current->right);
			}
			i++;
		}
	};

	int height(Node* node) {
		if(node == nullptr) {
			return 0;
		}
		int left = height(node->left);
		if (left == -1) {
			return -1;
		}
		int right = height(node->right);
		if (right == -1) {
			return -1;
		}
		if(abs(left - right) > 1) {
			return -1;
		}
		return max(left, right) + 1;
	}
};

int main() {
	string str;
	vector<string> arr;
	while(cin >> str) {
		arr.push_back(str);
	}
	binaryTree tree;
	tree.buildTree(arr);
	if(tree.height(tree.root) == -1) {
		cout << "False" << endl;
	} else {
		cout << "True" << endl;	
	}
	return 0;
}
