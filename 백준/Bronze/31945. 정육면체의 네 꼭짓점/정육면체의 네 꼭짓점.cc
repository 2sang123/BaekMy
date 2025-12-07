#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a, b, c, d;
    vector<vector<int>> g = { {0,1,2,3},{0,1,4,5},{0,2,4,6},{1,3,5,7},{2,3,6,7},{4,5,6,7} };
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        vector<int> p = { a, b, c,d };
        sort(p.begin(), p.end());
        bool ch = false;
        for (int i = 0; i < 6; i++)
        {
            if (g[i] == p)
            {
                cout << "YES" << '\n';
                ch = true;
                break;
            }
        }
        if (!ch)
        {
            cout << "NO" << '\n';
        }
    }
}
