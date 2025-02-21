#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> vec(n+1);
    vector<int> dp(1002);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + vec[j]);
        }
    }

    cout << dp[n];
}
