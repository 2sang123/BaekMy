#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
using namespace std;
int n = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    array<int, 3> dp, dp2;
    cin >> dp[0] >> dp[1] >> dp[2];
    dp2 = dp;
    for (int i = 1; i < n; i++) {
        array<int, 3> lines;
        cin >> lines[0] >> lines[1] >> lines[2];

        int prev0 = dp[0], prev1 = dp[1], prev2 = dp[2];
        int prev_min0 = dp2[0], prev_min1 = dp2[1], prev_min2 = dp2[2];

        dp[0] = lines[0] + max(prev0, prev1);
        dp[1] = lines[1] + max({ prev0, prev1, prev2 });
        dp[2] = lines[2] + max(prev1, prev2);

        dp2[0] = lines[0] + min(prev_min0, prev_min1);
        dp2[1] = lines[1] + min({ prev_min0, prev_min1, prev_min2 });
        dp2[2] = lines[2] + min(prev_min1, prev_min2);
    }

    cout << max({ dp[0], dp[1], dp[2] }) << ' ' << min({ dp2[0], dp2[1], dp2[2] });
}

