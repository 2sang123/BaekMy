#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;
    int mx = -4001;
    int mn = 4001;
    vector<int> cnt(8002);
    vector<int> mid;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum += num;
        mid.push_back(num);
        cnt[num + 4000]++;
        mx = max(num, mx);
        mn = min(num, mn);
    }
    int mcnt = 0;
    int most = 0;
    vector<int> mosts;
    for (int i = 0; i < cnt.size(); i++)
    {
            if (mcnt < cnt[i])
            {
                mcnt = cnt[i];
                mosts.clear();
                mosts.push_back(i-4000);
            }
            else if (mcnt == cnt[i])
            {
                mosts.push_back(i-4000);
            }   
    }
    if (mosts.size() > 1)
    {
        sort(mosts.begin(), mosts.end());
        most = mosts[1];
    }
    else most = mosts.front();
    sort(mid.begin(), mid.end());
    int middle = mid[n / 2];
    int aver=round((double)sum / n);
    int ran = mx - mn;

    cout << aver << '\n' << middle << '\n' << most << '\n' << ran;
}
