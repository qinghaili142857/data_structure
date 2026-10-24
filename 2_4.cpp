#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    queue<char> q;

    for (int i = 0; i < (int)s.size(); i++) {
        q.push(s[i]);

        if (q.size() > t.size()) {
            q.pop();
        }

        if (q.size() == t.size()) {
            queue<char> temp = q;
            bool flag = true;
            for (int j = 0; j < (int)t.size(); j++) {
                if (temp.front() != t[j]) {
                    flag = false;
                    break;
                }
                temp.pop();
            }
            if (flag) {
                cout << i - (int)t.size() + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}