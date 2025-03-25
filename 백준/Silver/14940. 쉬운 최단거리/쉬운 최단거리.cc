#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<bool>> visited;
void bfs(vector<vector<int>> &vec, pair<int, int> s)
{
    queue<pair<int,int>> q;
    q.push(s);
    visited[s.first][s.second] = false;
    vec[s.first][s.second] = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&visited[nx][ny]&&vec[nx][ny]!=0)
            {
                vec[nx][ny] = vec[cx][cy] + 1;
                q.push({nx,ny});
                visited[nx][ny] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, true));
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
            if (arr[i][j] == 2)
            {
                start.first = i;
                start.second = j;
            }
            else if (arr[i][j] == 0)
            {
                visited[i][j] = false;
            }
        }
    }
    bfs(arr, start);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && visited[i][j])
            {
                arr[i][j] = -1;
            }
        }
    }

    for (auto a : arr)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << '\n';
    }
}
