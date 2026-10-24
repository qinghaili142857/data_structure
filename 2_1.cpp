#include <iostream>
using namespace std;

template <typename T>
class Stack{
    class Node {
        public:
        T value;
        Node* next;
        Node (T value, Node* next = NULL)
            :value(value), next(next) {}
    };

    private:
    Node* top;
    int size;

    public:
    Stack() : top(NULL), size(0) {}
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T value) {
        Node* newNode = new Node(value, top);
        size++;
        if (top == NULL) {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    bool empty() {
        return size == 0;
    }
    T topValue() {
        if (top == NULL) {
            return T(); 
        }
        return top->value;
    }
};

int main() {
    bool flag  = true;
    Stack<char> s;
    char c;
    while (cin >> c) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                flag = false;
                break;
            }
            char topChar = s.topValue();
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                flag = false;
                break;
            }
            s.pop();
        }
    }
    if (!s.empty()) {
        flag = false;
    }
    cout << flag <<endl;
    return 0;
}