#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(46);
    vector<int> B(46);
    A[0] = 0;
    A[1] = 0;
    B[0] = 0;
    B[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        A[i] += B[i - 1];
        B[i] += B[i - 1]+A[i-1];
    }
    cout << A[n] << ' ' << B[n];
}
