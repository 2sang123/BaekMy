#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<bool> incount(200002, false);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (incount[a] && b == 0)
        {
            incount[a] = false;
        }
        else if (incount[a] && b == 1)
        {
            cnt++;
        }
        else if (!incount[a] && b == 0)
        {
            cnt++;
        }
        else if (!incount[a] && b == 1)
        {
            incount[a] = true;
        }
    }
    for (int i = 0; i < incount.size(); i++)
    {
        if (incount[i]) cnt++;
    }
    cout << cnt;
}
