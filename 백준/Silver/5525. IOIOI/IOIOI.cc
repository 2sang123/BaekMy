#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >>m;
    string s;

    string check;
    for (int i = 0; i < (n*2)+1; i++)
    {
        if (i % 2 == 0)
        {
            check += 'I';
        }
        else
        {
            check += 'O';
        }
    }
    cin >> s;
    int cnt = 0;
    int point = 0;
    do
    {
        string str = s.substr(point, check.size());
        if (str.compare(check) == 0)
        {
            cnt++;
        }
        point++;
    } while (point < m - check.size()+1);

    cout << cnt;
}

