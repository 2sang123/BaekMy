#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    if (n <= 99)
    {
        cnt = n;
        cout << cnt;
    }
    else if(n>=100 || n<=999)
    {
        cnt = 99;
        for (int i = 100; i <= n; i++)
        {
            int a = i / 100;
            int c = i % 10;
            int b = (i - (a*100 + c)) / 10;
            if ((b - a) == (c - b)) cnt++;
        }
        cout << cnt;
    }
    else
    {
        cnt = 144;
        cout << cnt;
    }
}
