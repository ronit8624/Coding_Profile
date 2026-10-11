class Solution {
public:
    string getKey(string str) {
        string key = str;
        sort(key.begin(), key.end());
        return key;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        int n = strs.size();

        for(int i=0;i<n;i++) {
            string curr = strs[i];
            string key = getKey(strs[i]);
            
            mpp[key].push_back(curr);
        }

        for(auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};