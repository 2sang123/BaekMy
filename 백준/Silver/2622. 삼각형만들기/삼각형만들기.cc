#include <iostream>
#include <algorithm>
using namespace std;
int n;

int tris(int t)
{
    int tri = 0;
    for (int a = 0; a <= t-2 ; a++)
    {
        for (int b = a; b <= t-a -1 ; b++)
        {
            int c = t - a - b;
            if (c < b) continue;
            if (a + b > c) tri++;
        }
    }
    return tri;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << tris(n);
}
