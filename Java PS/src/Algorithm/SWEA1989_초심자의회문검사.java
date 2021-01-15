package Algorithm;

import java.util.Scanner;

public class SWEA1989_초심자의회문검사 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 0; t < test; t++) {
			int answer = 0;
			boolean flag=true;
			String s = sc.next();
			for (int i = 0; i < s.length()/2; i++) {
				if(s.charAt(i)!=s.charAt(s.length()-1-i)){
					flag=false;
					break;
				}
			}
			System.out.println("#" + (t + 1) + " " + (flag?1:0));
		}
	}
}
