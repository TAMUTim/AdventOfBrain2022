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

int solve(string l, string b) {
    // loop through the strings
    ll int li = 1;
    ll int bi = 1;
    ll int s = 0;

    // remove the first and lost
    // l = l.substr(1, l.size() - 2);
    // b = b.substr(1, b.size() - 2);
    
    vector<string> lv, bv;

    ll int lic = 0, bic = 0;
    while(li < l.size() && bi < b.size()) {
        // loop until hit a comma
        string t1 = "";
        string t2 = "";

        cout << t1 << " " << t2 << endl;

        bool ilb = false, irb = false; 

        // compare elements
        while(l[li] != ',') {
            if(l[li] == '[') {
                ilb = true;
                // instead get the entire bracket quandry
                while(l[li] != ']') {
                    t1.push_back(l[li]);                    
                    li++;
                    cout << t1 << endl;
                }
                t1.push_back(l[li]);
                li++;
                cout << t1 << endl;
                break;
            } else if(l[li] == ']') {
                break;
            } else {
                t1.push_back(l[li]);
            }
            li++;
        }
        cout << endl;

        while(b[bi] != ',') {
            if(b[bi] == '[') {
                irb = true;
                while(b[bi] != ']') {
                    t2.push_back(b[bi]);                    
                    bi++;
                }
                t1.push_back(b[bi]);
                cout << t2 << endl;
                bi++;
                break;
            } else if(b[bi] == ']') {
                break;
            } else  {
                t2.push_back(b[bi]);
            }
            bi++;
        }
        bi++; li++;


        cout << t1 << " " << t2 << endl;

        // now have string form of side by side elemnts: t1 and t2
        // if(ilb && irb) {
        //     s += solve(t1, t2);
        // } else if(!ilb && !irb) {
        //     // both not vectors
        // } else if(ilb && !irb) {
        //     // left hand vector and right hand not
        //     // convert right side to vector and process with solve
        // } else if(!ilb && irb) {
        //     // left hand not vector and right hand is
        //     // convert left side to vector and process with solve
        // }
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("13_sample.txt", "r", stdin);
    freopen("13_out.txt", "w", stdout);

    string l, b;
    ll int s = 0;
    while(cin >> l, cin >> b) {
        s += solve(l, b);
    }

    cout << s << endl;

    return 0;
}