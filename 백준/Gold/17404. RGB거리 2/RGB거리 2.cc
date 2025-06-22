#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, g, b = 0;

    cin >> n;
    vector < vector<int>> color(n, vector<int>(3));
    
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    int ans = 1e9;
    
    for (int f = 0; f < 3; f++)
    {
        vector < vector<int>> cost(n, vector<int>(3,1e9));
        cost[0][f] = color[0][f];
        for (int i = 1; i < n; i++)
        {
            cost[i][0] = color[i][0] + min(cost[i - 1][1], cost[i - 1][2]);
            cost[i][1] = color[i][1] + min(cost[i - 1][0], cost[i - 1][2]);
            cost[i][2] = color[i][2] + min(cost[i - 1][0], cost[i - 1][1]);
        }
        for (int j = 0; j < 3; j++)
        {
            if (j != f) ans = min(ans, cost[n - 1][j]);
        }
    }
    cout << ans;
}