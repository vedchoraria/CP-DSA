//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cin(x) for(int &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << (x) << endl; cout<<endl;


// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- General Functions ---
bool isCo_Prime( int a , int b){
    return true ? gcd(a,b) == 1 : false;
}

// --- Logic ---
void solve() {
    int n,q;cin>>n>>q;
    map<int, int>mp;
    int a,t, pos;
    for(int i = 1; i<=n; i++){
        cin>>a;
        if(mp.find(a) == mp.end()) mp[a] = i;
    }
    while(q--){
        cin>>t;
        pos = mp[t];
        cout<<pos<<" ";
        for(auto &e: mp){
            if(e.second < pos) e.second += 1;
        }
        mp[t] = 1;
    }
    // Solve logic here
    
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