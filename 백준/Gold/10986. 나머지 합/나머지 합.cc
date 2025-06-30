#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> count(m); // 나머지 저장
    int p = 0;
    long long cnt = 0;
    count[0] = 1; // 누적합이 0이면 그 자체로 m으로 나누어짐
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p = (p + arr[i]) % m;
        if (p < 0) p += m; // 음수 나머지 보정
        cnt += count[p]; // 해당 나머지가 나온 횟수만큼 추가
        count[p]++;
    }

    cout << cnt;
}