#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> sarr;

int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0 , 0, -1, 1 };
vector<vector<bool>> visited;

void dfs(int x, int y, char start)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && sarr[nx][ny] == start)
        {
            dfs(nx, ny,start);
        }
    }
}

void dfsB(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && sarr[nx][ny]!='B')
        {
            dfsB(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string s;
    sarr.resize(n);
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        cin >> sarr[i];
    }
    int cntR = 0;
    int cntG = 0;
    int cntB = 0;
    int cntRG = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j]&&sarr[i][j]=='R')
            {
                dfs(i, j,sarr[i][j]);
                cntR++;
            }
            else if (!visited[i][j] && sarr[i][j] == 'G')
            {
                dfs(i, j, sarr[i][j]);
                cntG++;
            }
            else if (!visited[i][j] && sarr[i][j] == 'B')
            {
                dfs(i, j, sarr[i][j]);
                cntB++;
            }
        }
    }
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j]&&sarr[i][j]!='B')
            {
                dfsB(i, j);
                cntRG++;
            }
        }
    }
    cout << cntR + cntG + cntB << ' ' << cntRG + cntB;
}