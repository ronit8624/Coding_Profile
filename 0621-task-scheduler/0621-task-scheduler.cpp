class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);

        for(auto it : tasks) {
            freq[it - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];
        int gaddhe = maxFreq - 1;
        int idleSlots = n * gaddhe;

        for(int i=24;i>=0;i--) {
            idleSlots -= min(freq[i], gaddhe);
        }

        if(idleSlots > 0) return idleSlots + tasks.size();

        return tasks.size();
    }
};