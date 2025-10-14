#include <iostream>
using namespace std;
long long n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    long long out = n * n * k;
    cout << out;
}
