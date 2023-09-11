import java.util.*;

class Solution {
    
    static class Pos{
        int val;
        int idx;
        
        Pos(int val, int idx){
            this.val = val;
            this.idx = idx;
        }
    }
    
    public List<List<Integer>> groupThePeople(int[] arr) {
        List<List<Integer>> ans = new LinkedList<>();
        int n = arr.length;
        Pos[] pos = new Pos[n];
        for(int i=0;i<n;i++){
            pos[i] = new Pos(arr[i],i);
        }
        
        Arrays.sort(pos, new Comparator<Pos>(){
            @Override
            public int compare(Pos o1, Pos o2){
                return Integer.compare(o1.val, o2.val);
            }
        });
        
        for(int i=0;i<n;){
            int cnt = pos[i].val;
            List<Integer> tmp = new LinkedList<>();
            for(int j=0;j<cnt;j++){
                tmp.add(pos[i+j].idx);
            }
            i+=cnt;
            ans.add(tmp);
        }
        
        return ans;
    }
}