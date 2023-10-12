class Solution {
    public int integerBreak(int n) {
        
        if(n==2)return 1;
        if(n==3)return 2;
        
        int threeCnt = n/3;
        int na = n%3;
        int answer = 0;
        if(na==0)answer = (int)Math.pow(3,threeCnt);
        else if(na==1)answer = (int)Math.pow(3,threeCnt-1)*4;
        else if(na==2)answer = (int)Math.pow(3,threeCnt)*2;
        
        return answer;
    }
}