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

void recur(vector<vector<int>>& vvb, ll int stx, ll int sty, ll int target) {    
    // cout << stx << " " << sty << endl;    
    if(vvb[stx + 1][sty] == 0) {
        recur(vvb, stx + 1, sty, target);
    } else if(vvb[stx + 1][sty - 1] == 0) {
        recur(vvb, stx + 1, sty - 1, target);
    } else if(vvb[stx + 1][sty + 1] == 0) {
        recur(vvb, stx + 1, sty + 1, target);
    } else {
        // no possible play
        vvb[stx][sty] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("14_in.txt", "r", stdin);
    freopen("14_out.txt", "w", stdout);

    vector<vector<int>> vvb(1000, vector<int>(1000, 0));
    
    // let 0 = air, 1 = cave rock, 2 = sand
    // first draw out the cave
    // then simulate until drop into void
    // might need some sort of detection for the foundation?
    // ^ detect lowest horizontal section of cave ?
    // might be slanted, either way shouldn't be too bad

    string l;
    int lx = INT_MAX, ux = INT_MIN, ly = INT_MAX, uy = INT_MIN;
    while(getline(cin, l)) {
        // process line
        string tok;
        vector<pair<int, int>> vpii;
        stringstream ls(l);
        while(ls >> tok) {
            if(tok != "->") {
                string p1 = tok.substr(0, tok.find(','));
                string p2 = tok.substr(tok.find(',') + 1, tok.size() - tok.find(','));
                vpii.emplace_back(make_pair(stoi(p1), stoi(p2)));
            }
        }

        for(int i = 0; i < vpii.size() - 1; ++i) {
            pair<int, int> p1 = vpii[i];
            pair<int, int> p2 = vpii[i + 1];
            
            // cout << "Pair: \n";
            // cout << p1.first << " " << p1.second << " and " << p2.first << " " << p2.second << endl;

            lx = min(lx, p1.first);
            ux = max(ux, p1.first);
            ly = min(ly, p1.second);
            uy = max(uy, p1.second);

            // we want to build the rocks vertically
            if(p1.first == p2.first) { 
                for(int j = min(p1.second, p2.second); j <= max(p1.second, p2.second); j++) {
                    vvb[j][p1.first] = 1;
                }
            }   

            // we want to build the rocks horizontally
            if(p1.second == p2.second) {
                for(int j = min(p1.first, p2.first); j <= max(p1.first, p2.first); j++) {
                    vvb[p1.second][j] = 1;
                }
            }
        }
    }

    // now simulate the sand falling
    // start at point 0, 500

    for(int i = 0; i < vvb[0].size(); ++i) {
        vvb[uy + 2][i] = 1;
    }

    ll int dsa = 0;
    ll int S_STX = 0, S_STY = 500;
    ll int ct = 0;


    bool xt = false;
    while(vvb[S_STX][S_STY] != -1) { 
        recur(vvb, S_STX, S_STY, uy);
        ct++; 
    }

    cout << ct << endl;

    // FOR SAMPLE INPUT
    // cout << "lower x: " << lx << " | upper x: " << ux << endl;
    // cout << "lower y: " << ly << " | upper y: " << uy << endl;

    // cout << "   ";
    // for(int j = lx; j <= ux; ++j) {
    //         cout << j << " ";
    // }
    // cout << endl;
    
    // for(int i = ly; i <= uy; ++i) {
    //     cout << i << ":  ";
    //     for(int j = lx; j <= ux; ++j) {
    //         cout << vvb[i][j] << "   ";
    //     }
    //     cout << endl;
    // }

    return 0;
}