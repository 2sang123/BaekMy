#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n ,k;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<int> bag(k);
    vector<pair<int, int>> jewels;
    for (int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        jewels.push_back({ m, v });
    }

    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(jewels.begin(), jewels.end());
    sort(bag.begin(), bag.end());
    long long sum = 0;
    int check = 0;

    for (int i = 0; i < k; i++)
    {
        int cBag = bag[i];

        while (check < n && jewels[check].first <= cBag) {
            pq.push(jewels[check].second);
            check++;
        }

        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    
    cout << sum;
}
