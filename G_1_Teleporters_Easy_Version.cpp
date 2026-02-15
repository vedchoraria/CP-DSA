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
#define sort(x) sort((x).begin() , (x).end())

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    int c; cin>>c;
    vector<int> b(n); 
    cin(b);
    vector<int> temp;
    for(int i = 0 ; i<n;i++)
    temp.pb(i+1+b[i]);

    sort(temp);
    int ans =0;
    int j =0;
    while(c>0 && j<n){
        c-= temp[j];
        if(c<0) break;
        ans++;
        j++;
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