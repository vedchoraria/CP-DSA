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
    ll n;
    if (!(cin >> n)) return;
    ll q;
    cin >> q;
    vector<ll>a(n),b(n);
    for(ll i= 0;i<n;i++)cin>>a[i];
    for(ll i= 0;i<n;i++)cin>>b[i];
    vector<ll>imax(n);
    for(ll i= 0;i<n;i++){
        imax[i] = max(a[i], b[i]);
    }
    for(ll i =n-2;i>=0;i--) { 
    imax[i] = max(imax[i+1], imax[i]);
    }
    vector<ll>sum(n +1, 0); 
    for(ll i= 0;i<n;i++){
        sum[i+1] = sum[i] + imax[i];
    }
    while(q--) {
        int l,r;
        cin>>l>>r;
        if(l>r||l<1||r>n) {
            cout<<0<<" ";
        }else {
            cout<<sum[r]-sum[l-1]<<" ";
        }
    }
    cout<<endl;
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