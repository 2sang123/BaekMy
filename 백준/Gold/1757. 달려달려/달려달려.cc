#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001][501][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 0; j <=m ; j++)
        {
            if (j != 1)
            {
                if (j > 0) 
                {
                    dp[i][j][1] = dp[i - 1][j - 1][1] + arr[i];
                    dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
                }
                else 
                {
                    dp[i][j][0] = max({ dp[i - 1][j + 1][0], dp[i - 1][j + 1][1], dp[i - 1][j][0] });
                }
            }
            else
            {
                dp[i][j][1] = dp[i - 1][j - 1][0] + arr[i];
                dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
            }
        }
    }
    cout << dp[n][0][0];
}
