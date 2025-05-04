#include <iostream>
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

bool isIntersect(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D) {
    long long ab_c = ccw(A, B, C);
    long long ab_d = ccw(A, B, D);
    long long cd_a = ccw(C, D, A);
    long long cd_b = ccw(C, D, B);

    // 일반적인 교차
    if (ab_c * ab_d <= 0 && cd_a * cd_b <= 0) {
        // colinear(일직선 상)의 경우, 범위 확인 필요
        if (ab_c * ab_d == 0 && cd_a * cd_b == 0) {
            if (A > B) swap(A, B);
            if (C > D) swap(C, D);
            return !(B < C || D < A); // 겹치지 않으면 false
        }
        return true;
    }
    return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    pair<ll, ll> a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;
    cout << isIntersect(a, b, c, d);
    
   
}
