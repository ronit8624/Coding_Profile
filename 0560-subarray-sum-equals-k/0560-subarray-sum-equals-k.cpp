class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, cnt = 0;
        unordered_map<int, int> preMap;
        preMap[0] = 1;

        for(int i=0;i<n;i++) {
            sum += nums[i];
            int req = sum - k;

            if(preMap.find(req) != preMap.end()) {
                cnt += preMap[req];
            }
            
            preMap[sum]++;
        }

        return cnt;
    }
};