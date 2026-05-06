class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    // The error was likely here: you MUST return the parent
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        
        for (auto& swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }
        
        // Group values by their component root
        unordered_map<int, unordered_map<int, int>> component_pools;
        for (int i = 0; i < n; i++) {
            component_pools[dsu.find(i)][source[i]]++;
        }
        
        int matches = 0;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            int val = target[i];
            
            // Check if the target value exists in this component's pool
            if (component_pools[root][val] > 0) {
                component_pools[root][val]--;
                matches++;
            }
        }
        
        return n - matches;
    }
};