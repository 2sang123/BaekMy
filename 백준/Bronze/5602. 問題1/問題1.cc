#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool com(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++)
    {
        arr.push_back({i+1,0 });
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int check;
            cin >> check;
            if (check == 1) arr[j].second = arr[j].second + 1;
        }
    }
    sort(arr.begin(), arr.end(), com);
    for (int i = 0; i < m; i++)
    {
        cout << arr[i].first << ' ';
    }
}
