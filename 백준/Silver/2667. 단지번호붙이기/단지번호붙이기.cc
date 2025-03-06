#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n;
int area = 0;
void dfs(int x, int y)
{
    visited[x][y] = true;
    area++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (grid[nx][ny] == 1 && !visited[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    grid.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }
    int components = 0;
    vector<int> out;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                components++;
                out.push_back(area);
                area = 0;
            }
        }
    }
    sort(out.begin(), out.end());
    cout << components<<'\n';
    for (auto a : out)
    {
        cout << a << '\n';
    }
}
