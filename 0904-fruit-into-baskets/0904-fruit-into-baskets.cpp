class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> freqMap;
        int j = 0, cnt = 0;

        for(int i=0;i<n;i++) {
            freqMap[fruits[i]]++;

            while(freqMap.size() > 2) {
                freqMap[fruits[j]]--;

                if(freqMap[fruits[j]] == 0) {
                    freqMap.erase(fruits[j]);
                }

                j++;
            }

            cnt = max(cnt, i - j + 1 ) ;
        }

        return cnt;
    }
};