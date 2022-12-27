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
    freopen("15_sample.txt", "r", stdin);
    freopen("15_out.txt", "w", stdout);

    string l;

    unordered_map<int, bool> um;
    int TARGET_LINE = 10;
    ll int s = 0;
    while(getline(cin, l)) {
        // process the two points
        int x1 = stoi(l.substr(l.find("at x=") + 5, l.find(",") - l.find("at x=") - 5));
        int y1 = stoi(l.substr(l.find(", y=") + 4, l.find(":") - l.find(", y=") - 4));

        l = l.substr(l.find(":") + 2, l.size() - l.find(":"));
        int x2 = stoi(l.substr(l.find("at x=") + 5, l.find(",") - l.find("at x=") - 5));
        int y2 = stoi(l.substr(l.find(", y=") + 4, l.size() - l.find(", y=") - 4));

        // figure out manhattan distance
        int md = abs(x1 - x2) + abs(y1 - y2);
        ll int dd = -1;
        if(y1 == TARGET_LINE) {
            // go left then right
            dd = md;
        } else if(TARGET_LINE <= y1 + md && TARGET_LINE > y1) {
            // get the dist from top-most y to target_line
            dd = y1 + md - TARGET_LINE;
            cout << "in upper half, x1=" << x1 << ", y1=" << y1 << " dd = " << dd << endl;
        } else if(TARGET_LINE >= y1 - md && TARGET_LINE < y1) {
            dd = TARGET_LINE - (y1 - md);
            cout << "in lower half, x1=" << x1 << ", y1=" << y1 << " dd = " << dd << endl;
        }

        if(dd >= 0) {
            cout << "edit for dd " << dd << endl;
            um[x1] = true;
            for(int i = x1; i < x1 + md; ++i) {
                um[i] = true;
            }

            for(int i = x1; i > x1 - md; --i) {
                um[i] = true;
            }
        }
    }

    vector<pair<int, bool>> vp;
    for(auto p : um) {
        vp.emplace_back(p);
        if(p.second == true) {
            // cout << p.first << endl;
            s++;
        }
    }

    sort(vp.begin(), vp.end(), [] (pair<int, bool> a, pair<int, bool> b) {
        return a.first < b.first;
    });

    for(auto p : vp) {
        cout << p.first << " " << p.second << endl;
    }

    cout << s << endl;

    return 0;
}