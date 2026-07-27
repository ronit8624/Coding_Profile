class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int lMax = 0, rMax = 0, total = 0;

        while(l < r) {
            if(height[l] <= height[r]) {
                if(height[l] < lMax) {
                    total += (lMax - height[l]);
                }
                else {
                    lMax = height[l];
                }
                l++;
            }
            else {
                if(height[r] < rMax) {
                    total += (rMax - height[r]);
                }
                else {
                    rMax = height[r];
                }
                r--;
            }
        }

        return total;
    }
};