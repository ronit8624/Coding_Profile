class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long prod = 1;
        vector<int> negatives;
        int zeros = 0;
        bool taken = false;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                prod *= nums[i];
                taken = true;
            }
            else if(nums[i] < 0) {
                negatives.push_back(nums[i]);
            }
            else {
                zeros++;
            }
        }

        sort(negatives.begin(), negatives.end());
        int len = negatives.size();

        if(len % 2 == 0) {
            for(int i = 0; i < len; i++) {
                prod *= negatives[i];
                taken = true;
            }
        }
        else {
            for(int i = 0; i < len - 1; i++) {
                prod *= negatives[i];
                taken = true;
            }
        }

        if(!taken) {
            if(zeros > 0) return 0;
            return *max_element(nums.begin(), nums.end());
        }

        return prod;
    }
};