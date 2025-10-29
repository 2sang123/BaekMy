#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string s;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    vector<ll> leftg(n, 0), rightg(n, 0);
    vector<ll> lefth(n, 0), righth(n, 0);

    ll curg = 0;
    ll curh = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'H')
        {
            leftg[i] = curg;
            curg = 0;
            curh++;
        }
        else
        {
            lefth[i] = curh;
            curh = 0;
            curg++;
        }
    }
    curg = 0;
    curh = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'H')
        {
            rightg[i] = curg;
            curg = 0;
            curh++;
        }
        else
        {
            righth[i] = curh;
            curh = 0;
            curg++;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'H')
        {
            ll l = leftg[i];
            ll r = rightg[i];
            cnt += (r * l) + max(0LL, l - 1) + max(0LL, r - 1);
        }
        else
        {
            ll l = lefth[i];
            ll r = righth[i];
            cnt += (r * l) + max(0LL, l - 1) + max(0LL, r - 1);
        }
    }
    cout << cnt;
}
