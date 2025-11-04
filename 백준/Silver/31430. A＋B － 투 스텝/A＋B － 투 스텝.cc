#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
    {
        long long a, b;
        cin >> a >> b;
        long long k = a + b;
        string s = "aaaaaaaaaaaaa";
        for (int i = 0; i < s.size(); i++)
        {
            if (k)
            {
                s[i] = (k % 26) + 'a';
                k /= 26;
            }
            else break;
        }
        cout << s << '\n';
    }
    else
    {
        string s;
        cin >> s;
        long long a = 0, r = 1;
        for (int i = 0; i < s.size(); i++)
        {
            a += (s[i] - 'a') * r;
            r *= 26;
        }
        cout << a << '\n';
    }
    return 0;
}
