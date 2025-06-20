#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

bool isRightAngle(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    long long x1 = A.first - B.first;
    long long y1 = A.second - B.second;
    long long x2 = C.first - B.first;
    long long y2 = C.second - B.second;

    return x1 * x2 + y1 * y2 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        points.push_back(p);
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                pair<int, int> A = points[i];
                pair<int, int> B = points[j];
                pair<int, int> C = points[k];

                // ∠ABC
                if (isRightAngle(A, B, C)) cnt++;
                // ∠ACB
                else if (isRightAngle(A, C, B)) cnt++;
                // ∠BAC
                else if (isRightAngle(B, A, C)) cnt++;
            }
        }
    }
    cout << cnt;
}
