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
    if (!(cin >> n)) return;
    
    vector<int> b(n); 
    cin(b);

    int j = n-1;
    
int ans = -1;
    for(j ; j>=0 ; j--){
        int i = j-1;
        if(b[j] == 1){
            ans = max(ans , 2*(j+1));
            break;
        }
        while(i>=0 && !isCo_Prime(b[j] , b[i])) i--;

        if(i >= 0 && isCo_Prime(b[i] , b[j]))
        ans = max(ans , i+j+2);
    }

    print(ans);
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