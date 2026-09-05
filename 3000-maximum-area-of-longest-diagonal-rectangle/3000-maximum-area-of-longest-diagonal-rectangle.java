class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int n = dimensions.length;
        int maxDiagonal = 0;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int diagonal = dimensions[i][0] * dimensions[i][0]
                         + dimensions[i][1] * dimensions[i][1];

            int area = dimensions[i][0] * dimensions[i][1];

            if(diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
            else if(diagonal == maxDiagonal) {
                maxArea = Math.max(maxArea, area);
            }
        }

        return maxArea;
    }
}