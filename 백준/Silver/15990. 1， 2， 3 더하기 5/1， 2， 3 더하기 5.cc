#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000009;
int t;
vector<tuple<long, long, long>> vec(100002, {0, 0, 0});
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    vec[0] = { 0, 0, 0 };
    vec[1] = { 1, 0, 0 };
    vec[2] = { 0, 1, 0 };
    vec[3] = { 1,1,1 };
    for (int i = 4; i <= 100001; i++)
    {
        long long x1, x2, emp1;
        long long y, yy, emp2;
        long long z1, z2, emp3;
        tie(emp1, x1, x2) = vec[i - 1];
        tie(y, emp2, yy) = vec[i - 2];
        tie(z1, z2, emp3) = vec[i - 3];
        vec[i] = { (x1 + x2)%MOD, (y + yy)%MOD, (z1 + z2)%MOD };
    }
    while (t--)
    {
        long long n;
        cin >> n;
        long long sum = (get<0>(vec[n]) + get<1>(vec[n]) + get<2>(vec[n]))%MOD;
        cout << sum << '\n';
    }
    
}
