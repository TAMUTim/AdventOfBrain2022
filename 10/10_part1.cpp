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
    freopen("10_in.txt", "r", stdin);
    freopen("10_out.txt", "w", stdout);

    string l;
    ll int cl = 0;
    ll int r = 1;
    ll int sum = 0;
    unordered_set<int> s = {20, 60, 100, 140, 180, 220};
    bool on = false;
    while(getline(cin, l)) {
        on = false;
        stringstream ss(l);
        string token;
        vector<string> v;
        while(ss >> token) {
            v.emplace_back(token);
        }

        if(v.size() == 1) {
            //noop command
            cl++;
        } else {
            // addx command
            // begin execution
            cl++;
            if(s.find(cl) != s.end()) {
                // cout << "first check\n";
                // cout << cl * r << endl;
                sum += cl * r;
            }

            cl++;
            if(s.find(cl) != s.end()) {
                // cout << "2nd check\n";
                // cout << cl * r << endl;
                sum += cl * r;
                on = true;
            }

            r += stoi(v[1]);
        }

        if(!on && s.find(cl) != s.end()) {
            // cout << "3rd check\n";
            // cout << cl * r << endl;
            sum += cl * r;
        }

        // cout << r << endl;
    }

    cout << sum << endl;

    return 0;
}