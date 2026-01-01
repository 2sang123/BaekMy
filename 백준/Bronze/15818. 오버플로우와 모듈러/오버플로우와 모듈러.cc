#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long mul=1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mul = (mul*(a % m))%m;
    }
    cout << mul;
}
