class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
        int[] ans = new int[1001];
        for(int i : arr){
            if(m.containsKey(i)){ //exist
                int tmp = m.get(i);
                m.put(i,++tmp);
            }else{ //non exits
                m.put(i,1);
            }
        }
        
        for(int key : m.keySet()){
                if(ans[m.get(key)]==1)return false;
                ans[m.get(key)] = 1;
            }
        return true;
    }
}