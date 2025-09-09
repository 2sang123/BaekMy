#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            arr.push_back(c);
        }
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        auto rangeSum = [&](int l, int r)
            {
                return prefix[r + 1] - prefix[l];
            };
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (l == r) dp[l][r] = arr[l];
                else {
                    dp[l][r] = rangeSum(l, r) - min(dp[l + 1][r], dp[l][r - 1]);
                }
            }
        }
        cout << dp[0][n - 1] << "\n";
    }
}
