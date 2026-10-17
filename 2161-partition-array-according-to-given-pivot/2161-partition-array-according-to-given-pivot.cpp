class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int lesser = 0, equal = 0, greater = 0;

        for(int i=0;i<n;i++) {
            if(nums[i] < pivot) lesser++;
            else if(nums[i] > pivot) greater++;
            else equal++;
        }

        vector<int> ans(n);
        int l = 0, e = lesser, g = n - greater;

        for(int i=0;i<n;i++) {
            if(nums[i] < pivot) {
                ans[l] = nums[i];
                l++;
            }
            else if(nums[i] > pivot) {
                ans[g] = nums[i];
                g++;
            }
            else {
                ans[e] = nums[i];
                e++;
            }
        }

        return ans;
    }
};