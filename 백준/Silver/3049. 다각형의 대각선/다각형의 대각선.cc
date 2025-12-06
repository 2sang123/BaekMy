#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int under = 24;
    int up = n * (n - 1) * (n - 2) * (n - 3);
    int out = up / under;
    cout << out;
}
