
#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int value, Node* next = NULL)
        : value(value), next(next) {}
};

class SingleList {
private:
    Node* head;
    Node* tail;
    int size_;

public:
    SingleList() : head(NULL), tail(NULL), size_(0) {}

    void addLast(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size_++;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    bool empty() {
        return size_ == 0;
    }

    int size() {
        return size_;
    }

    // 到达尾节点后重新返回头节点
    Node* getNext(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        return node->next == NULL ? head : node->next;
    }

    // 删除指定节点，返回下一位报数者
    Node* remove(Node* node) {
        if (node == NULL || head == NULL) {
            return NULL;
        }

        // 删除头节点
        if (node == head) {
            head = head->next;
            size_--;

            if (head == NULL) {
                tail = NULL;
            }

            delete node;
            return head;
        }

        Node* current = head;

        while (current != NULL && current->next != node) {
            current = current->next;
        }

        if (current != NULL) {
            // 删除之前保存下一个报数者
            Node* nextNode = getNext(node);

            current->next = node->next;

            if (node == tail) {
                tail = current;
            }

            size_--;
            delete node;

            return nextNode;
        }

        return NULL;
    }

    void swap(SingleList& other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(size_, other.size_);
    }

    void print() {
        Node* current = head;

        while (current != NULL) {
            printf("%4d", current->value);
            current = current->next;
        }

        printf("\n");
    }
};

int main() {
    int m, n;
    std::cin >> m;

    SingleList list;

    for (int i = 1; i <= m; i++) {
        list.addLast(i);
    }

    while (std::cin >> n) {
        SingleList newlist;

        Node* current = list.getHead();

        while (!list.empty()) {
            // 报数到 n
            int steps = (n - 1) % list.size();

            for (int i = 0; i < steps; i++) {
                current = list.getNext(current);
            }

            // 保存出列者编号
            int value = current->value;

            // 删除节点，返回下一位报数者
            current = list.remove(current);

            // 出列者进入新队列
            newlist.addLast(value);
        }

        // 交换链表
        list.swap(newlist);
    }

    list.print();

    return 0;
}
