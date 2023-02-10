class Solution {
    
    static int n;
    
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    
    static class Pos{
        int y;
        int x;
        
        Pos(int y, int x){
            this.y = y;
            this.x = x;
        }
        
    }
    
    public int maxDistance(int[][] grid) {
        int ans = -1;
        n = grid.length;
        
        Queue<Pos> q = new LinkedList<>();
        int[][] tmp = new int [n][n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)q.add(new Pos(i,j));
                else{
                    tmp[i][j] = 999999;
                }
            }
        }
        
        int cnt = 1;
        
        while(!q.isEmpty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                Pos pos = q.poll();
                for(int idx=0;idx<4;idx++){
                    int ny = pos.y + dy[idx];
                    int nx = pos.x + dx[idx];
                    if(ny>=n || nx>=n || ny<0 || nx<0 || tmp[ny][nx] <= cnt)continue;
                    tmp[ny][nx] = cnt;
                    q.add(new Pos(ny,nx));
                    ans = Math.max(ans,cnt);
                }
            }
            cnt++;
        }
        
        return ans;
    }
    
    
}