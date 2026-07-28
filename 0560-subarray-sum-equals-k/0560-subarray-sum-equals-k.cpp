class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, cnt = 0;
        unordered_map<int, int> preSumMap;
        preSumMap[0] = 1;

        for(int i=0;i<n;i++) {
            sum += nums[i];
            int req = sum - k;

            if(preSumMap.find(req) != preSumMap.end()) {
                cnt += preSumMap[req];
            }

            preSumMap[sum]++;
        }

        return cnt;
    }
};