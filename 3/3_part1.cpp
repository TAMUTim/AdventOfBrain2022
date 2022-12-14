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

    string inv;
    ll int c = 0;
    while(cin >> inv) {
        unordered_set<char> s;
        for(int i = 0; i < inv.size() / 2; ++i) {
            s.emplace(inv[i]);
        }

        for(int i = inv.size() / 2; i < inv.size(); ++i) {
            if(s.find(inv[i]) != s.end()) {
                if(inv[i] < 'a') {
                    c += inv[i] - 'A' + 27;
                } else {
                    c += inv[i] - 'a' + 1;
                }
                break;
            }
        }        
    }

    cout << c << endl;

    return 0;
}