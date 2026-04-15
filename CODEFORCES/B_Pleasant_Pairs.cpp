#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases

	while (t--)
	{
		int n;
		cin >> n; // Read the length of the array for the current test case

		// Create a vector of pairs to store the array elements and their original indices
		vector<pair<long long, long long>> v(n);

		// Read the array elements and store them with their indices
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first; // Read the element
			v[i].second = i + 1; // Store the 1-based index
		}

		// Sort the vector based on the array elements
		sort(v.begin(), v.end()); // O(n log n)

		int ans = 0; // Initialize the count of pleasant pairs

		// Iterate over each pair of elements in the sorted vector
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				// If the product of the elements is greater than or equal to 2*n, break the loop
				if (v[i].first * v[j].first >= 2 * n)
					break;

				// Check if the product of the elements equals the sum of their indices
				if (v[i].first * v[j].first == v[i].second + v[j].second) // a[i] * a[j] == i + j
					ans++; // Increment the count of pleasant pairs
			}
		} // O(n log n)

		// Output the count of pleasant pairs for the current test case
		cout << ans << "\n";
	}

	return 0;
}

//! Total Time Complexity (TC): O(n log n)
//! Total Space Complexity (SC): O(n)
