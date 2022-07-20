class Solution {
    public List<Integer> luckyNumbers (int[][] arr) {
        List<Integer> ans = new ArrayList<Integer>();
        int n = arr.length;
        int m = arr[0].length;
        for(int i=0;i<n;i++){
            int minNumInRow = 2147483647;
            int minNumIdx = 0;
            for(int j=0;j<m;j++){
                if(arr[i][j] < minNumInRow){
                    minNumIdx = j;
                    minNumInRow = arr[i][j];
                }
            }
            
            int chk = minNumInRow;
            
            for(int k=0;k<n;k++){
                chk = Math.max(chk,arr[k][minNumIdx]);
            }
            
            if(chk == minNumInRow)ans.add(minNumInRow);
        }
        return ans;
    }
}