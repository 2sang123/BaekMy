#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<char>> graph;
int bfs(int x, int y, char c)
{
    if (!visited[x][y]) return 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = false;
    int cnt = 1;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny])
            {
                if (graph[nx][ny] == c)
                {
                    cnt++;
                    q.push({ nx,ny });
                    visited[nx][ny] = false;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    graph.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m,true));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    long long bp = 0;
    long long wp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'W')
            {
                long long w = bfs(i, j, 'W');
                wp += w * w;
            }
        }
    }
    visited.assign(n, vector<bool>(m, true));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'B')
            {
                long long b = bfs(i, j, 'B');
                bp += b * b;
            }
        }
    }
    cout << wp << ' ' << bp;
}
