import java.util.*;

class Solution {
    public int findDuplicate(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        int ans = 0;
        for(int i : nums){
            if(hs.contains(i)){
                ans = i;
                break;
            }else{
                hs.add(i);
            }
        }
        
        return ans;
    }
}