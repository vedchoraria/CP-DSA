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

// --- Input/output Helpers ---
// FIXED: Use reference &x so cin actually stores the value in the vector
void ioar(vector<int> &v, int size) {
    v.resize(size);
    for (int &x : v) cin >> x;
}

void opar(const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    cout << '\n';
}

// --- Logic ---
void solve() {
    ll n;
    if (!(cin >> n)) return;
    
    vector<ll> b; 
    ioar(b, n); // Correctly resizes and fills 'b'

    // Solve logic here
    ll zero =0, sum =0;
    for(ll i : b){
        if( i != 0) {zero++;
            sum += i;
        }
    }
    cout<<min(sum-n+1 , zero)<<endl;
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