#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int n;

vector<pair<int, int>> vec(1001, {0, 0});
bool check[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
    }
    for (int i = 0; i < n-2; i++)
    {
        unordered_map<float, int> um;
        int a, b = 0;
        check[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (check[j]) continue;
            if (vec[i].first == vec[j].first)
            {
                if (um.count(5000)) um[5000]++;
                else um.insert({ 5000,1 });
                ans = max(ans, um[5000]);
            }
            else
            {
                float k = (float)(vec[i].second - vec[j].second) /
                    (vec[i].first - vec[j].first);
                if (um.count(k)) um[k]++;
                else um.insert({ k,1 });
                ans = max(ans, um[k]);
            }
        }
    }
    if (ans > 1) cout << ans+1;
    else cout << -1;
}