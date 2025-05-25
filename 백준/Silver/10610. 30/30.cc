#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
    long long sum = 0;
    bool has_zero = false;

    for (char c : s) {
        sum += c - '0'; // 모든 자릿수의 합이 3의 배수가 아니면 3의 배수 즉, 30의 배수가 아님
        if (c == '0') has_zero = true; // 끝자리가 0이 아니면 30의 배수가 아님
    }

    if (!has_zero || sum % 3 != 0) { 
        cout << -1;
    }
    else {
        sort(s.rbegin(), s.rend()); // 내림차순 정렬 큰 수 부터 나옴
        cout << s;
    }
}
