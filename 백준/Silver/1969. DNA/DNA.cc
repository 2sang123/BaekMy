#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> nums(n);
    int dist = 0;
    string out;
    for (int i = 0; i < m; i++)
    {
        int word[4] = { 0, };
        char w[4] = { 'A','C','G','T' };
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == w[0]) word[0]++;
            else if (arr[j][i] == w[1]) word[1]++;
            else if (arr[j][i] == w[2]) word[2]++;
            else if (arr[j][i] == w[3]) word[3]++;
        }
        int big = 0;
        char target = 'A';
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            sum += word[i];
            if (word[i] > big)
            {
                big = word[i];
                target = w[i];
            }
            else if (word[i] == big && target > w[i])
            {
                target = w[i];
            }
        }
        dist += sum - big;
        out += target;
    }
    cout << out << '\n' << dist;
}