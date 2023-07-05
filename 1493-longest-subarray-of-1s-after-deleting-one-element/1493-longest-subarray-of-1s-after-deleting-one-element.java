import java.util.*;

class Solution {
    public int longestSubarray(int[] nums) {
        ArrayList<Integer> li = new ArrayList<>();
        int sum = 0;
        for(int i : nums){
            if(i == 0){
                if(sum>0)li.add(sum);
                li.add(0);
                sum = 0;
            }
            else{
                sum+=i;
            }
        }
        
        if(sum>0)li.add(sum);
        
        int[] arr = new int[li.size()];
        int idx = 0;
        
        for(int i : li){
            arr[idx++] = i;
        }
        
        int answer = 0;
        
        if(arr.length == 1){
            if(arr[0] != 0)return arr[0]-1;
            return arr[0];
        }
        if(arr.length == 2)return arr[0]+arr[1];
        
        for(int i=0;i<arr.length-2;i++){
            answer = Math.max(arr[i]+arr[i+1]+arr[i+2],answer);
        }
        
        
        
        return answer;
    }
}