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
    int cnt = 0;
    vector<int> ap(26);
    string s;
    cin >> s;
    int ts = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        ap[s[i] - 'A']++;
    }
    for (int i = 0; i < n-1; i++)
    {
        cin >> s;
        int check = 0;
        vector<int> cap(26,0);
        for (int j = 0; j < s.size(); j++)
        {
            cap[s[j] - 'A']++;
        }
        for (int j = 0; j < 26; j++)
        {
            check += abs(ap[j] - cap[j]);
        }
        if (check <= 1) cnt++;
        else if (check == 2 && ts == s.size()) cnt++;
    }
    cout << cnt;
}
