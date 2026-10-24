#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;
    std::stack<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        s.push(num);
    }
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    return 0;
}