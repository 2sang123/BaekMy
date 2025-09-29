#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    vector<vector<int>> arr(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;
            int jump = arr[i][j];
            int ni = i + jump;
            int nj = j + jump;

            if (ni < n) dp[ni][j] += dp[i][j];
            if (nj < n) dp[i][nj] += dp[i][j];
        }
    }

    cout << dp[n - 1][n - 1] << "\n";
}
