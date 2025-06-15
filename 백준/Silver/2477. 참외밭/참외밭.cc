#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int mx=0, my=0;
    vector<pair<int, int>> qure;
    int bigx = 0;
    int bigy = 0;
    for (int i = 0; i < 6; i++)
    {
        int num, k;
        cin >> num >> k;
        if (num == 1 || num == 2)
        {
            if (mx < k)
            {
                mx = k;
                bigx = i;
            }
        }
        else if (num == 3 || num == 4)
        {
            if (my < k)
            {
                my = k;
                bigy = i;
            }
        }
        qure.push_back({ num, k });
    }
    int small_w = abs(qure[(bigx + 1) % 6].second - qure[(bigx + 5) % 6].second);
    int small_h = abs(qure[(bigy + 1) % 6].second - qure[(bigy + 5) % 6].second);
    int bqure = mx * my;
    int squre = small_h * small_w;
    cout << (bqure - squre) * n;
}
