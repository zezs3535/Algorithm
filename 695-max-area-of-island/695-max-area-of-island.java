class Solution {
    static int ans;
    static int cnt;
    static int n, m;
    static int[][] arr;
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    
    public void bfs(int y, int x){
        arr[y][x] = 0;
        cnt++;
        for(int idx=0;idx<4;idx++){
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if(ny>=n || ny<0 || nx>= m || nx<0 || arr[ny][nx] == 0)continue;
            arr[ny][nx]=0;
            bfs(ny,nx);
        }
        ans = Math.max(cnt,ans);
    }
    
    public int maxAreaOfIsland(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        arr = new int[n][m];
        ans=0;
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = grid[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1){
                    
                    cnt = 0;
                    bfs(i,j);
                }
            }
        }
        
        return ans;
    }
}