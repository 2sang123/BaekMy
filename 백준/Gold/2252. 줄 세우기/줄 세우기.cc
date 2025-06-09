#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[32001];
int in[32001];

void topolSort()
{
    int result[32001] = { 0, };
    queue<int> q;
    for (int i = 1; i <=n; i++)
    {
        if (in[i] == 0) q.push(i);
    }

    for (int i = 1; i <=n; i++)
    {
        if (q.empty())
        {
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if (--in[y] == 0)
                q.push(y);
        }
    }
    for (int i = 1; i <=n; i++)
    {
        cout << result[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in[v]++;
    }
    topolSort();
}
