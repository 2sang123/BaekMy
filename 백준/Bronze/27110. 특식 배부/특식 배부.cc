#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    int cnt = 0;
    if (a >= n) cnt += n;
    else cnt += a;
    if (b >= n) cnt += n;
    else cnt += b;
    if (c >= n) cnt += n;
    else cnt += c;
    
    cout << cnt;
}
