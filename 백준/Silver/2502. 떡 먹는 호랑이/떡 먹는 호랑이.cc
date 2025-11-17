#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long d, k;
    cin >> d >> k;
    vector<long long> dp(100002);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 100001; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int i = 1; i <= k; i++)
    {
        long long tmp = k - dp[d - 2] * i;
        if (tmp % dp[d - 1] != 0) continue;

        long long b = tmp / dp[d - 1];
        if (b >= 1)
        {
            cout << i << '\n' << b;
            break;
        }
    }
}
