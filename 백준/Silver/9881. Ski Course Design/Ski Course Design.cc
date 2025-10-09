#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int answer = 1e9;

    for (int i = arr.front(); i <= arr.back()-17; i++) {
        int e = i + 17;
        int sum = 0;

        for (int x : arr) {
            if (x < i) sum += (i - x) * (i - x);
            else if (x > e) sum += (x - e) * (x - e);
        }
        answer = min(answer, sum);
    }

    cout << answer;
}
