#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

bool checkUp(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    // check up
    for(int a = i - 1; a >= 0; --a) {
        if(v[a][j] >= val) return false;
    }
    return true;
}

bool checkDown(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    // check down
    for(int a = i + 1; a < v.size(); ++a) {
        if(v[a][j] >= val) return false;
    }
    return true;
}

bool checkRight(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    // check right
    for(int a = j + 1; a < v.size(); ++a) {
        if(v[i][a] >= val) return false;
    }
    return true;
}

bool checkLeft(ll int i, ll int j, ll int val, vector<vector<int>>& v) {
    // check left
    for(int a = j - 1; a >= 0; --a) {
        if(v[i][a] >= val) return false;
    }
    return true;
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
            // check cardinal directions
            if(checkRight(i, j, v[i][j], v) || checkLeft(i, j, v[i][j], v) || 
                checkUp(i, j, v[i][j], v) || checkDown(i, j, v[i][j], v)) {
                c++;
            }
        }
    }

    cout << c + 2 * v.size() + 2 * v[0].size() - 4 << endl;

    return 0;
}