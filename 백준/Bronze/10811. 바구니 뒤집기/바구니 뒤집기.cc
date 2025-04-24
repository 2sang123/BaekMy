#include <iostream>
#include <vector>
using namespace std;

void r(vector<int> &v, int s, int e) {
    if (s >= e) return;
    swap(v[s], v[e]);
    r(v, s + 1, e - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, j, k; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    while (m--) {
        cin >> j >> k;
        r(v, j - 1, k - 1);
    }
    for (int i : v) cout << i << ' ';
}