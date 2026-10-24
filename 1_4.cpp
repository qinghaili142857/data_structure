#include <iostream>
using namespace std;

class LinkedList {
    class Node {
        public:
        int value;
        Node* next;
        Node(int value, Node* next = NULL)
            : value(value), next(next) {}
    };

    private:
    Node* head;

    public:
    LinkedList() : head(NULL) {}
    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int value) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }

    // 如果值已存在，则不插入
    if (current != NULL && current->value == value) {
        return;
    }

    Node* newNode = new Node(value, current);

    if (previous == NULL) {
        head = newNode;
    } else {
        previous->next = newNode;
    }
    }
    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int value;
    while (cin >> value) {
        list.insert(value);
    }
    list.print();
    return 0;
}