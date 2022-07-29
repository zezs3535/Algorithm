class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int cnt = 0;
        int[][] arr = new int[m][n];
        
        for(int[] a : indices){
            int row = a[0];
            int col = a[1];
            
            for(int i=0;i<n;i++){
                arr[row][i] += 1;
            }
            
            for(int i=0;i<m;i++){
                arr[i][col] += 1;
            }
            
            }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] % 2 == 1)cnt++;
            }
        }
        return cnt;
    }
}