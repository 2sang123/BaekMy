#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool error = false;
void controll(deque<int> &d, string &str)
{
    bool reversed = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'D')
        {
            if (d.empty())
            {
                error = true;
                return;
            }

            if (reversed)
            {
                d.pop_back();
            }
            else
            {
                d.pop_front();
            }
        }
        else if (str[i] == 'R')
        {
            reversed ^= 1;
        }
    }
    if (reversed) reverse(d.begin(), d.end());
    return;
}


int main() {
    int T;
    cin >> T;

    while (T--) {
        error = false;
        int n;
        char c1, c2;
        int rcnt, dcnt;
        string s;

        cin >> s;
        cin >> n;
        cin >> c1;
        deque<int> arr;
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                int in;
                char non;
                if (i < n - 1)
                {
                    cin >> in >> non;
                }
                else
                {
                    cin >> in;
                }
                arr.push_back(in);
            }
        }
        cin >> c2;
        
        controll(arr, s);
        if (error)
        {
            cout << "error" << '\n';
        }
        else
        {
            cout << c1;
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i];
                if (i < arr.size() - 1) cout << ',';
            }
            cout << c2 << '\n';
        }
        
    }
}
