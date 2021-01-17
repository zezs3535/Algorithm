package Algorithm;

import java.util.Scanner;

public class SWEA1288_새로운불면증치료법 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int a = 0;
			int n = sc.nextInt();
			int answer=0;
			int cnt=n;
			while(a!=1023) {
				answer++;
				int num=n;
				while(num>0) {
					a|=(1<<(num%10));
					num/=10;
				}
				if(a==1023)break;
				n=n+cnt;
			}
			System.out.println("#" + (i + 1) + " "+n);
		}
	}
}
