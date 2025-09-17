#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<bool> check(1001, false);
int arr[4] = { 1, 5, 10, 50 };
int cnt = 0;
void dfs(int idx, int depth, int sum) {
    if (depth == n) {
        if (!check[sum]) {
            check[sum] = true;
            cnt++;
        }
        return;
    }
    for (int i = idx; i < 4; i++) {  
        dfs(i, depth + 1, sum + arr[i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dfs(0, 0, 0);
    cout << cnt;
}
