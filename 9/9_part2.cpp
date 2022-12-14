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
    freopen("9_in.txt", "r", stdin);
    freopen("9_out.txt", "w", stdout);

    char c;
    int p;

    vector<pair<int, int>> v(10, {0, 0});

    unordered_set<pair<int, int>, pair_hash> s;
    s.emplace(pair<int, int>({0, 0}));

    while(cin >> c >> p) {
        for(int i = 0; i < p; ++i) {
            if(c == 'U') {
                v[0].second++;
            } else if(c == 'D') {
                v[0].second--;
            } else if(c == 'R') {
                v[0].first++;
            } else if(c == 'L') {
                v[0].first--;
            } else {
                return -1;
            }

            for(int j = 1; j < 10; ++j) {
                if(v[j - 1].second - v[j].second >= 2 && v[j - 1].first - v[j].first >= 2) {
                    v[j].first = v[j - 1].first - 1;
                    v[j].second = v[j - 1].second - 1;
                } else if(v[j - 1].second - v[j].second >= 2 && v[j].first - v[j - 1].first >= 2) {
                    v[j].first = v[j - 1].first + 1;
                    v[j].second = v[j - 1].second - 1;
                } else if(v[j].second - v[j - 1].second >= 2 && v[j - 1].first - v[j].first >= 2) {
                    v[j].first = v[j - 1].first - 1;
                    v[j].second = v[j - 1].second + 1;
                } else if(v[j].second - v[j - 1].second >= 2 && v[j].first - v[j - 1].first >= 2) {
                    v[j].first = v[j - 1].first + 1;
                    v[j].second = v[j - 1].second + 1;
                }
                
                
                else if(v[j - 1].second - v[j].second >= 2) {
                    v[j].second = v[j - 1].second - 1;
                    v[j].first = v[j - 1].first;
                } else if(v[j].second - v[j - 1].second >= 2) {
                    v[j].second = v[j - 1].second + 1;
                    v[j].first = v[j - 1].first;
                } else if(v[j].first - v[j - 1].first >= 2) {
                    v[j].first = v[j - 1].first + 1;
                    v[j].second = v[j - 1].second;
                } else if(v[j - 1].first - v[j].first >= 2) {
                    v[j].first = v[j - 1].first - 1;
                    v[j].second = v[j - 1].second;
                }

                if(j == 9 && s.find(pair<int, int>({v[j].first, v[j].second})) == s.end()) {
                    s.emplace(pair<int, int>({v[j].first, v[j].second}));
                }
            }
            // for(auto g : v) {
            //     cout << g.first << " " << g.second << endl;
            // } cout << endl;
        }

        // cout << "-----------------------\n";
    }

    cout << s.size() << endl;

    return 0;
}
