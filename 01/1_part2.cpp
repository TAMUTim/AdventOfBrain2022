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
    priority_queue<int, vector<int>, greater<int>> pq;
    ll int s = 0;
    while(getline(cin, line)) {
        if(line.empty()) {
            pq.emplace(s);
            if(pq.size() > 3) {
                pq.pop();
            }
            s = 0;
        } else {
            s += stoi(line);
        }
    }

    ll int g = 0;
    for(int i = 0; i < 3; ++i) {
        g += pq.top();
        pq.pop();
    }

    cout << g << endl;

    return 0;
}