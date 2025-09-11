#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n/2; i++)
    {
        if (s[i] == '?'&&s[n-1-i]!='?')
        {
            s[i] = s[n-1-i];
        }
        else if (s[n -1- i] == '?'&&s[i]!='?')
        {
            s[n -1- i] = s[i];
        }
        else if (s[n - 1 - i] == '?' && s[i] == '?')
        {
            s[i] = 'a';
            s[n - i - 1] = 'a';
        }
    }
    if (n % 2 != 0&& s[n/2]=='?')
    {
        s[n / 2] = 'a';
    }
    cout << s;
}
