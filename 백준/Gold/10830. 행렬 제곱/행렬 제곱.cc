#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
long long k;
int test = 1000;
vector<vector<long long>> multi(const vector<vector<long long>>& m, const vector<vector<long long>>& m2)
{
    vector<vector<long long>> save(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int h = 0; h < n; h++)
            {
                save[i][j] = (save[i][j]+ m[i][h] * m2[h][j])%1000;
            }
        }
    }
    return save;
}

vector<vector<long long>> pMat(vector<vector<long long>>& mat, long long ex)
{
    vector<vector<long long>> res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }
    vector<vector<long long>> base = mat;
    while (ex > 0)
    {
        if (ex % 2 == 1) res = multi(res, base);
        base = multi(base, base);
        ex /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<vector<long long>> mat(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<long long>> mat2 = pMat(mat, k);

    for (auto& v1 : mat2)
    {
        for (auto& v2 : v1)
        {
            cout << v2 << ' ';
        }
        cout << '\n';
    }
}
