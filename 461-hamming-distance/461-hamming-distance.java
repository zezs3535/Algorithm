class Solution {
    public int hammingDistance(int x, int y) {
        int cnt = 0;
        int tmp = 1;
        for(int i=0;i<32;i++){
            if((x & tmp) != (y & tmp)){
                cnt++;
            }
            tmp <<= 1;
        }
        return cnt;
    }
}