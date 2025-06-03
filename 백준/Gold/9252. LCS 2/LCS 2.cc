#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string s, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> n;
    int len1 = s.size(), len2 = n.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s[i - 1] == n[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = len1, j = len2;
    string result;

    while (i > 0 && j > 0) {
        if (s[i - 1] == n[j - 1]) {
            result += s[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }

    reverse(result.begin(), result.end());
    cout << result.size() << '\n';
    if (result.size() > 0)
    {
        cout << result;
    }

}
