#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("4_in.txt", "r", stdin);
    freopen("4_out.txt", "w", stdout);

    string line;
    ll int c = 0;
    while(cin >> line) {
        // process line, first split by comma, then split by hyphen into int pairs
        size_t pos = 0;
        string f, s;

        f = line.substr(0, line.find(","));
        s = line.substr(line.find(",") + 1, line.size());

        pair<int, int> fp = {stoi(f.substr(0, f.find("-"))), stoi(f.substr(f.find("-") + 1, f.size()))};
        pair<int, int> sp = {stoi(s.substr(0, s.find("-"))), stoi(s.substr(s.find("-") + 1, s.size()))};

        // cout << fp.first << " " << fp.second << " | " << sp.first << " " << sp.second << endl;

        if((fp.first >= sp.first && fp.second <= sp.second) || (sp.first >= fp.first && sp.second <= fp.second)) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}