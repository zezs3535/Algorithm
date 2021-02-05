package Algorithm;

import java.util.Scanner;

public class SWEA3499_퍼펙트셔플 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int n = sc.nextInt();
			sc.nextLine();
			String[] s = new String[n];
			for(int i=0;i<n;i++) {
				s[i]=new String();
				s[i]=sc.next();
			}
			System.out.print("#"+test+" ");
			if(n%2==0) {
				for(int i=0;i<n/2;i++) {
					System.out.print(s[i]+" ");
					System.out.print(s[i+n/2]+" ");
				}
				System.out.println();
			}
			else {
				for(int i=0;i<n/2;i++) {
					System.out.print(s[i]+" ");
					System.out.print(s[i+(n/2+1)]+" ");
				}
				System.out.print(s[n/2]);
				System.out.println();
			}
			//System.out.println("#" + test + " " + answer);
		}

	}

}
