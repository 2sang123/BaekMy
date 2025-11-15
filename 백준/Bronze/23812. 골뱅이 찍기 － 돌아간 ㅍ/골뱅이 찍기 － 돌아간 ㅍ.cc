#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool check = false;
    int up = 0;
    for (int i = 0; i < n*5; i++)
    {
        if (i / n > up)
        {
            up = i / n;
            check = !check;
        }
        if (!check)
        {
            for (int j = 0; j < n; j++)
            {
                cout << '@';
            }
            for (int j = 0; j < n*3; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j < n; j++)
            {
                cout << '@';
            }
        }
        else
        {
            for (int j = 0; j < n*5; j++)
            {
                cout << '@';
            }
        }
        cout << '\n';
    }
}
