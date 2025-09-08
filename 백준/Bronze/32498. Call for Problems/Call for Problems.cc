#include <iostream>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if (b % 2 != 0)
        {
            c++;
        }
    }
    cout << c;
}
