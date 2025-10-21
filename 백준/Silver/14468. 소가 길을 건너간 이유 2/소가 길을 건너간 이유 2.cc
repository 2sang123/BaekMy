#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<pair<int,int>> cow(26,{-1,-1});
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'A';
        if (cow[c].first == -1) cow[c].first = i;
        else cow[c].second = i;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cow[i].first == -1) continue;
        for (int j = i+1; j < 26; j++)
        {
            if (cow[j].first == -1) continue;
            if((cow[i].first < cow[j].first && cow[j].first < cow[i].second && cow[i].second < cow[j].second) ||
                (cow[j].first < cow[i].first && cow[i].first < cow[j].second && cow[j].second < cow[i].second))
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}
