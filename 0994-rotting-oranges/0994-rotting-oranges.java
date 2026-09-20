class Solution {
    boolean isValid(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.add(new int[] {i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        int time = 0;

        while(!q.isEmpty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                int[] cell = q.poll();
                int row = cell[0];
                int col = cell[1];

                for(int j=0;j<4;j++) {
                    int newRow = row + delRow[j];
                    int newCol = col + delCol[j];

                    if(isValid(newRow, newCol, n, m) &&
                        grid[newRow][newCol] == 1) {
                        
                        fresh--;
                        grid[newRow][newCol] = 2;
                        q.add(new int[] {newRow, newCol});
                    }
                }
            }

            time++;
        }

        if(fresh != 0) return -1;

        return Math.max(0, time - 1);
    }
}