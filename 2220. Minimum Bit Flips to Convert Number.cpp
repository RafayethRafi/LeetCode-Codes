class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal;
        x = __builtin_popcount(x);

        return x;
    }
};
