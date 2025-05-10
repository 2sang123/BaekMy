#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int& x : arr) cin >> x;

	vector<int> lis;
	vector<int> pos(n); // 각 원소가 LIS에서 몇 번째 위치에 들어갔는지 저장
	vector<int> idx; // LIS 값이 들어간 arr의 인덱스 저장

	for (int i = 0; i < n; ++i) {
		int x = arr[i];
		auto it = lower_bound(lis.begin(), lis.end(), x);
		int lis_pos = it - lis.begin();  // 들어갈 위치

		if (it == lis.end()) {
			lis.push_back(x);
			idx.push_back(i);
		}
		else {
			*it = x;
			idx[lis_pos] = i;
		}

		pos[i] = lis_pos;
	}

	int len = lis.size();
	vector<int> result(len);
	int cur_idx = idx[len - 1];  // LIS 마지막 값의 인덱스

	for (int i = n - 1; i >= 0; --i) {
		if (pos[i] == len - 1 && arr[i] <= arr[cur_idx]) {
			result[len - 1] = arr[i];
			cur_idx = i;
			len--;
		}
	}

	cout << result.size() << '\n';
	for (int x : result) cout << x << ' ';
}
