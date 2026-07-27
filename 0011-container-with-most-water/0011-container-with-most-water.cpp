class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int maxi = INT_MIN;

        while(l < r) {
            int _height = min(height[l], height[r]);
            int width = r - l;
            long long area = _height * width;

            maxi = max(maxi, (int) area);

            if(height[l] < height[r]) l++;
            else r--;
        }

        return maxi;
    }
};