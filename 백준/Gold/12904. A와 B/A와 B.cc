#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string t, s;
    cin >> t >> s;

    queue<string> q;
    q.push(s);

    while (!q.empty()) 
    {
        string cur = q.front(); 
        q.pop();

        if (cur == t) {
            cout << 1;
            return 0;
        }

        if (cur.length() <= t.length()) continue;

        if (cur.back() == 'A') {
            string next = cur.substr(0, cur.size() - 1);
            q.push(next);
        }

        if (cur.back() == 'B') {
            string next = cur.substr(0, cur.size() - 1);
            reverse(next.begin(), next.end());
            q.push(next);
        }
    }

    cout << 0;
}
