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
    
    vector<int>a(n);
    vector<int>ind(n + 1);
    cin(a);
    for(int i=0;i<n;i++){
        ind[a[i]] = i;
    }
    vector<int>ma(n);
    ma[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        ma[i]=max(a[i],ma[i+1]);
    }
    for(int i=0;i<n;i++){
        if(a[i]!=ma[i]){
            int target = ma[i];
            int l = i;
            int r = ind[target];
            reverse(a.begin() + l,a.begin() +r+1);
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
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