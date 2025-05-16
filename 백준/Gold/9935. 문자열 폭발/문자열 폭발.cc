#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, boom;
    cin >> s >> boom;

    vector<char> stack;

    for (int i = 0; i < s.size(); i++) {
        stack.push_back(s[i]);

        if (stack.size() >= boom.size()) {
            bool found = true;
            for (int j = 0; j < boom.size(); j++) {
                if (stack[stack.size() - boom.size() + j] != boom[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                for (int j = 0; j < boom.size(); j++) {
                    stack.pop_back();
                }
            }
        }
    }
    if (stack.empty()) {
        cout << "FRULA";
    } else {
        for (char c : stack) {
            cout << c;
        }
    }

    return 0;
}
