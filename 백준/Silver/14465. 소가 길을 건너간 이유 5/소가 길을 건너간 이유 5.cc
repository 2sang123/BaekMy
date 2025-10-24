#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> b;
    vector<int> lights(n, 1);
    for (int i = 0; i < b; i++)
    {
        int black;
        cin >> black;
        lights[black - 1] = 0;
    }
    int mRepair = b;
    int bcnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (lights[i] == 0) bcnt++;
    }
    mRepair = bcnt;
    for (int i = k; i < n; i++)
    {
        if (lights[i - k] == 0) bcnt--;
        if (lights[i] == 0) bcnt++;
        mRepair = min(mRepair, bcnt);
    }
    cout << mRepair;
}
