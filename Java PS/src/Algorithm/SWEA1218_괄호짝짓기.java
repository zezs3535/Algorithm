package Algorithm;

import java.util.Scanner;
import java.util.Stack;

public class SWEA1218_괄호짝짓기 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= 10; t++) {
			boolean isValid = true;
			int n = sc.nextInt();
			Stack<Character> st = new Stack<Character>();
			String s = sc.next();
			for (int i = 0; i < s.length(); i++) {
				if(s.charAt(i)=='('||s.charAt(i)=='{'||s.charAt(i)=='['||s.charAt(i)=='<') {
					st.push(s.charAt(i));
					continue;
				} 
				if(s.charAt(i)==')') {
					if(st.peek()=='(') {
						st.pop();
						continue;
					}
					else {
						isValid=false;
						break;
					}
				}
				if(s.charAt(i)=='}') {
					if(st.peek()=='{') {
						st.pop();
						continue;
					}
					else {
						isValid=false;
						break;
					}
				}
				if(s.charAt(i)==']') {
					if(st.peek()=='[') {
						st.pop();
						continue;
					}
					else {
						isValid=false;
						break;
					}
				}
				if(s.charAt(i)=='>') {
					if(st.peek()=='<') {
						st.pop();
						continue;
					}
					else {
						isValid=false;
						break;
					}
				}
			}
			if(!isValid ||!st.empty()) {
				System.out.println("#"+t+" "+0);
			}
			else {
				System.out.println("#"+t+" "+1);
			}
		}

	}

}
