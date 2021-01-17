package Algorithm;

import java.util.Scanner;

public class SWEA1945_간단한소인수분해 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			int answer=0;
			int n = sc.nextInt();
			int[] cnt=new int[5];
			while(n!=1) {
				while(n%2==0) {
					n/=2;
					cnt[0]++;
				}
				while(n%3==0) {
					n/=3;
					cnt[1]++;
				}
				while(n%5==0) {
					n/=5;
					cnt[2]++;
				}
				while(n%7==0) {
					n/=7;
					cnt[3]++;
				}
				while(n%11==0) {
					n/=11;
					cnt[4]++;
				}
			}
			System.out.println("#"+t+" "+cnt[0]+" "+cnt[1]+" "+cnt[2]+" "+cnt[3]+" "+cnt[4]);
		}
	}
}
