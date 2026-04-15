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
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    vector<ll>b(n);
    for(int i=0; i<n;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    ll ma = 0;
    ll req = 0;

    for(int i=0; i<n;i++){
        req+=b[i];
        if(req>n)break;
        ll curr = a[n-req];
        ll temp = curr*(i+1);
        if(temp > ma){
            ma = temp;
        }
    }

    print(ma);
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