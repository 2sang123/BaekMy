#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;

int Xcount(string str, int start)
{
    int cnt = 0;
    for (int i = start; i < str.size(); i++)
    {
        if (str[i] == 'X')
        {
            cnt++;
        }
        else return cnt;
    }
    return cnt;
}

int pCount(string str, int start)
{
    int cnt = 0;
    for (int i = start; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            cnt++;
        }
        else return cnt;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int end = s.size();

    int sum = 0;
    int start = 0;
    string out;
    if (s[0] == '.')
    {
        int p = pCount(s, start);
        for (int i = 0; i < p; i++)
        {
            out += '.';
        }
        sum += p;
        start += p;
    }
    while (sum < end)
    {
        
        int x = 0;
        int p = 0;
        x = Xcount(s, start);
        if (x % 2 != 0 || x==1 || x==0)
        {
            cout << -1;
            return 0;
        }
        else if (x == 2)
        {
            out += "BB";
        }
        else if(x%4==0)
        {
            for (int i = 0; i < x/4; i++)
            {
                out += "AAAA";
            }
        }
        else if (x % 4 == 2)
        {
            for (int i = 0; i < x / 4; i++)
            {
                out += "AAAA";
            }
            out += "BB";
        }
        
        sum += x;
        start += x;
        p = pCount(s, start);
        for (int i = 0; i < p; i++)
        {
            out += '.';
        }
        sum += p;
        start += p;
        if (sum >= end) break;
    }
    cout << out;
}

