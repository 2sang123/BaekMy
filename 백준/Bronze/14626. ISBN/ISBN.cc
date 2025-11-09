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
    bool h = false;
    int check = s.back() - '0';
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i] != '*')
        {
            if (i % 2 == 0)
            {
                sum += s[i] - '0';
            }
            else
            {
                sum += (s[i] - '0') * 3;
            }
        }
        else
        {
            if (i % 2 == 0)
            {
                h = true;
            }
            else
            {
                h = false;
            }
        }
    }
    int out = 0;
    for (int i = 0; i < 10; i++)
    {
        if (h)
        {
            if (check == 0)
            {
                if (check == (sum + i) % 10)
                {
                    out = i;
                    break;
                }
            }
            else
            {
                if (check == (10 - (sum + i) % 10))
                {
                    out = i;
                    break;
                }
            }
        }
        else
        {
            if (check == 0)
            {
                if (check == (sum + i*3) % 10)
                {
                    out = i;
                    break;
                }
            }
            else
            {
                if (check == (10 - (sum + i*3) % 10))
                {
                    out = i;
                    break;
                }
            }
        }
        
    }
    cout << out;
}
