class Solution {
    
    static int n;
    static int[][] gridNew;
    
    public int fillNum(int[][]grid, int y, int x){
        int xMax = -1;
        int yMax = -1;
        for(int i=y;i<n;i++)yMax = Math.max(yMax,grid[i][x]);
        for(int i=y;i>=0;i--)yMax = Math.max(yMax,grid[i][x]);
        for(int j=x;j<n;j++)xMax = Math.max(xMax,grid[y][j]);
        for(int j=x;j>=0;j--)xMax = Math.max(xMax,grid[y][j]);
        return Math.min(xMax,yMax);
    }
    
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int ans = 0;
        n = grid.length;
        gridNew = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridNew[i][j] = fillNum(grid, i, j);
                ans += Math.abs(gridNew[i][j] - grid[i][j]);
            }
        }
        return ans;
    }
}