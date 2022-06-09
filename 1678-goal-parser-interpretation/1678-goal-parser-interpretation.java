class Solution {
    public String interpret(String command) {
        String ans = "";
        int n = command.length();
        for(int i=0;i<n;i++){
            if(command.charAt(i) == '('){
                if(command.charAt(i+1) == ')'){
                    ans+="o";
                    i++;
                    continue;
                }
                if(command.charAt(i+1) == 'a'){
                    ans+="al";
                    i+=2;
                    continue;
                }
            }
            else if(command.charAt(i) == 'G'){
                ans+='G';
            }
        }
        return ans;
    }
}