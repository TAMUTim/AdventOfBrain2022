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

    int hx = 0, hy = 0, tx = 0, ty = 0;

    unordered_set<pair<int, int>, pair_hash> s;

    s.emplace(pair<int, int>({0, 0}));

    while(cin >> c >> p) {
        if(c == 'U') {
            for(int i = 0; i < p; ++i) {
                hy++;
                if(hy - ty >= 2) {
                    ty = hy - 1;
                    tx = hx;

                    if(s.find(pair<int, int>({ty, tx})) == s.end()) {
                        s.emplace(pair<int, int>({ty, tx}));
                    }
                }
            }
        } else if(c == 'D') {
            for(int i = 0; i < p; ++i) {
                hy--;
                if(ty - hy >= 2) {
                    ty = hy + 1;
                    tx = hx;

                    if(s.find(pair<int, int>({ty, tx})) == s.end()) {
                        s.emplace(pair<int, int>({ty, tx}));
                    }
                }
            }
        } else if(c == 'L') {
            for(int i = 0; i < p; ++i) {
                hx--;
                if(tx - hx >= 2) {
                    tx = hx + 1;
                    ty = hy;

                    if(s.find(pair<int, int>({ty, tx})) == s.end()) {
                        s.emplace(pair<int, int>({ty, tx}));
                    }
                }
            }
        } else if(c == 'R') {
            for(int i = 0; i < p; ++i) {
                hx++;
                if(hx - tx >= 2) {
                    tx = hx - 1;
                    ty = hy;

                    if(s.find(pair<int, int>({ty, tx})) == s.end()) {
                        s.emplace(pair<int, int>({ty, tx}));
                    }
                }
            }
        } else {
            return -1;
        }
    }

    cout << s.size() << endl;

    return 0;
}
