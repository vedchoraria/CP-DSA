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
    ll n,k;
        cin>>n>>k;
        vector<ll>arr(n,0);
        for(int i=0;i<n;i++)cin>>arr[i];
 
        sort(arr.begin(),arr.end());
        ll low=0;
        ll high=n-1;
        vector<ll>pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)pre[i]+=pre[i-1]+arr[i];
       ll ans=0;
        for(int i=0;i<=k;i++){
         ll sum=pre[n-1 - (k-i) ]-pre[2*i]+arr[2*i];
         ans=max(sum,ans);
        }
        cout<<ans<<endl;
    
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