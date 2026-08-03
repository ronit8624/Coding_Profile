class Solution {
public:
    using P = pair<int, int>;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans;
        long long time = arr[0][0];
        priority_queue<P, vector<P>, greater<P>> readyQ;
        int ind = 0;

        while(ind < n || !readyQ.empty()) {

            while(ind < n && arr[ind][0] <= time) {
                readyQ.push({arr[ind][1], arr[ind][2]});
                ind++;
            }

            if(readyQ.empty()) {
                time = arr[ind][0];
            }
            else {
                auto cell = readyQ.top();
                readyQ.pop();

                ans.push_back(cell.second);
                time += cell.first;
            }
        }

        return ans;
    }
};