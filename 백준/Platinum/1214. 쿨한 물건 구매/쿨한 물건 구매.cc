#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll d, p, q;
    cin >> d >> p >> q;
    ll out = d / (p * q) * (p * q);
    if (out > 0)
    {
        out -= p * q;
    }
    d -= out;
    if (p < q) swap(p, q);
    ll mins = 2e9;
    for (ll i = 0; i*p <=d+p ; i++)
    {
        mins = min(mins, i * p + ((d - p * i + q - 1) / q) * q);
    }
    out += mins;
    cout << out;
}
