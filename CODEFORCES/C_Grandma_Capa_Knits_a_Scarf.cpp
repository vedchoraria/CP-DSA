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
    string s; cin>>s;
    int ans = INT_MAX;
    vector<int>alpa(26,0);
    for(int k=0;k<26;k++){
        int cnt =0; int j = n-1 , i= 0;
        bool valid = true;
        while(i<j){
            if(s[i] == s[j]){
                i++; j--;
                continue;
            }
            else if(s[i] == k+'a'){
                i++; cnt++;
            }
            else if(s[j] == k+'a'){
                j--; cnt++;
            }
            else {break; valid = false;}


        }
        if(valid){
        ans = min(ans, cnt);}


    }

    print(ans);

    // Solve logic here
    
}

int main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}