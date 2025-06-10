#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int ccw(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C) {
    ll cross = (B.first - A.first) * (C.second - A.second)
        - (B.second - A.second) * (C.first - A.first);

    if (cross > 0) return 1;      // 반시계 방향 (CCW)
    if (cross < 0) return -1;     // 시계 방향 (CW)
    return 0;                     // 일직선 (colinear)
}

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
vector<pair<ll, ll>> ps;
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    auto pivot = ps[0];
    ll c = ccw(pivot, a, b);
    if (c == 0) return dist(pivot, a) < dist(pivot, b);
    return c > 0;
}

int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        pair<ll, ll> point;
        cin >> point.first >> point.second;
        ps.push_back(point);
    }
    // 기준점 선택 (y가 가장 작고, 같으면 x가 작은)
    sort(ps.begin(), ps.end(), [](pair<ll, ll>& a, pair<ll, ll>& b) 
        {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
        });

    // 극각 정렬
    sort(ps.begin() + 1, ps.end(), cmp);
    //Graham Scan
    vector<pair<ll, ll>> hull;
    for (auto& p : ps)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }
    cout << hull.size();
}
