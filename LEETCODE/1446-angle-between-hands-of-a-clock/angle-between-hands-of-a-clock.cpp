class Solution {
public:
    double angleClock(int hour, int minutes) {
        double bigHand = minutes*6.0;
        double small = 30.0 * (hour%12) + 0.5*minutes;
        double diff = abs(bigHand - small);
        return min(diff, 360-diff);
    }
};