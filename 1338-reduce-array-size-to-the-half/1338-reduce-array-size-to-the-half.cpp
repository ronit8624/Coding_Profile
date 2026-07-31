class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;

        for(int i=0;i<n;i++) {
            mpp[arr[i]]++;
        }

        vector<int> cntel;

        for(auto& it : mpp) {
            cntel.push_back(it.second);
        }

        sort(cntel.begin(), cntel.end(), greater<int>());

        int target = n / 2;
        int removed = 0;
        int ans = 0;

        for(int i=0;i<cntel.size();i++) {
            removed += cntel[i];
            ans++;

            if(removed >= target) {
                break;
            }
        }

        return ans;
    }
};