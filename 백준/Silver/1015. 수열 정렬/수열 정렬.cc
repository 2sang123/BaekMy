#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n,-1);
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int check = 1;
    int rank = 0;
    while (true)
    {
        if (find(p.begin(), p.end(), -1) == p.end()) break;
        for (int i = 0; i < arr.size(); i++)
        {
            if (check == arr[i])
            {
                p[i] = rank;
                rank++;
            }
        }
        check++;
    }
    for (auto out : p)
    {
        cout << out << ' ';
    }
}
