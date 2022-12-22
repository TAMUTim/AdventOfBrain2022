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
    // process as single list
    // if bracket then recur call and return, easy since we now just return bool
    ll int lind = 1, bind = 1;

    while(lind <= l.size() - 2 || bind <= b.size() - 2) {
        string ls = "", bs = "";

        bool rhsv = false, lhsv = false;

        // get element normally
        if(lind <= l.size() - 1 && l[lind] != '[') {
            while(l[lind] != ',' && lind < l.size() - 1) {
                ls.push_back(l[lind]);
                lind++;
            }
            if(l[lind] == ',') { lind++; }
        } else if(lind <= l.size() - 1 && l[lind] == '[') {
            // what to do if
            ll int mtx = 1;
            lhsv = true;
            while(mtx != 0) {
                ls.push_back(l[lind]);
                lind++;
                if(l[lind] == '[') { mtx++; } 
                else if(l[lind] == ']') { mtx--; }
            }
            ls.push_back(l[lind]);
            lind++;

            if(l[lind] == ',') { lind++; }
        }


        // get element normally
        if(bind <= b.size() - 1 && b[bind] != '[') {
            while(b[bind] != ',' && bind < b.size() - 1) {
                bs.push_back(b[bind]);
                bind++;
            }
            if(b[bind] == ',') { bind++; }
        } else if(bind <= b.size() - 1 && b[bind] == '[') {
            // what to do if
            ll int mtx = 1;
            rhsv = true;
            while(mtx != 0) {
                bs.push_back(b[bind]);
                bind++;
                if(b[bind] == '[') { mtx++; } 
                else if(b[bind] == ']') { mtx--; }
            }
            bs.push_back(b[bind]);
            bind++;

            if(b[bind] == ',') { bind++; }
        }

        // cout << ls << " vs. " << bs << endl;
        if(!bs.empty() && ls.empty()) { return 1; } 
        if(bs.empty() && !ls.empty()) { return -1; }

        if(!rhsv && !lhsv) {
            if(stoi(ls) > stoi(bs)) {
                // cout << ls << " vs. " << bs << " is out of order\n";
                return -1;
            } else if(stoi(ls) < stoi(bs)) {
                return 1;
            }
        } else {
            // one of the comparing objects is a vector
            // turn into vector for the one without
            if(!rhsv) {
                // want to vectorize whatevers in here
                string tem = "[";
                tem += bs;
                tem += "]";
                bs = tem;
            }
            
            if(!lhsv) {
                string tem = "[";
                tem += ls;
                tem += "]";
                ls = tem;
            }

            if(solve(ls, bs) < 0) return -1;
            if(solve(ls, bs) > 0) return 1;
        }
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("13_in.txt", "r", stdin);
    freopen("13_out.txt", "w", stdout);

    string l, b;
    ll int s = 0;
    ll int in = 1;
    vector<string> gv;
    while(cin >> l, cin >> b) {       
        gv.emplace_back(l);
        gv.emplace_back(b);
    }

    gv.emplace_back("[[2]]");
    gv.emplace_back("[[6]]");

    sort(gv.begin(), gv.end(), [](const string& lhs, const string& rhs) {
        return solve(lhs, rhs) > 0 ? true : false;
    });

    ll int dk = 1;
    for(int i = 0; i < gv.size(); ++i) {
        cout << i << ": " << gv[i] << endl;
        if(gv[i] == "[[2]]" || gv[i] == "[[6]]")  {
            dk *= i + 1;
        }
    }

    cout << dk << endl;
    
    return 0;
}