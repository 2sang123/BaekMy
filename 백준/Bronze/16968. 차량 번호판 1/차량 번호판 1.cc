#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            if (s[i] == 'c')
            {
                cnt += 26;
            }
            else
            {
                cnt += 10;
            }
        }
        else
        {
            if (s[i] == 'c'&&s[i-1]=='c')
            {
                cnt *= 25;
            }
            else if(s[i]=='d'&&s[i-1]=='d')
            {
                cnt *= 9;
            }
            else if (s[i] == 'c' && s[i - 1] == 'd')
            {
                cnt *= 26;
            }
            else
            {
                cnt *= 10;
            }
        }

    }
    cout << cnt;
}
