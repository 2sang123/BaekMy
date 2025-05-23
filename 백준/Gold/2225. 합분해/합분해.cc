#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<vector<int>>dp(n+k+1, vector<int>(k+1, 0));
    for (int i = 0; i <= n+k; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n+k; i++) 
    {
        for (int j = 1; j <= k; j++) 
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%MOD;
        }
    }
    
    cout << dp[n+k-1][k-1] << endl;
}
