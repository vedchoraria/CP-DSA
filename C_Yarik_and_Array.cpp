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

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> b(n);
    cin(b); 
    int ans = INT_MIN;
    int i =0, j =0;
    int sum =0;
    while(j<n){
        if(sum < 0){
            sum =0;
            i = j;
        }
        if(i<j){
            if((b[j] ^ b[j-1]) & 1){
                sum += b[j];
            }
            else{
                sum = b[j];
                i=j;
            }
        }
        else{
            sum = b[j];
            
        }

        ans = max(sum , ans);
        j++;
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