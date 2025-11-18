#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int sum = 0;
    char back = ' ';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != back)
        {
            sum += 10;
            back = s[i];
        }
        else
        {
            back = s[i];
            sum += 5;
        }
    }
    cout << sum;
}
