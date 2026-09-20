class Solution {
    boolean isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int cnt = 0;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        boolean[][] vis = new boolean[n][m];
        for(int i=0;i<n;i++) {
            Arrays.fill(vis[i], false);
        }

        Queue<int[]> q = new LinkedList<>();

        q.add(new int[]{1, 0, 0});
        vis[0][0] = true;

        while(!q.isEmpty()) {
            int[] cell = q.poll();
            int dist = cell[0];
            int row = cell[1];
            int col = cell[2];

            if(row == n-1 && col == n-1) return dist;

            for(int i=-1;i<=1;i++) {
                for(int j=-1;j<=1;j++) {
                    int newRow = row + i;
                    int newCol = col + j;

                    if(isValid(newRow, newCol, n, m) &&
                        !vis[newRow][newCol] &&
                        grid[newRow][newCol] == 0) {
                        
                        vis[newRow][newCol] = true;
                        q.add(new int[] {dist + 1, newRow, newCol});
                    }
                }
            }
        }

        return -1;
    }
}