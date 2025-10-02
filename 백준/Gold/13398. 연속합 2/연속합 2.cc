#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = arr[0];
    dp[0][1] = -1e9;

    int ans = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max({ ans, dp[i][0], dp[i][1] });
    }

    cout << ans;
}
