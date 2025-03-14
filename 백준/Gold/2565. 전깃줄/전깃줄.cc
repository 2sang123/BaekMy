#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
int n;

pair<int, int> line;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int>dp(n+1, 1);
    vector<pair<int, int>> lines;
    for (int i = 0; i < n; i++)
    {
        cin >> line.first >> line.second;
        lines.push_back(line);
    }
    sort(lines.begin(), lines.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.first < b.first;
        });
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (lines[i].second > lines[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;

            }
        }
    }
    int out = n - *max_element(dp.begin(), dp.end());
    cout << out;
}
