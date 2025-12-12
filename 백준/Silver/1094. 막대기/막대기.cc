#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int t = n;
    int cnt = 0;
    while (t > 0)
    {
        if (t % 2 == 1)
        {
            cnt++;
            t /= 2;
        }
        else t /=2;
    }
    cout << cnt;
}
