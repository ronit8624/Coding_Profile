class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        priority_queue<pair<int,char>> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0)
                pq.push({freq[i], char(i + 'a')});
        }

        string ans;

        while(pq.size() >= 2) {
            auto [fre1, ch1] = pq.top();
            pq.pop();

            auto [fre2, ch2] = pq.top();
            pq.pop();

            ans += ch1;
            ans += ch2;

            fre1--;
            fre2--;

            if(fre1 > 0)
                pq.push({fre1, ch1});

            if(fre2 > 0)
                pq.push({fre2, ch2});
        }

        if(!pq.empty()) {
            auto [fre, ch] = pq.top();

            if(fre > 1)
                return "";

            ans += ch;
        }

        return ans;
    }
};