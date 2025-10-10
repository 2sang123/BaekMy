#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, w;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> arr(32, vector<int>(32, 0));

    arr[1][1] = 1;

    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    cin >> r >> c >> w;
    long long sum = 0;
    int p = 0;
    for (int i = r; i < r+w; i++)
    {
        p++;
        for (int j = c; j < c+p; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << sum;
}
