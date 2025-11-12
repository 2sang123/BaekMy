#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.insert(vec.begin() + num, i+1);
    }
    
    for (int i = n-1; i >=0 ; i--)
    {
        cout << vec[i] << ' ';
    }
}
