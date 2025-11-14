#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    vector<bool> cup(3,false);
    cup[0] = true;
    while (cin >> c)
    {
        if (c == 'A')
        {
            bool temp = cup[0];
            cup[0] = cup[1];
            cup[1] = temp;
        }
        else if (c == 'B')
        {
            bool temp = cup[1];
            cup[1] = cup[2];
            cup[2] = temp;
        }
        else if (c == 'C')
        {
            bool temp = cup[0];
            cup[0] = cup[2];
            cup[2] = temp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (cup[i]) cout << i + 1;
    }
}
