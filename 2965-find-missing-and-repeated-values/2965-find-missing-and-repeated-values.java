class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int m = grid.length;
        int n = m * m;

        long sn = 1L * n * (n + 1) / 2;
        long s2n = 1L * n * (n + 1) * (2 * n + 1) / 6;

        long s = 0, s2 = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                s += grid[i][j];
                s2 += (grid[i][j] * grid[i][j]);
            }
        }

        long val1 = sn - s;
        long val2 = s2n - s2;

        val2 = val2 / val1;

        long x = (val1 + val2) / 2;
        long y = x - val1;

        return new int[] {(int)y, (int)x};
    }
}