#include <iostream>
#include <vector>
using namespace std;

int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1, 1 };
vector<vector<bool>> visit;
vector<vector<char>> campus;
int cnt = 0;
void dfs(int sx, int sy)
{
    visit[sx][sy] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny])
        {
            if (campus[nx][ny] == 'P') cnt++;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    campus.assign(n, vector<char>(m));
    visit.assign(n, vector<bool>(m, false));

    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> campus[i][j];
            if (campus[i][j] == 'I')
            {
                sx = i;
                sy = j;
            }
            else if (campus[i][j] == 'X')
            {
                visit[i][j] = true;
            }
        }
    }
    dfs(sx, sy);
    if (cnt <= 0)
    {
        cout << "TT";
    }
    else cout << cnt;
}

