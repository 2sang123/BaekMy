#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'F' && i % 2 == 0 && j % 2 == 0)
            {
                cnt++;
            }
            else if (s[j] == 'F' && i % 2 == 1 && j % 2 == 1)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}