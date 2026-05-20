#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> c(n);
        for (int &x : c) cin >> x;

        sort(c.rbegin(), c.rend());

        int ans = 0;
        int extra = 0;
        bool oneExtra = false;
        //Case like 111111 7 , (for circular) one extra
        if (n > 1 && c[0] >= 2 && c[1] == 1)
            oneExtra = true;

        for (int x : c) {
            if (x == 1) {
                // Adding that one only if it can be adjusted
                if (extra > 0) {
                    extra--;
                    ans++;
                } else if (oneExtra) {
                    oneExtra = false;
                    ans++;
                }
            } else {
                // All others will be directly accepted.
                ans += x;

                // to safely place 1 singleton AA X AA , AA X AAA
                // so actually x/2 - 1;
                //INTUITION: 
                //first 4 cards give 1 slot, then every extra 2 cards give another slot 
                if (x >= 4) {
                    extra += 1 + (x - 4) / 2;
                }
            }
        }
        // Minimum 3 cards required else none
        if (ans < 3) ans = 0;

        cout << ans << '\n';
    }

    return 0;
}