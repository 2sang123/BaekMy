#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool incircle(pair<int, int> tp, pair<int, int> cp, long long r)
{
    long long dx = (cp.first - tp.first) * (cp.first - tp.first);
    long long dy = (cp.second - tp.second) * (cp.second - tp.second);
    if (r * r >= dx + dy) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    pair<int, int> sp, ep;
    cin >> t;
    
    while (t--)
    {
        cin >> sp.first >> sp.second >> ep.first >> ep.second;
        int n;
        pair<int, int> cp;
        int r;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> cp.first >> cp.second >> r;
            if (!incircle(sp, cp, r) && incircle(ep, cp, r))
            {
                cnt++;
            }
            else if (incircle(sp, cp, r) && !incircle(ep, cp, r))
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}
