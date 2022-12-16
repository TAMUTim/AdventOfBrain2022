#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

struct pair_hash {
    inline size_t operator()(const pair<int, int> & v) const {
        return v.first * 31 + v.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("12_sample.txt", "r", stdin);
    freopen("12_out.txt", "w", stdout);

    vector<vector<char>> v;

    string li;
    while(cin >> li) {
        vector<char> vi;
        for(auto g : li) {
            vi.emplace_back(g);
        }

        v.emplace_back(vi);
    }

    pair<int, int> st;
    pair<int, int> en;
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            if(v[i][j] == 'S') {
                st = make_pair(i, j);
            }

            if(v[i][j] == 'E') {
                en = make_pair(i, j);
            }
        }
    }

    // now do like bs or djikstras or smth
    queue<pair<pair<int, int>, int>> q;
    q.emplace(make_pair(st, 0));

    ll int mi = INT32_MAX;
    while(!q.empty()) {
        pair<pair<int, int>, int> pos = q.front();
        q.pop();
        cout << pos.first.first << " " << pos.first.second << ": " << v[pos.first.first][pos.first.second] << endl;

        if(v[pos.first.first][pos.first.second] == 'E') {
            mi = min(mi, (ll int) pos.second);
            continue;
        }
        char cur = v[pos.first.first][pos.first.second] == 'S' ? 'a' : v[pos.first.first][pos.first.second];
        
        // put in cardinal nodes
        // up
        if(pos.first.first + 1 >= 0 
            && abs(cur - (v[pos.first.first - 1][pos.first.second] == 'E' ? 'z' : v[pos.first.first - 1][pos.first.second])) <= 1) {
            q.emplace(make_pair(make_pair(pos.first.first - 1, pos.first.second), pos.second + 1));
        } 

        // down
        if(pos.first.first + 1 < v.size() 
            && abs(cur - (v[pos.first.first + 1][pos.first.second] == 'E' ? 'z' : v[pos.first.first + 1][pos.first.second])) <= 1) {
            q.emplace(make_pair(make_pair(pos.first.first + 1, pos.first.second), pos.second + 1));
        } 

        // left
        if(pos.first.second - 1 >= 0 
            && abs(cur - (v[pos.first.first][pos.first.second - 1] == 'E' ? 'z' : v[pos.first.first + 1][pos.first.second])) <= 1) {
            q.emplace(make_pair(make_pair(pos.first.first, pos.first.second - 1), pos.second + 1));
        } 

        // right
        if(pos.first.second < v[0].size() 
            && abs(cur - (v[pos.first.first][pos.first.second + 1] == 'E' ? 'z' : v[pos.first.first][pos.first.second + 1])) <= 1) {
            q.emplace(make_pair(make_pair(pos.first.first, pos.first.second + 1), pos.second + 1));
        } 
    }

    return 0;
}