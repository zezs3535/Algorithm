class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList<Integer> arr = new ArrayList<>();
        int n = nums.length;
        int[] ans = new int[n];
        for(int i=0;i<n;i++){
            arr.add(index[i],nums[i]);
        }
        int i = 0;
        for(Integer it : arr){
            ans[i] = it;
            i++;
        }
        return ans;
    }
}