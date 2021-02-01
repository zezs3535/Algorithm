package Algorithm;

import java.util.Scanner;

public class SWEA1289_원재의메모리복구하기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			String s = sc.next();
			int answer=0;
			int cur=0;
			for (int j = 0; j < s.length(); j++) {
				if(s.charAt(j)=='1') {
					cur=1;
					answer++;
					for(int k=j+1;k<s.length();k++){
						if(s.charAt(k)-'0'!=cur) {
							cur=s.charAt(k)-'0';
							answer++;
						}
					}
					break;
				}
			} 
			System.out.println("#" + i + " " + answer);
		}
	}
}
