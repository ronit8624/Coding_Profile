class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int target = n / 2;
        int removed = 0, ans = 0;

        unordered_map<int, int> freqMap;
        for(int i=0;i<n;i++) {
            freqMap[arr[i]]++;
        }

        vector<int> freq;
        for(auto it : freqMap) {
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end(), greater<int>());

        for(int i=0;i<freq.size();i++) {
            removed += freq[i];
            ans++;

            if(removed >= target)
                break;
        }

        return ans;
    }
};