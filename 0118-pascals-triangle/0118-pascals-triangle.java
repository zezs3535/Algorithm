class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new LinkedList<>();
        ans.add(new LinkedList<>());
        ans.get(0).add(1);
        
        for(int i=1;i<numRows;i++){
            ans.add(new LinkedList<>());
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)ans.get(i).add(1);
                else{
                    ans.get(i).add(ans.get(i-1).get(j-1)+ans.get(i-1).get(j));
                }
            }
        }
        
        return ans;
    }
}