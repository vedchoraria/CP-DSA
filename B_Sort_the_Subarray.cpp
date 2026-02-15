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

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n), b(n); 
    cin(a);
    cin(b);
    int l = -1 , r = -1;
    int i =0 , j =0;
    for(i =0 ; i<n; i++){
        if(a[i] != b[i]){
            l = i;
            break;
        }
    }
    while(i > 0 && b[i] >= b[i-1] ) i--;
    l = i;


    for(j =n-1 ; j>=0; j--){
        if(a[j] != b[j]){
            r = j;
            break;
        }
    }

    while(j < n-1 && b[j] <= b[j+1] ) j++;
    r = j;

    if(l>r) cout<<"-1 -1"<<endl;
    else cout<<l+1<<" " << r +1 << endl;

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