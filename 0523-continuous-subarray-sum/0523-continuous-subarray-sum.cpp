class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> modMap;
        int sum = 0;
        modMap[0] = -1;

        for(int i=0;i<n;i++) {
            sum += nums[i];
            int rem = sum % k;

            if(modMap.find(rem) != modMap.end()) {
                if(i - modMap[rem] >= 2) return true;
            }
            else {
                modMap[rem] = i;
            }
        }

        return false;
    }
};