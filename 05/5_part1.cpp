#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("5_in.txt", "r", stdin);
    freopen("5_out.txt", "w", stdout);

    vector<vector<char>> v = {
        {'F', 'C', 'P', 'G', 'Q', 'R'},
        {'W', 'T', 'C', 'P'},
        {'B', 'H', 'P', 'M', 'C'},
        {'L', 'T', 'Q', 'S', 'M', 'P', 'R'},
        {'P', 'H', 'J', 'Z', 'V', 'G', 'N'},
        {'D', 'P', 'J'},
        {'L', 'G', 'P', 'Z', 'F', 'J', 'T', 'R'},
        {'N', 'L', 'H', 'C', 'F', 'P', 'T', 'J'},
        {'G', 'V', 'Z', 'Q', 'H', 'T', 'C', 'W'}
    };

    /*
                                [R] [J] [W]
                    [R] [N]     [T] [T] [C]
        [R]         [P] [G]     [J] [P] [T]
        [Q]     [C] [M] [V]     [F] [F] [H]
        [G] [P] [M] [S] [Z]     [Z] [C] [Q]
        [P] [C] [P] [Q] [J] [J] [P] [H] [Z]
        [C] [T] [H] [T] [H] [P] [G] [L] [V]
        [F] [W] [B] [L] [P] [D] [L] [N] [G]
        1   2   3   4   5   6   7   8   9 
    */

    string t;
    ll int n, p1, p2;
    while(cin >> t >> n >> t >> p1 >> t >> p2) {
        for(int i = 0; i < n; ++i) {
            if(v[p1 - 1].size() == 0) break;

            char ta = v[p1 - 1].back();
            v[p1 - 1].pop_back();
            v[p2 - 1].emplace_back(ta);
        }
    }

    for(auto g : v) {
        cout << g.back();
    }

    cout << endl;

    return 0;
}