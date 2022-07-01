class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (int[] a, int[] b) -> Integer.compare(b[1],a[1]));
        int ans = 0;
        for(int i=0;i<boxTypes.length;i++){
            if(truckSize == 0)break;
            int cnt = 0;
            if(truckSize>=boxTypes[i][0]){ //can load
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }
        return ans;
    }
}