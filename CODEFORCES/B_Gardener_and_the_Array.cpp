#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		int n;
		cin >> n; // Read the size of the array for each test case
		map<int, int> mp; // Map to count occurrences of each bit position
		vector<vector<int>> v; // Vector to store the bit positions for each number
		for (int i = 0; i < n; i++) { // Loop through each number in the array
			int x;
			cin >> x; // Read the number of set bits in the current number
			vector<int> temp(x); // Temporary vector to store the bit positions
			for (int j = 0; j < x; j++) {
				cin >> temp[j]; // Read each bit position
				mp[temp[j]]++; // Increment the count of this bit position
			}
			v.push_back(temp); // Store the bit positions in the vector
		}
		string ans = "No"; // Default answer is "No"
		for (int i = 0; i < n; i++) { // Check each number's bit positions
			int f = 1; // Flag to check if all bit positions are repeated
			for (auto it : v[i]) {
				if (mp[it] == 1) { // If any bit position is unique
					f = 0; // Set flag to 0
					break; // Break the loop
				}
			}
			if (f == 1) { // If all bit positions are repeated
				ans = "Yes"; // Set answer to "Yes"
				break; // Break the loop
			}
		}
		cout << ans << endl; // Output the answer for the test case
        

        for(auto it : mp){
            cout<<it.first<<" = "<<it.second<<endl;
        }
	}
}

// Time Complexity (TC): O(k log k)
// Space Complexity (SC): O(k)
