#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int finds(int x, vector<int> & p)
{
    if (p[x] != x)
    {
        p[x] = finds(p[x], p);
    }
    return p[x];
}
void unite(int a, int b, vector<int>& p)
{
    a = finds(a, p);
    b = finds(b, p);
    p[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g, p;
    cin >> g >> p;
    vector<int> parent(g + 1);
    for (int i = 0; i <= g; i++)
    {
        parent[i] = i;
    }
    int cnt = 0;
    for (int i = 0; i < p; i++)
    {
        int gi;
        cin >> gi;
        int big = finds(gi, parent);
        if (big == 0) break;
        unite(big, big-1, parent);
        cnt++;
    }
    cout << cnt;
}
