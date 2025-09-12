#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long cnt = 0;
    long long count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '2')
        {
            cnt++;
        }
        else
        {
            for (int j = 1; j <= cnt; j++)
            {
                count += j * (cnt-j+1);
            }
            cnt = 0;
        }
    }
    if (cnt != 0)
    {
        for (int j = 1; j <= cnt; j++)
        {
            count += j * (cnt - j + 1);
        }
    }
    cout << count;
}
