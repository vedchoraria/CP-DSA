#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    if (c == 'g') {
        cout << 0 << endl;
        return;
    }

    // Double the string to handle the cyclic nature
    s += s; 
    
    int max_wait = 0;
    int last_green_pos = -1;

    // Traverse from right to left
    // We only need to check up to the original length n
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            last_green_pos = i;
        }
        
        if (s[i] == c && last_green_pos != -1) {
            // We only care about the occurrences in the first half 
            // to find the max wait time starting from any position
            if (i < n) {
                max_wait = max(max_wait, last_green_pos - i);
            }
        }
    }

    cout << max_wait << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}