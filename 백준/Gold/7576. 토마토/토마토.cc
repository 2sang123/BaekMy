#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<bool>> blocked;
int day = -1;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0, -1, 1 };

vector<pair<int,int>> bfs(vector<pair<int, int>> sp)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < sp.size(); i++)
    {
        q.push({ sp[i].first, sp[i].second });
    }
    vector<pair<int, int>> test;
    pair<int, int> re;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&blocked[nx][ny])
            {
                if (matrix[nx][ny] == 0)
                {
                    matrix[nx][ny] = 1;
                    re.first = nx;
                    re.second = ny;
                    test.push_back(re);
                }
            }
        }
    }
    return test;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    matrix.assign(m, vector<int>(n));
    blocked.assign(m, vector<bool>(n,true));
    pair<int, int> start;
    vector<pair<int, int>> sp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1)
            {
                blocked[i][j] = false;
            }
            else if (matrix[i][j] == 1)
            {
                start.first = i;
                start.second = j;
                sp.push_back(start);
            }
        }
    }
    while (!sp.empty())
    {
        sp = bfs(sp);
        day++;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                day = -1;
                break;
            }
        }
    }
    cout << day;
}
