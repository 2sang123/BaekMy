#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> dp(1005,-1);
vector<int> arr;
int n;
int bfs()
{
    queue<int> q;
    q.push(0);
    dp[0] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int jump = arr[cur];
        for (int i = 1; i <= jump; i++)
        {
            int next = cur + i;
            if (next >= n) return dp[cur] + 1;
            if (dp[next] == -1)
            {
                dp[next] = dp[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    bfs();
    cout << dp[n-1];
}
