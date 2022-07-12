class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0;
        int n = bank.length;
        int curLaser = 0;
        for(int i=0;i<n;i++){
            int curCnt = 0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i].charAt(j) == '1')curCnt++;
            }
            ans += curCnt*curLaser;
            if(curCnt!=0)curLaser = curCnt;
        }
        return ans;
    }
}