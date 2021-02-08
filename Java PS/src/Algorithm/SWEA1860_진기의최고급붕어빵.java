package Algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA1860_진기의최고급붕어빵 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			int[] customer = new int[n];
			for (int i = 0; i < n; i++) {
				customer[i] = sc.nextInt();
			}
			Arrays.sort(customer);
			int time = customer[n - 1];
			int bread = 0;
			int timecnt = -1;
			int cuscnt=0;
			boolean flag=true;
			for (int i = 0; i <= time; i++) {
				timecnt++;
				if(timecnt==m) {
					bread+=k;
					timecnt=0;
				}
				while(cuscnt<n && customer[cuscnt]==i) {
					if(bread>0) {
						bread--;
						cuscnt++;
					}
					else {
						flag=false;
						break;
					}
				}
				if(cuscnt==n)break;
			}
			if(flag)System.out.println("#"+test+" Possible");
			else if(!flag)System.out.println("#"+test+" Impossible");
		}

	}

}
