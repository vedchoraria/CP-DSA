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

// --- Logic ---
bool check(vector<int>&v, ll h, ll x){
    ll nd = 0;
    for(auto i: v){
        nd += (h > i) ? (h-i) : 0;
        if(nd > x) return false;
    }
    return true;
}
void solve(){
    ll n, x;
    cin>>n>>x;
    int mn = INT_MAX;
    vector<int>v(n);
    for(auto &i: v){
        cin>>i;
        mn = min(mn, i);
    }
    ll s = 0, e = mn+x, mid, ans = 0;
    while(s<=e){
        mid = s+(e-s)/2;
        if(check(v, mid, x)){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    print(ans);
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