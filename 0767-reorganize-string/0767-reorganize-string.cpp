class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        int n = s.size();
        vector<int> freq(26, 0);

        for(int i=0;i<n;i++) {
            freq[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for(int i=0;i<26;i++) {
            if(freq[i] != 0) {
                pq.push({freq[i], i + 'a'});
            }
        }

        while(pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            if(first.first > 0) pq.push(first);
            if(second.first > 0) pq.push(second);
        }

        if(!pq.empty()) {
            if(pq.top().first > 1) return "";
            ans += pq.top().second;
        }

        return ans;
    }
};