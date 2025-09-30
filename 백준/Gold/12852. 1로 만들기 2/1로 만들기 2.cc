#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int minN = 0;
    vector<ll> dp(n + 1, 0);
    vector<ll> test;
    ll t = n;
    test.push_back(t);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            if (dp[i] < dp[i / 2] + 1)
            {
                minN = dp[i];
            }
            else
            {
                minN = dp[i / 2] + 1;
            }
            dp[i] = minN;
        }
        if (i % 3 == 0)
        {
            if (dp[i] < dp[i / 3] + 1)
            {
                minN = dp[i];
            }
            else
            {
                minN = dp[i / 3] + 1;
            }
            dp[i] = minN;
        }
    }
    cout << dp[n] << '\n';
    while (t > 1)
    {
        ll arr[3] = { t - 1, (t % 2 == 0 ? t / 2 : -1), (t % 3 == 0 ? t / 3 : -1) };
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] > 0 && dp[arr[i]] == dp[t] - 1)
            {
                t = arr[i];
                test.push_back(arr[i]);
                break;
            }
        }
        
    }
    for (auto out : test)
    {
        cout << out << ' ';
    }
}
