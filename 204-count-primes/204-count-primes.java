class Solution {
    public int countPrimes(int n) {
        int[] arr = new int[n+1]; // 소수 0 아니면 1
        int num = (int)Math.sqrt(n);
        int ans = 0;
        if(n>=2){
            arr[0] = 1;
            arr[1] = 1;
        }
        for(int i=2;i<=num;i++){
            for(int j=2;j*i<=n;j++){
                arr[i*j] = 1;
            }
        }
        for(int i=2;i<n;i++){
            if(arr[i]==0)ans++;
        }
        return ans;
    }
}