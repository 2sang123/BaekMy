#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int n;
int k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n>>k;
    vector<int> coin(n);
    vector<int> vec(k+1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    vec[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <= k; j++) {
            vec[j] += vec[j - coin[i]];
        }
    }
    cout << vec[k];
}
