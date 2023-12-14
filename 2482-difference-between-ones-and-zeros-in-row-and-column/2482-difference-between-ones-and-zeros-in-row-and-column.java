class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int n = grid.length; //column
        int m = grid[0].length; //row
        int[][] diff = new int[n][m];
        
        int[] onesRow = new int[n];
        int[] zerosRow = new int[n];
        
        int[] onesCol = new int[m];
        int[] zerosCol = new int[m];
        
        for(int i=0;i<n;i++){
            int oneCnt=0;
            int zeroCnt=0;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    oneCnt++;
                    onesCol[j]+=1;
                }
                else{
                    zeroCnt++;
                    zerosCol[j]+=1;
                }
            }
            onesRow[i] = oneCnt;
            zerosRow[i] = zeroCnt;
        }
        
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j] = onesRow[i]-zerosRow[i]+onesCol[j]-zerosCol[j];
            }
        }
        
        return diff;
    }
}