class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int ans = 0;
        Arrays.sort(costs);
        for(int i : costs){
            if(i<=coins){
                ans++;
                coins-=i;
            }
        }
        return ans;
    }
}