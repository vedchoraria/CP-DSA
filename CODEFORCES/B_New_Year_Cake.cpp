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

int build(ll white, ll dark, bool top) {
    int boom = 0;
    for(int i= 0; ;i++){
        ll size = 1LL<<i;
        if((i % 2 == 0) == top){
            if(white<size) break;
            white-= size;
        } 
        else{
            if(dark<size) break;
            dark-= size;
        }
        boom++;
    }
    return boom;
}


void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int &x : a) cin>>x;
    for(int &x : b) cin>>x;
    for(int &x : c) cin>>x;
    vector<int> A(2*n), B(2*n), C(2*n);
    for (int i = 0; i < n; i++) {
        A[i] = A[i+n] = a[i];
        B[i] = B[i+n] = b[i];
        C[i] = C[i+n] = c[i];
    }

        // AB[i][j] = true if for all t: A[i+t] < B[j+t]
        vector<vector<char>> AB(n, vector<char>(n, 0));
        vector<vector<char>> BC(n, vector<char>(n, 0));

        // compute AB
        for (int i = 0; i < n; i++) {
            vector<int> diff(2*n);
            for (int t = 0; t < 2*n; t++)
                diff[t] = A[i+t] - B[t];

            deque<int> dq;
            for (int t = 0; t < 2*n; t++) {
                while (!dq.empty() && diff[dq.back()] <= diff[t])
                    dq.pop_back();
                dq.push_back(t);

                if (dq.front() <= t - n)
                    dq.pop_front();

                if (t >= n - 1) {
                    int j = t - (n - 1);
                    if (j < n && diff[dq.front()] < 0)
                        AB[i][j] = 1;
                }
            }
        }

        // compute BC
        for (int j = 0; j < n; j++) {
            vector<int> diff(2*n);
            for (int t = 0; t < 2*n; t++)
                diff[t] = B[j+t] - C[t];

            deque<int> dq;
            for (int t = 0; t < 2*n; t++) {
                while (!dq.empty() && diff[dq.back()] <= diff[t])
                    dq.pop_back();
                dq.push_back(t);

                if (dq.front() <= t - n)
                    dq.pop_front();

                if (t >= n - 1) {
                    int k = t - (n - 1);
                    if (k < n && diff[dq.front()] < 0)
                        BC[j][k] = 1;
                }
            }
        }

        // count valid triples
        ll ans = 0;
        for (int j = 0; j < n; j++) {
            ll cntA = 0, cntC = 0;
            for (int i = 0; i < n; i++)
                if (AB[i][j]) cntA++;
            for (int k = 0; k < n; k++)
                if (BC[j][k]) cntC++;
            ans += cntA * cntC;
        }

        cout << ans << '\n';
    
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