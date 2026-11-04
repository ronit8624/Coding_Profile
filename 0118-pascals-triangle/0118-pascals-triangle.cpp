class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0;i<numRows;i++) {
            long long val = 1;
            vector<int> row;

            for(int j=0;j<=i;j++) {
                row.push_back((int)val);
                val = (val * (i - j)) / (j + 1);
            }

            ans.push_back(row);
        }

        return ans;
    }
};