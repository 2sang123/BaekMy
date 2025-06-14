#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int square_dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> p(4);
        for (int i = 0; i < 4; ++i) {
            cin >> p[i].first >> p[i].second;
        }

        vector<int> dists;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                dists.push_back(square_dist(p[i], p[j]));
            }
        }

        sort(dists.begin(), dists.end());

        if (dists[0] > 0 &&
            dists[0] == dists[1] &&
            dists[1] == dists[2] &&
            dists[2] == dists[3] &&
            dists[4] == dists[5] &&
            dists[4] == 2 * dists[0]) 
        {
            cout << "1\n";
        }
        else 
        {
            cout << "0\n";
        }
    }
}
