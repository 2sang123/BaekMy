#include <iostream>
using namespace std;

long long a, b;
long long out = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i >= 4 && i % 2 == 0)
        {
            out += i;
        }
    }
    cout << out;
}
