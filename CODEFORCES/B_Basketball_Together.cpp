#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, d;
    cin >> n >> d;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // Sort players in descending order
    sort(p.rbegin(), p.rend());

    int wins = 0;
    int players_used = 0;

    for (int i = 0; i < n; i++) {
        long long leader_power = p[i];
        
        // Minimum players needed for this team: (d / leader_power) + 1
        long long needed = (d / leader_power) + 1;
        
        // Check if we have enough players left (including the leader)
        if (players_used + needed <= n) {
            wins++;
            players_used += needed;
        } else {
            // Not enough players left to form any more winning teams
            break;
        }
    }

    cout << wins << endl;
    return 0;
}