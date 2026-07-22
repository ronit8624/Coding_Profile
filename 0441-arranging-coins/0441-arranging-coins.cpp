class Solution {
public:
    int arrangeCoins(int n) {
        int stairs = 0;

        while(n >= stairs + 1) {
            stairs++;
            n -= stairs;
        }

        return stairs;
    }
};