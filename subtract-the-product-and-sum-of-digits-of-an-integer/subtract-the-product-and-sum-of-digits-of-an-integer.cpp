class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        while(n!=0){
            int v = n%10;
            p*=v;
            s+=v;
            n/=10;
        }
        return p-s;
    }
};