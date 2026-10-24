#include <iostream>

using namespace std;

class PolyList {
    class Node {
    public:
        double value;
        int power;
        Node* next;

        Node(double value, int power, Node* next = NULL)
            : value(value), power(power), next(next) {}
    };

private:
    Node* head;

public:
    PolyList() : head(NULL) {}

    PolyList(const PolyList&) = delete;
    PolyList& operator=(const PolyList&) = delete;

    PolyList(PolyList&& other) noexcept : head(other.head) {
        other.head = NULL;
    }

    ~PolyList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(double value, int power) {
        if (abs(value) == 0) return;

        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->power > power) {
            previous = current;
            current = current->next;
        }

        
        if (current != NULL && current->power == power) {
            current->value += value;

            
            if (abs(current->value) == 0) {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
            }
            return;
        }

        Node* newNode = new Node(value, power, current);

        if (previous == NULL) {
            head = newNode;
        } else {
            previous->next = newNode;
        }
    }

    PolyList add(const PolyList& other) const {
        PolyList result;

        Node* current1 = head;
        Node* current2 = other.head;

        while (current1 != NULL && current2 != NULL) {
            if (current1->power > current2->power) {
                result.insert(current1->value, current1->power);
                current1 = current1->next;
            }
            else if (current2->power > current1->power) {
                result.insert(current2->value, current2->power);
                current2 = current2->next;
            }
            else {
                result.insert(
                    current1->value + current2->value,
                    current1->power
                );
                current1 = current1->next;
                current2 = current2->next;
            }
        }

        while (current1 != NULL) {
            result.insert(current1->value, current1->power);
            current1 = current1->next;
        }

        while (current2 != NULL) {
            result.insert(current2->value, current2->power);
            current2 = current2->next;
        }

        return result;
    }

    void print(int index) const {
        Node* current = head;
        int count = 1;

        while (current != NULL) {
            if (count == index) {
                printf("%.1f %d\n", current->value, current->power);
                return;
            }
            current = current->next;
            count++;
        }
    }
};

int main() {
    PolyList poly1, poly2;
    double value;
    int power, index;

    while (cin >> value >> power) {
        poly1.insert(value, power);
        if (cin.peek() == '\n') break;
    }

    while (cin >> value >> power) {
        poly2.insert(value, power);
        if (cin.peek() == '\n') break;
    }

    PolyList result = poly1.add(poly2);

    cin >> index;
    result.print(index);

    return 0;
}
