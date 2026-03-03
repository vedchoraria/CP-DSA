//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cin(x) for(auto &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << i << endl; cout<<endl;



// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- General Functions ---
bool isCo_Prime( int a , int b){
    return true ? gcd(a,b) == 1 : false;
}

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
//LCM FUnc
// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> x(n), y(n); 
    cin(x); cin(y);
    vector<int>diff(n);
    for(int i=0;i<n;i++) diff[i] = y[i]-x[i];
    // ek negative ke liye 1 se zyada element use nhi hoga...so if koi element usse bada nhi hai...we wont take it ...
    // like -8 +2+1+5 = 0 , 4 element use hue , but only one pair , apana directly 1+2 bhi us kr sakte the
    sort(diff.begin(), diff.end());
    int l = 0;
    int r = diff.size() - 1;
    int ans = 0;
    while(l < r)
    {
        if(diff[l] + diff[r] >= 0)
        {
            ans++;
            l++;
            r--;
        }      
        else
        {
            l++;  // too negative, discard it
        }
    }

    // Solve logic here
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