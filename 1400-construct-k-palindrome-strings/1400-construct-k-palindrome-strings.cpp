class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();

        if(n < k) return false;

        unordered_map<char, int> freqMap;
        for(int i = 0; i < n; i++) {
            freqMap[s[i]]++;
        }

        int odd = 0;

        for(auto it : freqMap) {
            int freq = it.second;

            if(freq % 2 != 0) odd++;
        }

        return odd <= k;
    }
};