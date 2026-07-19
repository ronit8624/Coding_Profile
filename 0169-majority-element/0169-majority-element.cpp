class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, maxCnt = 1;
        int el = nums[0];

        for(int i=1;i<n;i++) {
            if(nums[i] == el) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            }
            else {
                cnt--;

                if(cnt == 0) {
                    el = nums[i];
                    cnt = 1;
                }
            }
        }

        return el;
    }
};