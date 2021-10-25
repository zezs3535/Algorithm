class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(char i : stones){
            for(char j : jewels){
                if(i==j)ans++;
            }
        }
        return ans;
    }
};