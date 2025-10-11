#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'P') cout << "skipped" << '\n';
        else
        {
            int c = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '+')
                {
                    c = i;
                    break;
                }
            }
            string a = s.substr(0, c);
            string b = s.substr(c+1);
            cout << stoi(a) + stoi(b) << '\n';
        }
    }
}
