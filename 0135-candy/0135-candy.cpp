class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;

        while(i < n) {
            // flat surface
            if(ratings[i] == ratings[i-1]) {
                sum++;
                i++; 
                continue;
            }

            // upward slope
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]) {
                peak++;
                sum += peak;
                i++;
            }

            // downward slope
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]) {
                sum += down;
                down++;
                i++;
            }

            if(down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};