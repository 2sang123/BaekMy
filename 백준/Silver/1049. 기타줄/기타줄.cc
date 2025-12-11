#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int six=10000, one= 2000;
    for (int i = 0; i < m; i++)
    {
        int s, o;
        cin >> s >> o;
        six = min(s, six);
        one = min(o, one);
    }
    int cost = 0;
    if (one * 6 > six)
    {
        int p = n % 6;
        if (p * one < six)
        {
            cost = ((n / 6) * six) + p * one;
        }
        else
        {
            cost = ((n / 6) + 1) * six;
        }
    }
    else
    {
        cost = one * n;
    }
    cout << cost;
}
