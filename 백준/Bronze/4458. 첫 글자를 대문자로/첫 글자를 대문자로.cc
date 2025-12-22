#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        if (s[0] >= 'a' && s[0] <= 'z')
        {
            s[0] = s[0] - 32;
        }
        cout << s << '\n';
    }
}
