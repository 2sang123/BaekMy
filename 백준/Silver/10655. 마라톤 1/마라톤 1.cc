#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> check;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        check.push_back({ x,y });
    }
    ll out = 1e9;
    ll sum = 0;
    for (int i = 0; i < check.size()-1; i++)
    {
        ll d = abs(check[i].first - check[i + 1].first) + abs(check[i].second - check[i + 1].second);
        sum += d;
    }
    int move = 0;
    while (true)
    {
        if (move >= n-2) break;
        ll jump1 = abs(check[move].first - check[move + 1].first) + 
            abs(check[move].second - check[move + 1].second);
        
        ll jump2 = abs(check[move+1].first - check[move + 2].first) +
            abs(check[move+1].second - check[move + 2].second);

        ll change = abs(check[move].first - check[move + 2].first) +
            abs(check[move].second - check[move + 2].second);
        out = min(out, sum+change - (jump1+jump2));
        move++;
    }
    cout << out;

}
