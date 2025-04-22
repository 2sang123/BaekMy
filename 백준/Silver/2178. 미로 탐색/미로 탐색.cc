#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> dist;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    dist[x][y] = 1;
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (grid[nx][ny] == 1 && dist[nx][ny]==-1)
                {
                    dist[nx][ny] = dist[cx][cy]+1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n>>m;
    grid.assign(n, vector<int>(m));
    dist.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }
    bfs(0,0);

    cout << dist[n-1][m-1] << '\n';

}
