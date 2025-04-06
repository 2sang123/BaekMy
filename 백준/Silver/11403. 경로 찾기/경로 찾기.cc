#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> graph[1001];


vector<bool> bfs(int s)
{
    vector<bool> visit(n, false);
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int next : graph[node])
        {
            if (visit[next] == false)
            {
                visit[next] = true;
                q.push(next);
            }

        }
    }
    return visit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                graph[i].push_back(j);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        vector<bool> reachable = bfs(i);
        for (int j = 0; j < n; j++)
        {
            if (reachable[j]) mat[i][j] = 1;
        }
    }

    for (auto a : mat)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << '\n';
    }
}

