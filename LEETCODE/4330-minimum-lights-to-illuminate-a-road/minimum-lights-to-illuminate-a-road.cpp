class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> ans(n + 1, 0); 
        
        for (int i = 0; i < n; i++) {
            int v = lights[i];
            if (v > 0) {
                ans[max(0, i - v)] += 1;
                if (i + v + 1 < n + 1) {
                    ans[i + v + 1] -= 1;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }
        
        int ops = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                ops++;
                if (i + 1 < n && ans[i + 1] == 0) {
                    i++;
                    if (i + 1 < n && ans[i + 1] == 0) {
                        i++;
                    }
                }
            }
        }
        return ops;
    }
};