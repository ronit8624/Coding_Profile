class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxi = 0;

        while(i < j) {
            int dist = j - i;
            int minHeight = min(height[i], height[j]);
            long long area = 1LL * dist * minHeight;
            maxi = max(maxi, (int)area);

            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxi;
    }
};