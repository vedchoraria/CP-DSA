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

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
// --- Logic ---
void solve() {
    int len;
    cin >> len;
    string str;
    cin >> str;
 
    int total = 0;
    int start_idx = -1; 
    int end_idx = -1;  
 
    for (int k = 0; k < len; k++) {
        if (str[k] == '1') {
            total++;
            if (start_idx == -1) start_idx = k;
            end_idx = k;
        }
    }
 
    if (total == 0) {
        cout << (len + 2) / 3 << "\n";
        return;
    }
 
    int extras = 0;
 
    if (start_idx > 0) {
        extras += (start_idx + 1) / 3; 
    }
 
    int tail = len - 1 - end_idx;
    if (tail > 0) {
        extras += (tail + 1) / 3;
    }
 
    int seg = 0;
    for (int k = start_idx + 1; k < end_idx; k++) {
        if (str[k] == '0') {
            seg++;
        } else {
            extras += (seg / 3);
            seg = 0;
        }
    }
    
    extras += (seg / 3);
 
    cout<<(total + extras)<< "\n";
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