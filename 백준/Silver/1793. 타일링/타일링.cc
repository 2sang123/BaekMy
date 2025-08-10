#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct BigInt
{
	string val;
	BigInt(long long num = 0)
	{
		val = to_string(num);
	}
	BigInt(const string& s)
	{
		val = s;
	}
	BigInt operator+(const BigInt& other) const
	{
		string a = val;
		string b = other.val;
		while (a.size() < b.size()) a = '0' + a;
		while (b.size() < a.size()) b = '0' + b;
		string res = "";
		int carry = 0;
		for (int i = a.size()-1; i >=0 ; i--)
		{
			int sum = (a[i] - '0') + (b[i] - '0') + carry;
			carry = sum / 10;
			res = char(sum % 10 + '0') + res;
		}
		if (carry) res = '1' + res;
		return BigInt(res);
	}
	friend ostream& operator<<(ostream& os, const BigInt& num)
	{
		os << num.val;
		return os;
	}
};
long long n;
vector<BigInt> dp(251);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dp[0] = 1;
	dp[1] = 1;
	while (cin >> n)
	{
		for (long long i = 2; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]);
		}
		cout << dp[n] << '\n';
	}
	
}
