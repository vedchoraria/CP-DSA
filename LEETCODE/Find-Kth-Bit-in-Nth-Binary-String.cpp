1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        string sequence = "0";
5        for (int i = 1; i < n && k > sequence.length(); ++i) {
6            sequence += '1';
7            string temp = sequence;
8            for (int j = temp.length() - 2; j >= 0; --j) {
9                char invertedBit = (temp[j] == '1') ? '0' : '1';
10                sequence += invertedBit;
11            }
12        }
13    
14        return sequence[k - 1];
15    }
16};