#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<long long> arr;
bool sorRule(long long a, long long b) {
    int cnta = 0, cntb = 0;
    long long ta = a, tb = b;
    while (ta > 0 && ta % 3 == 0) 
    {
        cnta++;
        ta /= 3;
    }
    while (tb > 0 && tb % 3 == 0) 
    {
        cntb++;
        tb /= 3;
    }

    if (cnta != cntb) return cnta > cntb;
    return a < b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long b;
        cin >> b;
        arr.push_back(b);
    }
    sort(arr.begin(), arr.end(), sorRule);
    for (auto out : arr)
    {
        cout << out << ' ';
    }
}
