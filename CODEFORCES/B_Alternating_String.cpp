// Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        int a = 0, b = 0;

        for (char c : s) {
            if (c == 'a') a++;
            else b++;
        }

        // For an alternating string:
        // difference between count of a and b must be at most 1
        if (abs(a - b) <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}