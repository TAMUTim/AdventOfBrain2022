#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("6_in.txt", "r", stdin);
    freopen("6_out.txt", "w", stdout);

    string str;
    cin >> str;

    for(int i = 0; i < str.size(); ++i) {
        unordered_set<char> us;

        bool go = true;
        for(int j = i; j < i + 4; ++j) {
            if(us.find(str[j]) != us.end()) {
                go = false;
                break;
            } else {
                us.emplace(str[j]);
            }
        }

        if(go) {
            cout << i + 4 << endl;
            break;
        }
    }

    return 0;
}