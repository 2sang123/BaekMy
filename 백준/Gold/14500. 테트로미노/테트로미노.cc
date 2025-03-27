#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
int sumf = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0 ,-1, 1 };
vector<vector<bool>> visited;

void dfs(vector<vector<int>> &vec,int x, int y, int depth, int sum)
{
    if (depth == 4)
    {
        sumf = max(sum, sumf);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(vec, nx, ny, depth + 1, sum + vec[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

int middle_ex(vector<vector<int>>& vec, int x, int y)
{
    int maxV = 0;

    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m)
    {
        maxV = max(maxV, vec[x][y] + vec[x-1][y] + vec[x][y-1] + vec[x][y+1]);
    }

    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < n)
    {
        maxV = max(maxV, vec[x][y] + vec[x-1][y] + vec[x][y-1] + vec[x+1][y]);
    }

    if (y - 1 >= 0 && y + 1 < m && x + 1 < n)
    {
        maxV = max(maxV, vec[x][y] + vec[x][y-1] + vec[x][y+1] + vec[x+1][y]);
    }

    if (x - 1 >= 0 && y + 1 < m && x + 1 < n)
    {
        maxV = max(maxV, vec[x][y] + vec[x][y+1] + vec[x-1][y] + vec[x+1][y]);
    }
    return maxV;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    visited.assign(n, vector<bool>(m,false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(arr, i, j, 0, 0);
            visited[i][j] = false;
            sumf = max(sumf, middle_ex(arr, i, j));
        }
    }

    cout << sumf;
}
