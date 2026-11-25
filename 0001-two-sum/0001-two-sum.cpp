class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = n-1;
        int first_element = INT_MAX;
        int second_element = INT_MAX;

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == target) {
                first_element = nums[left];
                second_element = nums[right];
                break;
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        for(int i=0;i<n;i++) {
            if(first_element == temp[i] || second_element == temp[i]) {
                ans.push_back(i);
            }

            if(ans.size() == 2) break;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};