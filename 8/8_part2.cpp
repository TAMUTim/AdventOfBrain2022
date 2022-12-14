#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int checkUp(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    for(int a = i - 1; a >= 0; --a) {
        if(v[a][j] >= val) return i - a;
    }
    return i;
}

int checkDown(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    for(int a = i + 1; a < v.size(); ++a) {
        if(v[a][j] >= val) return a - i;
    }
    return v.size() - 1 - i;
}

int checkRight(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    for(int a = j + 1; a < v.size(); ++a) {
        if(v[i][a] >= val) return a - j;
    }
    return v[i].size() - 1 - j;
}

int checkLeft(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    for(int a = j - 1; a >= 0; --a) {
        if(v[i][a] >= val) return j - a;
    }
    return j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("8_in.txt", "r", stdin);
    freopen("8_out.txt", "w", stdout);

    vector<vector<int>> v;
    string str;
    while(cin >> str) {
        vector<int> iv;
        for(auto a : str) {
            iv.emplace_back(a - '0');
        }
        v.emplace_back(iv);
    }

    ll int c = 0;
    for(int i = 1; i < v.size() - 1; ++i) {
        for(int j = 1; j < v[i].size() - 1; ++j) {
            int cr = checkRight(i, j, v[i][j], v);
            int cl = checkLeft(i, j, v[i][j], v);
            int cu = checkUp(i, j, v[i][j], v);
            int cd = checkDown(i, j, v[i][j], v);

            ll int cum = cr * cl * cu * cd;
            c = max(c, cum);
        }
    }

    cout << c << endl;

    return 0;
}