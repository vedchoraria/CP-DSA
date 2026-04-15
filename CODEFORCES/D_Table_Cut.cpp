#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                pref[i][j] = a[i][j]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        long long S = pref[n][m];
        long long A = 0;
        int last_col = 1;
        vector<int> cut(n + 1);

        for (int i = 1; i <= n; i++) {
            long long best_diff = LLONG_MAX;
            int best_j = last_col;

            for (int j = last_col; j <= m; j++) {
                long long row_add =
                    pref[i][j] - pref[i][j - 1]
                  - pref[i - 1][j] + pref[i - 1][j - 1];

                long long candidate = A + row_add;
                long long diff = llabs(2 * candidate - S);

                if (diff < best_diff) {
                    best_diff = diff;
                    best_j = j;
                }
            }

            A += pref[i][best_j]
               - pref[i][best_j - 1]
               - pref[i - 1][best_j]
               + pref[i - 1][best_j - 1];

            cut[i] = best_j;
            last_col = best_j;
        }

        long long ans = A * (S - A);
        cout << ans << '\n';

        // reconstruct path
        string path;
        int col = 1;
        for (int i = 1; i <= n; i++) {
            while (col < cut[i]) {
                path.push_back('R');
                col++;
            }
            if (i < n) path.push_back('D');
        }

        cout << path << '\n';
    }
    return 0;
}
