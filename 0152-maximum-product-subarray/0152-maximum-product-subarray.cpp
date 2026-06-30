class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftProd = 1, rightProd = 1;
        int ans = INT_MIN;

        for(int i=0;i<n;i++) {
            if(leftProd == 0) leftProd = 1;
            if(rightProd == 0) rightProd = 1;
            
            leftProd *= nums[i];
            rightProd *= nums[n-i-1];

            ans = max(ans, max(leftProd, rightProd));
        }

        return ans;
    }
};