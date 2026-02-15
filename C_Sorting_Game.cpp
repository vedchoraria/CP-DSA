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
    
    string s;
    cin>>s;
    
    bool no_move = true;
    for(int i =0;i<n-1; i++){
        if(s[i] >s[i+1]){
            no_move = false;
            break;
        }
    }
    if(no_move){
        print("Bob");
        return;
    }
        //ALICE
    print("Alice");
    int zero = 0;
    for(char c : s){
        if(c == '0')zero++;
    }
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(i<zero){
            if(s[i] =='1'){
                ans.push_back(i+1); }
        }
        else{
            if(s[i] =='0'){
                ans.push_back(i+1);
            }
        }
    }    
    print(ans.size());
    for(int i=0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

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