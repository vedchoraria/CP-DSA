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

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    //Even Case : to get minimum lcm and less than n/w , both a and b must be less than n/2, but a+b = n/2;, therefore a=n/2 and b =n/2
    if(n%2 == 0) {
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }

    //Odd Case : LCM *GCD = n, so min LCM , highest GCD , so a = greatest proper divisor
    //Any composite number $n$ must have at least one divisor less than or equal to $\sqrt{n}$.
    // So , our task is just to find the smallest factor divisible , so  that n/i = greatest divisor, and henceforth their lcm is least

    int gpd =1;
    for(int i =2; i*i <= n ; i++){
        if(n%i == 0){
        gpd = n/i;
        break;
        }
    }
    cout << gpd << " " << n - gpd << endl;
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