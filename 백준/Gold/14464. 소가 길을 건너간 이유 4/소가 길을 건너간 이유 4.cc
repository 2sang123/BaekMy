#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c, n;
    cin >> c >> n;
    vector<int> ctime;
    for (int i = 0; i < c; i++)
    {
        int t;
        cin >> t;
        ctime.push_back(t);
    }
    vector<pair<int, int>> ntime(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ntime[i].first >> ntime[i].second;
    }
    sort(ctime.begin(), ctime.end());
    sort(ntime.begin(), ntime.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
    int i = 0;
    for (int t: ctime)
    {
        while (i < n && ntime[i].first <= t)
        {
            pq.push(ntime[i].second);
            i++;
        }
        while (!pq.empty() && pq.top() < t)
            pq.pop();

        if (!pq.empty()) {
            pq.pop();
            cnt++;
        }
    }
    cout << cnt;
}
