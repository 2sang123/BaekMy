#include <iostream>
#include <algorithm>
using namespace std;

int ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    int cross = (B.first - A.first) * (C.second - A.second)
        - (B.second - A.second) * (C.first - A.first);

    if (cross > 0) return 1;      // 반시계 방향 (CCW)
    if (cross < 0) return -1;     // 시계 방향 (CW)
    return 0;                     // 일직선 (colinear)
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    pair<int, int> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    cout<<ccw(a, b, c);
}
