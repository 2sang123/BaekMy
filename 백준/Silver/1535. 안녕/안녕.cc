#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int hp = 100;
    vector<int> damage(n + 1);
    vector<int> happy(n + 1);
    vector<int> dp(100, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> damage[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> happy[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 99; j >=damage[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-damage[i]] + happy[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

