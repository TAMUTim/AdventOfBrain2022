#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("2_in.txt", "r", stdin);
    freopen("2_out.txt", "w", stdout);


    // rock = x
    // paper = y
    // scissor = z
    unordered_map<string, string> m;
    m["A"] = "X";
    m["B"] = "Y";
    m["C"] = "Z";
    m["X"] = "Y";
    m["Y"] = "Z";
    m["Z"] = "X";

    unordered_map<string, string> lm;
    lm["X"] = "Z";
    lm["Y"] = "X";
    lm["Z"] = "Y";


    ll int c = 0;
    string a, b;
    while(cin >> a >> b) {
        a = m[a];
        
        if(b == "Y") {
            c += 3;
            c += a[0] - 'W';
        } else if(b == "Z") {
            c += 6;
            c += m[a][0] - 'W';
        } else {
            c += lm[a][0] - 'W';
        }
    }

    cout << c << endl;

    return 0;
}