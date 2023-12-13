class Solution {
    
    public int check(int[][] arr, int posN, int posM, int n, int m){
        boolean gaChk = false;
        boolean seChk = false;
        for(int i=0;i<m;i++){
            if(arr[posN][i]==1){
                if(gaChk){
                    return 0;
                }else{
                    gaChk = true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i][posM]==1){
                if(seChk){
                    return 0;
                }else{
                    seChk=true;
                }
            }
        }
        if(gaChk&&seChk)return 1;
        else{
            return 0;
        }
    }
    
    public int numSpecial(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1)ans += check(arr,i,j,n,m);
            }
        }
        
        return ans;
    }
}