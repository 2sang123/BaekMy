#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int res = -1;

int full22(const vector<vector<int>>& mat, int rs, int cs)
{
    priority_queue<int> pq;
    pq.push(mat[rs][cs]);
    pq.push(mat[rs+1][cs]);
    pq.push(mat[rs][cs+1]);
    pq.push(mat[rs+1][cs+1]);
    pq.pop();
    return pq.top();
}

void divideMat(vector<vector<int>> mat, int d)
{
    if (mat.size() == 2)
    {
        res = full22(mat, 0, 0);
        return;
    }
    int nd = d / 2;
    vector<vector<int>> newMat(nd, vector<int>(nd,0));
    
    for (int i = 0; i < d; i+=2)
    {
        for (int j = 0; j < d; j+=2)
        {
            newMat[i/2][j/2] = full22(mat, i, j);
        }
    }
    return divideMat(newMat, nd);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    divideMat(arr, n);
    cout << res;
}
