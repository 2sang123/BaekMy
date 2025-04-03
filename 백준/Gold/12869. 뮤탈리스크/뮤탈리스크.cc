#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int n;
int scv[3] = {};
int attackDamage[3] = { 1,3,9 };
vector<int> attack;
vector<vector<int>> attackV;


int ret = 987654321;


bool visited[64][64][64][64];


void go(int scv1, int scv2, int scv3, int cnt)
{

	

	if (scv1 <= 0 && scv2 <= 0 && scv3 <= 0)
	{
		ret = min(ret, cnt);
		return;
	}

	if (visited[scv1][scv2][scv3][cnt]) return;

	visited[scv1][scv2][scv3][cnt] = 1;

	for (vector<int> i : attackV)
	{
		visited[scv1][scv2][scv3][cnt] = true;
		go(max(0,scv1 - i[0]), max(0,scv2 - i[1]), max(0,scv3 - i[2]), cnt + 1);
	}
}



int main()
{
	
	cin >> n;


	do
	{
		for (int i : attackDamage)
		{
			attack.push_back(i);
		}
		attackV.push_back(attack);
		attack.clear();
	}
	while (next_permutation(attackDamage, attackDamage + 3));

	
	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}

	go(scv[0], scv[1], scv[2], 0);

	cout << ret;
	

}

