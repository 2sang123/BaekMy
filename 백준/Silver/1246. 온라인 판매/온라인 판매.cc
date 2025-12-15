#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> cost;
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        cost.push_back(p);
    }
    sort(cost.begin(), cost.end());
    int price, sum = 0;
    for (int i = 0; i < cost.size(); i++)
    {
        int egg = min(n, (int)cost.size() - i);
        int sell = egg * cost[i];
        if (sell >= sum)
        {
            sum = sell;
            price = cost[i];
        }
    }
    cout << price << ' ' << sum;
}
