//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cin(x) for(auto &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << i << endl; cout<<endl;



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
//LCM FUnc
// --- Logic ---
void print_queue(queue<int>q){
    cout<<"QUEUE : ";
    while(!q.empty()) {cout<<q.front()<<" ";
        q.pop();}
        cout<<endl;
}
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> b(n); 
    cin(b);
    queue<int>q;
    sort(b.rbegin() , b.rend());
    for(int i : b){
        q.push(i);
    }
    cout<<q.front()<<" ";
    int temp = q.front();
    q.pop();
    int cnt =1;
    while(!q.empty() && cnt<n){
        print_queue(q);
        int a = q.front();
        q.pop();

        if((temp|a) != temp){
            cout<<a<<" ";
        }
        else q.push(a);
        temp = temp|a;
        cnt++;
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();

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