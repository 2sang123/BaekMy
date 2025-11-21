#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> jarr(n+1, vector<int>(m+1));
    vector<vector<int>> iarr(n+1, vector<int>(m+1));
    vector<vector<int>> oarr(n+1, vector<int>(m+1));
    vector<vector<char>> world(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> world[i][j];
            if (world[i][j] == 'J')
            {
                jarr[i + 1][j + 1] = jarr[i + 1][j] + jarr[i][j + 1] - jarr[i][j] + 1;
                iarr[i + 1][j + 1] = iarr[i + 1][j] + iarr[i][j + 1] - iarr[i][j];
                oarr[i + 1][j + 1] = oarr[i + 1][j] + oarr[i][j + 1] - oarr[i][j];
            }
            else if (world[i][j] == 'I')
            {
                jarr[i + 1][j + 1] = jarr[i + 1][j] + jarr[i][j + 1] - jarr[i][j];
                iarr[i + 1][j + 1] = iarr[i + 1][j] + iarr[i][j + 1] - iarr[i][j]+1;
                oarr[i + 1][j + 1] = oarr[i + 1][j] + oarr[i][j + 1] - oarr[i][j];
            }
            else if (world[i][j] == 'O')
            {
                jarr[i + 1][j + 1] = jarr[i + 1][j] + jarr[i][j + 1] - jarr[i][j];
                iarr[i + 1][j + 1] = iarr[i + 1][j] + iarr[i][j + 1] - iarr[i][j];
                oarr[i + 1][j + 1] = oarr[i + 1][j] + oarr[i][j + 1] - oarr[i][j]+1;
            }
        }
    }
    int sx, sy, ex, ey;
    for (int i = 0; i < k; i++)
    {
        cin >> sx >> sy >> ex >> ey;
        cout << jarr[ex][ey] - jarr[sx - 1][ey] - jarr[ex][sy - 1] + jarr[sx - 1][sy - 1] << ' ';
        cout << oarr[ex][ey] - oarr[sx - 1][ey] - oarr[ex][sy - 1] + oarr[sx - 1][sy - 1] << ' ';
        cout << iarr[ex][ey] - iarr[sx - 1][ey] - iarr[ex][sy - 1] + iarr[sx - 1][sy - 1] << ' ';
        cout << '\n';
    }
}
