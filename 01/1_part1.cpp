#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("1_in.txt", "r", stdin);
    freopen("1_out.txt", "w", stdout);

    string line;
    ll int m = -1;
    ll int s = 0;
    while(getline(cin, line)) {
        if(line.empty()) {
            m = max(m, s);
            s = 0;
        } else {
            s += stoi(line);
        }
    }

    cout << m << endl;

    return 0;
}