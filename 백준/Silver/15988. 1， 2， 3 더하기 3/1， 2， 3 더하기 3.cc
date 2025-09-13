#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long MOD = 1000000009;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int c;
        cin >> c;
        vector<long long> dp(c + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= c; i++)
        {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%MOD;
        }
        cout << dp[c]%MOD << '\n';
    }
}
