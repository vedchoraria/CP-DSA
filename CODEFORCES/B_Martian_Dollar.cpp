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

    int n, b;
    if (cin >> n >> b) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_money = b; 
        int min_price = a[0]; 

        for (int i = 1; i < n; i++) {
            if (min_price < a[i]) {
                int dollars = b / min_price;
                int remainder = b % min_price;
                int potential_money = (dollars * a[i]) + remainder;
                
                max_money = max(max_money, potential_money);
            }

          
            min_price = min(min_price, a[i]);
        }
        
        print(max_money);
    }
}


int main() {
    fastio;
    // int t = 1;
    // cin >> t; 
    // while (t--) {
        solve();
    // }
    return 0;
}