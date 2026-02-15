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
#define print_arr(x) for(int &i : (x)) cout << i << " "; cout<<endl;

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    int q;
    cin>>q;

    vector<int> a(n) , x(q); 
    cin(a);
    cin(x);
    int minx =31;
    
    for(int i =0 ;i<q ; i++){
        //checking if a smaller power of two is already been added , then it will be not divisible by the larger powers
        if(x[i] < minx){
            minx = x[i];
            for(int j = 0 ; j<n ;j++){
               if(a[j] % (int)pow(2,x[i]) == 0) a[j] += pow(2,x[i]-1);
            }
        }
        
    }

    print_arr(a);
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