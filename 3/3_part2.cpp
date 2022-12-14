#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("3_in.txt", "r", stdin);
    freopen("3_out.txt", "w", stdout);

    vector<string> v(3);
    ll int c = 0;
    while(cin >> v[0] >> v[1] >> v[2]) {
        unordered_set<char> s;
        for(int i = 0; i < v[0].size(); ++i) {
            s.emplace(v[0][i]);
        }

        ll int t = 0;
        for(char g : s) {
            if(v[1].find(g) != string::npos && v[2].find(g) != string::npos) {
                if(g < 'a') {
                    c += g - 'A' + 27;
                } else {
                    c += g - 'a' + 1;
                }
                break;
            }
        }    
    }

    cout << c << endl;

    return 0;
}