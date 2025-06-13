#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<vector<int>> maps;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int x=-1, y=-1;
    int xx=-1, yy=-1;
    maps.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 1)
            {
                if (x == -1 && y == -1)
                {
                    y = i;
                    x = j;
                }
                else
                {
                    xx = j;
                    yy = i;
                }
            }
        }
    }
    int dist = abs(xx - x) + abs(yy - y);
    cout << dist;
}
