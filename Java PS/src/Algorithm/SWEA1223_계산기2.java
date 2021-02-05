package Algorithm;

import java.util.Scanner;
import java.util.Stack;

public class SWEA1223_계산기2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= 10; t++) {
			int n = sc.nextInt();
			String s = sc.next();
			Stack<Integer> st = new Stack<Integer>();
			Stack<Character> st2 = new Stack<Character>();
			for(int i=0;i<n;i++) {
				if(s.charAt(i)>='0' && s.charAt(i)<='9') {
					st.push(s.charAt(i)-'0');
				}
				else if(s.charAt(i)=='+') {
					st2.push(s.charAt(i));
				}
				else if(s.charAt(i)=='*') {
					int tmp = st.pop();
					st.push(tmp*(s.charAt(i+1)-'0'));
					i++;
				}
			}
			while(!st2.empty()) {
				st2.pop();
				int tmp = st.pop();
				int tmp2 = st.pop();
				st.push(tmp+tmp2);
				
			}
			System.out.println("#"+t+" "+st.pop());
		}

	}

}
