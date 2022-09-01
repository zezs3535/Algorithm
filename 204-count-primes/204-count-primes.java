class Solution {
    public int countPrimes(int n) {
        boolean[] arr = new boolean[n+1]; // 소수 0 아니면 1
        int num = (int)Math.sqrt(n);
        int ans = 0;
        for(int i=2;i<=num;i++){
            for(int j=2;j*i<=n;j++){
                arr[i*j] = true;
            }
        }
        for(int i=2;i<n;i++){
            if(arr[i]==false)ans++;
        }
        return ans;
    }
}