//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---

bool has2025(string str){
    for(int i =0;i<=str.size()-4;i++){
        if(str.substr(i, 4) == "2025"){
            return true;
        }
    }
    return false;
}

bool has2026(string str){
    for(int i = 0;i <= str.size() - 4;i++){
        if(str.substr(i, 4) == "2026"){
            return true;
        }
    }
    return false;
}

int get_cost_A(string s, int n) {
    int min_ops = 5; // Max possible is 4
    for (int i = 0; i <= n - 4; ++i) {
        int ops = 0;
        if (s[i] != '2') ops++;
        if (s[i+1] != '0') ops++;
        if (s[i+2] != '2') ops++;
        if (s[i+3] != '6') ops++;
        min_ops = min(min_ops, ops);
    }
    return min_ops;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if(has2026(s) || !has2025(s)){
        cout<<0<<endl;
        return;
    }
    cout<<1<<endl;
    
}

int main() {
    fastio;
    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}