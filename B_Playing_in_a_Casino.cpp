#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; 

	while (t--)
	{
		int n, m;
		cin >> n >> m; 

		
		vector<vector<long long>> v(m, vector<long long>(n));

		
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				cin >> v[i][j]; 
			}
		}
		// Sort each row of the rotated matrix
		for (int i = 0; i < m; i++)
		{
			sort(v[i].begin(), v[i].end()); // Sort the i-th row
		} // Time complexity: O(m * (n log n))

		long long ans = 0; // Initialize the total winnings

		// Calculate the total winnings for all games
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// Calculate the contribution of v[i][j] to the total winnings
				ans -= (v[i][j] * (n - j - 1));
				ans += (v[i][j] * j);
			}
		} // Time complexity: O(n * m)

		cout << ans << "\n"; // Output the total winnings for the current test case
	}
}

// Time Complexity (TC): O(m * (n log n))
// Space Complexity (SC): O(n * m)
