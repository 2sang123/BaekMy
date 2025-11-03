#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin >> s;
    cin >> n;
    vector<vector<int>> ap(26, vector<int>(s.size()+1));
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        for (int j = 0; j < 26; j++)
        {
            ap[j][i + 1] = ap[j][i] + (j == idx);
        }
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        int s, e;
        int sum = 0;
        cin >> c >> s >> e;
        int idx = c - 'a';
        
        cout << ap[idx][e + 1] - ap[idx][s] << '\n';
    }
}
