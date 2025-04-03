#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> n >> m >> s;
    int cnt = 0;
    int res = 0;

    for (int i = 1; i < m - 1; i++) {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            cnt++;
            if (cnt >= n) {
                res++;
            }
            i++;
        }
        else {
            cnt = 0;
        }
    }

    cout << res;
}

