class Solution {
    
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    static int n;
    static int m;
    
    
    public int countBattleships(char[][] board) {
        n = board.length;
        m = board[0].length;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X'){
                    ans++;
                    dfs(board, i, j);
                }
            }
        }
        return ans;
    }
    
    public void dfs(char[][] board, int y, int x){
        board[y][x] = '.';
        for(int idx=0;idx<4;idx++){
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if(ny>=n || nx>=m || ny<0 || nx<0 || board[ny][nx] == '.')continue;
            dfs(board,ny,nx);
        }
    }
}