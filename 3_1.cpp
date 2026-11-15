#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Huffman{
    class Node{
        public:
        int value;
        int freq;
        Node* left;
        Node* right;

        Node(int value, int freq, Node* left = nullptr, Node* right = nullptr) {
            this->value = value;
            this->freq = freq;
            this->left = left;
            this->right = right;
        }
    };

    public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };
    int wpl = 0;
    priority_queue<Node*, vector<Node*>, Compare> pq;
    void createHuffmanTree(vector<int> arr) {
        for (int ele : arr) {
        Node* newNode = new Node(ele, ele);
        pq.push(newNode);
        }
        while(pq.size() > 1){
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            Node* newNode = new Node(-1, left->freq + right->freq);
            wpl += newNode->freq;
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }
    }

    
};

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    Huffman huffman;
    huffman.createHuffmanTree(arr);
    cout << huffman.wpl << endl;
}
