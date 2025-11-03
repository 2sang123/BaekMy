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
    vector<vector<int>> ap(26, vector<int>(s.size()));
    for (int i = 0; i < s.size(); i++)
    {
        ap[s[i] - 'a'][i]++;
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        int s, e;
        int sum = 0;
        cin >> c >> s >> e;
        for (int j = s; j <= e; j++)
        {
            sum += ap[c - 'a'][j];
        }
        cout << sum << '\n';
    }
}
