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

    void addLast(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int getMax() {
        if (head == NULL) {
            return -1;
        }
        else {
            int max = head->value;
            Node* maxNode = head;
            Node* current = head;
            while (current != NULL) {
                if (current->value > max) {
                    max = current->value;
                    maxNode = current;
                }
                current = current->next;
            }
            remove(maxNode);
            return max;
        }
    }

    void remove(Node* node) {
        if (node ==NULL || head == NULL) {
            return;
        }
        if (node == head) {
            head = head->next;
            delete node;
            return;
        }
        Node* current = head;
        while (current->next != NULL && current->next != node) {
            current = current->next;
        }
        if (current->next == node) {
            current->next = node->next;
            delete node;
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
    int n;
    LinkedList list;
    while (cin >> n) {
        list.addLast(n);
    }
    list.addLast(list.getMax());
    list.print();
    return 0;
}
