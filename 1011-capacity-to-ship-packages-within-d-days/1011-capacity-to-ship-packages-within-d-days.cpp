class Solution {
public:
    int f(vector<int>& weights, int n, int capacity) {
        int days = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(sum + weights[i] <= capacity) {
                sum += weights[i];
            }
            else {
                days++;
                sum = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int requiredDays = f(weights, n, mid);

            if(requiredDays <= days) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};