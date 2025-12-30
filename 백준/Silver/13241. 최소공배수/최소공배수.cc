#include <iostream>
using namespace std;
long long gcd(int s, int r)
{
    if (r == 0)
    {
        return s;
    }
    return gcd(r, s % r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    cout << (a * b) / g;
}
