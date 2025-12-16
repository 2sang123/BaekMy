#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, b, h, w;
    cin >> n >> b >> h >> w;
    int p;
    int cost = 1e8;
    for (int i = 0; i < h; i++)
    {
        cin >> p;
        int a;
        for (int j = 0; j < w; j++)
        {
            cin >> a;
            if (a >= n && p*n<=b)
            {
                cost = min(cost, p * n);
            }
        }
    }
    if (cost == 1e8)
    {
        cout << "stay home";
    }
    else
    {
        cout << cost;
    }
}
