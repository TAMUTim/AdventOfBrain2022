// this took too long, implementation heavy

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

struct Monkey {
    vector<int> s;
    vector<int> c;
    int d;
    int t;
    int f;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("11_sample.txt", "r", stdin);
    freopen("11_out.txt", "w", stdout);

    string mo;
    map<int, Monkey> hm;

    // process the input first
    while(getline(cin, mo)) {
        string token;
        vector<string> v = {mo};
        for(int i = 0; i < 6; ++i) {
            getline(cin, token);
            v.emplace_back(token);
        }

        Monkey m;
        stringstream ss(mo);
        vector<string> tem;
        
        // process id
        while(ss >> token) { tem.emplace_back(token); }
        tem[1].pop_back();
        m.id = stoi(tem[1]);

        // process starting items
        vector<int> s_te;
        v[1] = v[1].substr(v[1].find(':') + 1);
        v[1].erase(remove(v[1].begin(), v[1].end(), ' '), v[1].end());
        stringstream ts(v[1]);
        while(ts.good()) {
            string t;
            getline(ts, t, ',');
            s_te.emplace_back(stoi(t));
        }
        m.s = s_te;

        // process operation
        // * = -1 | + = -2 | old = -3 | all other numers = themselves
        vector<int> op;
        v[2] = v[2].substr(v[2].find('=') + 1);
        stringstream opss(v[2]);
        while(opss >> token) {
            if(token == "old") op.emplace_back(-3);
            else if(token == "+") op.emplace_back(-2);
            else if(token == "*") op.emplace_back(-1);
            else op.emplace_back(stoi(token));
        }

        m.c = op;

        // process division factor
        m.d = stoi(v[3].substr(v[3].find("by") + 3));

        // process true/false case
        m.t = stoi(v[4].substr(v[4].find("monkey") + 7));
        m.f = stoi(v[5].substr(v[5].find("monkey") + 7));

        hm[m.id] = m;
    }
    
    unordered_map<int, int> cm;
    // for(auto p : hm) {
    //     cm[p.first];
    // }
    // now actually run the logic
    // for 20 rounds
    for(int i = 0; i < 20; ++i) {
        for(auto p : hm) {
            for(int j = 0; j < hm[p.first].s.size(); ++j) {
                cm[p.first]++;
                // run operation and then divide by 3
                if(hm[p.first].c[1] == -1) {
                    hm[p.first].s[j] *= (hm[p.first].c[2] == -3) ? hm[p.first].s[j] : hm[p.first].c[2];
                } else if(hm[p.first].c[1] == -2) {
                    hm[p.first].s[j] += (hm[p.first].c[2] == -3) ? hm[p.first].s[j] : hm[p.first].c[2];
                }

                hm[p.first].s[j] /= 3;
                
                // test if the condiiton is true
                if(hm[p.first].s[j] % hm[p.first].d == 0) {
                    // thrown to the true monkey
                    hm[hm[p.first].t].s.emplace_back(hm[p.first].s[j]);
                } else {
                    // throw to false monkey
                    hm[hm[p.first].f].s.emplace_back(hm[p.first].s[j]);
                }
            }

            hm[p.first].s.clear();
        }

        // for(auto p : hm) {
        //     for(auto g : hm[p.first].s) {
        //         cout << g << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "finished round " << i << endl << endl;
    }

    priority_queue<int> pq;
    for(auto p : cm) {
        pq.emplace(p.second);
    }

    ll int su = pq.top();
    pq.pop();
    su *= pq.top();

    cout << su << endl;

    return 0;
}