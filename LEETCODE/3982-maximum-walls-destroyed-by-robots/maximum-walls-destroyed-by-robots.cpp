class Solution {
public:
    int maxWalls(vector<int>& rb, vector<int>& d,vector<int>& w) {
        int n = rb.size();
        int pos1, pos2, pos3, lpos, rpos;
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[rb[i]] = d[i];
        }
        sort(rb.begin(), rb.end());
        sort(w.begin(), w.end());
        for (int i = 0; i < n; i++) {
            pos1 = upper_bound(w.begin(), w.end(), rb[i]) -w.begin();
            if (i >= 1) {
                lpos=lower_bound(w.begin(),w.end(),max(rb[i] - m[rb[i]],rb[i-1]+1)) -w.begin();
            } else {
                lpos = lower_bound(w.begin(), w.end(),rb[i] - m[rb[i]]) - w.begin();
            }
            left[i] = pos1 - lpos;
            if (i < n - 1) {
                rpos =
                    upper_bound(w.begin(), w.end(),min(rb[i] + m[rb[i]], rb[i+1]-1)) -w.begin();
            } else {
                rpos =upper_bound(w.begin(), w.end(),rb[i] + m[rb[i]]) -w.begin();
            }
            pos2 = lower_bound(w.begin(), w.end(), rb[i]) -w.begin();
            right[i] = rpos - pos2;
            if (i == 0) {
                continue;
            }
            pos3 = lower_bound(w.begin(), w.end(), rb[i-1]) -w.begin();
            num[i] = pos1 - pos3;
        }
        int subLeft, subRight, curr_l, curr_r;
        subLeft = left[0];
        subRight = right[0];
        for (int i = 1; i < n; i++) {
            curr_l =
                max(subLeft + left[i],subRight-right[i - 1] +min(left[i] + right[i-1], num[i]));
            curr_r = max(subLeft + right[i], subRight + right[i]);
            subLeft = curr_l;
            subRight = curr_r;
        }
        return max(subLeft, subRight);
    }
};