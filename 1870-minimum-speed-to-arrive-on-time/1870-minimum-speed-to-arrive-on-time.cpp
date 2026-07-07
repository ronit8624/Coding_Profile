class Solution {
public:
    double f(vector<int>& dist, int n, int speed) {
        double time = 0;

        for(int i = 0; i < n - 1; i++) {
            time += ceil((double)dist[i] / speed);
        }

        time += (double)dist[n - 1] / speed;

        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        int low = 1;
        int high = 1e7;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            double totalTime = f(dist, n, mid);

            if(totalTime <= hour) {
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