class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxA = 0;
        h.push_back(0);

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[i] < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
};