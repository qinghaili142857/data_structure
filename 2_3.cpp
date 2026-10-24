#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int n;
    while (cin >> n && n != -1) {
        switch (n) {
            case 1:
                int value;
                cin >> value;
                s.push(value);
                break;
            case 0:
                if (s.empty()) {
                    cout << "error ";
                }
                else {
                    cout << s.top() << " ";
                    s.pop();
                }
                break;
        }
    }
    cout << endl;
    return 0;
}