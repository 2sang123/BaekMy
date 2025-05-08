#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
void back(vector<int>& vec, int start)
{
    if (vec.size() == m)
    {
        for (int num : vec)
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        vec.push_back(i);
        back(vec, i);
        vec.pop_back();
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	vector<int> cur;
	back(cur, 1);
}
