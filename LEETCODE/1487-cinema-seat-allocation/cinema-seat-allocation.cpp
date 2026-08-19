class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number -> bitmask of reserved seats
        unordered_map<int, int> occupied;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // We only care about seats 2 through 9
            if (col >= 2 && col <= 9) {
                occupied[row] |= (1 << col);
            }
        }

        // Any completely empty row can accommodate 2 families
        int ans = (n - (int)occupied.size()) * 2;

        // Masks representing the required empty seats (as 0 bits)
        // Seats 2,3,4,5 -> (1<<2) | (1<<3) | (1<<4) | (1<<5) = 60
        // Seats 6,7,8,9 -> (1<<6) | (1<<7) | (1<<8) | (1<<9) = 960
        // Seats 4,5,6,7 -> (1<<4) | (1<<5) | (1<<6) | (1<<7) = 240
        const int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // 60
        const int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); // 960
        const int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // 240

        for (const auto& [row, mask] : occupied) {
            bool left   = (mask & leftMask) == 0;
            bool right  = (mask & rightMask) == 0;
            bool middle = (mask & middleMask) == 0;

            if (left && right) {
                ans += 2;
            } else if (left || right || middle) {
                ans += 1;
            }
        }

        return ans;
    }
};