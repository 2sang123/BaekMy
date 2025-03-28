#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
int m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    while (n--)
    {
        cin >> m;
        string wear;
        string parts;
        int multi = 1;
        map<string, int> cloth;
        vector<string> keys;
        for (int i = 0; i < m; i++)
        {
            cin >> wear >> parts;
            if (cloth.find(parts) == cloth.end())
            {
                cloth.insert({ parts, 0 });
                keys.push_back(parts);
            }
            cloth[parts]++;
        }

        for (auto a : keys)
        {
            multi *= (cloth[a]+1);
        }
        cout << multi-1 << '\n';
    }
}
