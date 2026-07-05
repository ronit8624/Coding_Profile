class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;

        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;

        for (char c : p) {
            pMap[c]++;
        }

        int left = 0;
        int count = p.size();

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            sMap[ch]++;

            if (pMap.count(ch) && sMap[ch] <= pMap[ch]) {
                count--;
            }

            if (right - left + 1 > p.size()) {
                char leftChar = s[left];

                if (pMap.count(leftChar) && sMap[leftChar] <= pMap[leftChar]) {
                    count++;
                }

                sMap[leftChar]--;
                left++;
            }

            if (count == 0) {
                res.push_back(left);
            }
        }

        return res;
    }
};