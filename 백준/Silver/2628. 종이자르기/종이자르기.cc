#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int wid, hei, cut;
    cin >> wid >> hei >> cut;
    vector<int> wcut;
    vector<int> hcut;
    wcut.push_back(0);
    wcut.push_back(wid);
    hcut.push_back(0);
    hcut.push_back(hei);

    for (int i = 0; i < cut; i++)
    {
        int r, p;
        cin >> r >> p;
        if (r == 1)
        {
            wcut.push_back(p);
        }
        else
        {
            hcut.push_back(p);
        }
    }
    sort(wcut.begin(), wcut.end());
    sort(hcut.begin(), hcut.end());
    int mw = 0, mh = 0;
    for (int i = 0; i < wcut.size(); i++)
    {
        if (i < wcut.size() - 1)
        {
            mw = max(mw,abs(wcut[i + 1] - wcut[i]));
        }
    }
    for (int i = 0; i < hcut.size(); i++)
    {
        if (i < hcut.size() - 1)
        {
            mh = max(mh, abs(hcut[i + 1] - hcut[i]));
        }
    }
    cout << mh * mw;
}
