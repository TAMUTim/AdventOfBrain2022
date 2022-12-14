// not even gonna lie, this one was really cool

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
    ll int r = 1;
    ll int crt = 0;

    vector<char> x = {'#', '#', '#'};

    for(int i = 3; i < 40; ++i) {
        x.emplace_back('.');
    }

    vector<char> ans;

    while(getline(cin, l)) {
        stringstream ss(l);
        string token;
        vector<string> v;
        while(ss >> token) {
            v.emplace_back(token);
        }

        if(v.size() == 1) {
            // cout << x[crt] << endl;
            ans.emplace_back(x[crt % x.size()]);
            crt++;
        } else {
            // for(auto h : x) {
            //     cout << h;
            // }
            // cout << endl;
            //start n + 1 cycle
            // cout << x[crt] << endl;
            ans.emplace_back(x[crt % x.size()]);
            crt++;

            // cout << x[crt] << endl;
            ans.emplace_back(x[crt % x.size()]);
            crt++;
            // end n + 2 cycle
            // move the pointer
            if(r - 1 >= 0 && r - 1 < x.size()) {
                x[r - 1] = '.';
            }

            if(r >= 0 && r < x.size()) {
                x[r] = '.';
            }

            if(r + 1 >= 0 && r + 1 < x.size()) {
                x[r + 1] = '.';
            }
            
            r += stoi(v[1]);

            if(r - 1 >= 0 && r - 1 < x.size()) {
                x[r - 1] = '#';
            }

            if(r >= 0 && r < x.size()) {
                x[r] = '#';
            }

            if(r + 1 >= 0 && r + 1 < x.size()) {
                x[r + 1] = '#';
            }

            
            // for(auto h : x) {
            //     cout << h;
            // }
            // cout << endl << endl;
        }
    }

    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if(i % 40 == 39) {
            cout << endl;
        }
    }

    return 0;
}