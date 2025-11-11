#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<vector<int>> city;
vector<pair<int, int>> chicken;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    city.assign(n, vector<int>(n));
    vector<pair<int, int>> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ch;
            cin >> ch;
            city[i][j] = ch;
            if (ch == 2) chicken.push_back({ i,j });
            else if (ch == 1) start.push_back({ i,j });
        }
    }
    vector<int> comb(chicken.size(), 0);
    fill(comb.end() - m, comb.end(), 1);
    int mdist = 1e9;
    do {
        int sum = 0;
        for (auto [hx, hy] : start) {
            int dist = 1e9;
            for (int i = 0; i < chicken.size(); i++) {
                if (comb[i]) {
                    int cx = chicken[i].first;
                    int cy = chicken[i].second;
                    dist = min(dist, abs(hx - cx) + abs(hy - cy));
                }
            }
            sum += dist;
        }
        mdist = min(mdist, sum);
    } while (next_permutation(comb.begin(), comb.end()));
    cout << mdist;
}
