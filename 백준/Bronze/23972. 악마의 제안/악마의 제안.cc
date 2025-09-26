#include <iostream>
using namespace std;

long long k, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    if (n == 1) {
        cout << -1;
        return 0;
    }

    long long a = (n * k + (n - 2)) / (n - 1);
    if (k > a)
    {
        cout << -1;
        return 0;
    }
    cout << a;
}
