class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int> lastIndex(26);
        vector<bool> visited(26, false);

        for(int i=0;i<n;i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        string ans = "";

        for(int i=0;i<n;i++) {
            char ch = s[i];

            if(visited[ch - 'a']) continue;

            while(!ans.empty() &&
                  ans.back() > ch &&
                  lastIndex[ans.back() - 'a'] > i) {

                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
    }

    string smallestSubsequence(string s) {
        return removeDuplicateLetters(s);
    }
};