#include <bits/stdc++.h>

#define ll long long
#define M_PI 3.14159265358979323846
#define MOD 1000000007

using namespace std;

struct nodey {
    ll int s;
    ll int f;
    vector<nodey*> v;
    string n;
    bool il;
    nodey* par;

    public:
        nodey() {
            s = 0;
            f = 0;
            n = "ROOT";
            il = true;
            par = nullptr;
        }
};

ll int fillSize(nodey* root) {
    if(root->il) {
        root->s = root->f;
        return root->s;
    }

    for(auto g : root->v) {
        root->s += fillSize(g);
    }

    root->s += root->f;

    return root->s;
}

void getSize(nodey* root, ll int target, ll int& pp) {
    if(root->s >= target) {
        pp = min(pp, root->s);
    }

    for(auto g : root->v) {
        getSize(g, target, pp);
    }
}


void printTree(nodey* root) {
    cout << "Node: " << root->n << " with size: " << root->s << " is a leaf? " << root->il << endl;
    
    for(auto g : root->v) {
        printTree(g);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("7_in.txt", "r", stdin);
    freopen("7_out.txt", "w", stdout);

    ll int c = 0;

    string line;
    nodey* root = new nodey;
    nodey* s_root = root;
    bool first = true;
    while(getline(cin, line)) {
        stringstream ss(line);
        string token;
        vector<string> v;
        while(ss >> token) {
            v.emplace_back(token);
        }

        if(v[0] == "$") {
            // know its a command

            // ignore if its ls
            if(v[1] == "ls") continue;

            // only other alternative is cd
            if(v[2] == "/") {
                s_root = root;
            } else if(v[2] == "..") {
                s_root = s_root->par;
            } else {
                for(auto gg : s_root->v) {
                    if(gg->n == v[2]) {
                        s_root = gg;
                    }
                }
            }
        } else {
            if(v[0] == "dir") {
                nodey* x = new nodey;
                x->n = v[1];
                x->par = s_root;
                s_root->v.push_back(x);
                s_root->il = false;
            } else {
                s_root->f += stoi(v[0]);
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    ll int to = fillSize(root);

    ll int target = to - 40000000;
    ll int pp = INT_MAX;

    getSize(root, target, pp);

    cout << pp << endl;
    
    return 0;
}