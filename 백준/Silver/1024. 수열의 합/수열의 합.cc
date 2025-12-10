#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll n, l;

ll count(ll s)
{
    if (s > 100) return -1;
    ll num = (n / s) - (s - 1) / 2;
    if (num < 0)
    {
        return count(s+1);
    }
    ll sum = 0;
    for (ll i = num; i < num+s; i++)
    {
        sum += i;
        if (sum == n) return num;
    }
    return count(s+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;
    ll start = count(l);
    if (start >= 0)
    {
        ll sum = 0;
        while (sum < n)
        {
            cout << start << ' ';
            sum += start;
            start++;
        }
    }
    else
    {
        cout << start;
    }
}
