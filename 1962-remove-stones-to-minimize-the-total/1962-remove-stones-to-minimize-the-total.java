class Solution {
    public int minStoneSum(int[] piles, int k) {
        int ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        int n = piles.length;
        for(int i=0;i<n;i++){
            pq.add(piles[i]);
        }
        for(int i=0;i<k;i++){
            int tmp = pq.poll();
            pq.add((int)Math.ceil((double)tmp/2));
        }
        while(!pq.isEmpty()){
            ans += pq.poll();
        }
        return ans;
    }
}