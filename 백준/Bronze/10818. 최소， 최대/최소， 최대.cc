#include <iostream>
using namespace std;
int n;
int a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int big = -1000000; 
    int small = 1000000;
    while (n--)
    {
        cin >> a;
        if (a > big)
        {
            big = a;
        }
        if (a < small)
        {
            small = a;
        }
    }
    cout << small << " " << big;
}
