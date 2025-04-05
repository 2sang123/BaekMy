#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, h;

int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };

vector<vector<vector<bool>>> blocked;
vector<vector<vector<int>>> box;

vector<tuple<int, int, int>> bfs(vector<tuple<int, int, int>> sp)
{
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < sp.size(); i++)
    {
        q.push({sp[i]});
    }
    
    vector<tuple<int, int, int>> test;
    tuple<int, int, int> re;

    while (!q.empty())
    {
        int cz, cy, cx;
        tie(cz, cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >=0 && nz<h && blocked[nz][ny][nx])
            {
                if (box[nz][ny][nx] == 0)
                {
                    box[nz][ny][nx] = 1;
                    re = { nz, ny, nx };
                    test.push_back(re);
                }
            }
        }
    }
    return test;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;

    box.assign(h, vector<vector<int>>(m, vector<int>(n)));
    blocked.assign(h, vector<vector<bool>>(m, vector<bool>(n, true)));

    vector<tuple<int, int, int>> starts;
    tuple<int, int, int> point;
    int day = -1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1)
                {
                    point = { i, j ,k };
                    starts.push_back(point);
                }
                else if (box[i][j][k] == -1)
                {
                    blocked[i][j][k] = false;
                }
            }
        }
    }

    while (!starts.empty())
    {
        starts = bfs(starts);
        day++;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (box[i][j][k] == 0)
                {
                    day = -1;
                    break;
                }
            }
        }
    }
    cout << day;
}

