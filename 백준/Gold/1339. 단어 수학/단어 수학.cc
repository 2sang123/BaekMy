#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long

vector<ll> alpha(26);
vector<bool> nzero(26, false);
set<int> used;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        nzero[s[0] - 'A'] = true;
        ll num = 1;
        for (int j = s.size()-1; j>=0; j--)
        {
            int c = s[j] - 'A';
            used.insert(c);
            alpha[c] += num;
            num *= 10;
        }
    }
    vector<int> chars(used.begin(), used.end());
    if (chars.size() == 10)
    {
        ll midx = 1e18;
        int zchar = -1;

        for (int c : chars)
        {
            if (!nzero[c] && alpha[c] < midx)
            {
                midx = alpha[c];
                zchar = c;
            }
        }

        if (zchar == -1)
        {
            for (int t : chars)
            {
                if (alpha[t] < midx)
                {
                    midx = alpha[t];
                    zchar = t;
                }
            }
        }

        alpha[zchar] = 0;
    }

    sort(chars.begin(), chars.end(), [&](int a, int b) {
        return alpha[a] > alpha[b];
        });
    ll out = 0;
    int j = 9;
    for (int c : chars)
    {
        out += alpha[c] * j;
        j--;
    }
    cout << out;
}
