#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nscore, p;
    cin >> n >> nscore >> p;

    vector<int> scores(n);
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    if (n == 0) 
    {
        cout << 1;
        return 0;
    }

    sort(scores.begin(), scores.end(), greater<int>());

    if (n == p && nscore <= scores.back()) 
    {
        cout << -1;
        return 0;
    }

    int rank = 1;
    for (int i = 0; i < n; i++) 
    {
        if (scores[i] > nscore) rank++;
        else break;
    }

    cout << rank;
}
