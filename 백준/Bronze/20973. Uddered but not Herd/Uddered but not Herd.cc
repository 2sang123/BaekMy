#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s;
string a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> s;
    int cnt = 0;
    int start = 0;
    while (true)
    {
        if (start >= s.size()) break;
        for (int i = 0; i <a.size(); i++)
        {
            if (s[start] == a[i])
            {
                start++;
            }
        }
        cnt++;
    }
    cout << cnt;
}
