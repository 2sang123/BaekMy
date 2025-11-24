#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    bool t = false;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll cnt = 0;
    ll b = arr[0];
    
    for (ll i = 1; i < arr.size(); i++)
    {
        if (arr[i] <= b)
        {
            if (arr[i] + k <= b)
            {
                cnt = -1;
                break;
            }
            else
            {
                cnt++;
                b = arr[i] + k;
            }
        }
        else
        {
            b = arr[i];
        }
    }
    cout << cnt;
}
