class Solution {
public:
    int getNextNum(int n) {
        int ans = 0;

        while(n > 0) {
            int digit = n % 10;
            ans += (digit * digit);
            n /= 10;
        }

        return ans;
    }
    
    bool isHappy(int n) {
        unordered_set<int> vis;

        while(vis.find(n) == vis.end()) {
            vis.insert(n);
            n = getNextNum(n);

            if(n == 1) return true;
        }

        return false;
    }
};