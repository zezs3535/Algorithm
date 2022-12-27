class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = rocks.length;
        int ans = 0;
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = capacity[i] - rocks[i];
        }
        Arrays.sort(arr);
        for(int i=0;i<n;i++){
            if(arr[i]==0){ //already full
                ans++;
            }else{
                if(additionalRocks >= arr[i]){
                     additionalRocks -= arr[i];
                    ans++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
}