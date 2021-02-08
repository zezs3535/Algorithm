package Algorithm;

import java.util.Scanner;

public class SWEA9229_한빈이와SpotMart {

	static int[] snack;
	static int[] sel = new int[2];
	static int answer;
	static int weight;
	static int n;
	static void comb(int idx, int k) {
		if(k==2) {
			int sum = sel[0]+sel[1];
			if(sum==weight) {
				answer=sum;
				return;
			}
			if(sum>weight)return;
			answer = Math.max(answer, sum);
			return;
		}
		if(idx==n)return;
		sel[k]=snack[idx];
		comb(idx+1,k+1);
		comb(idx+1,k);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			answer=0;
			n = sc.nextInt();
			weight = sc.nextInt();
			snack = new int[n];
			for (int i = 0; i < n; i++) {
				snack[i] = sc.nextInt();
			}
			comb(0,0);
			if(answer==0)System.out.println("#"+test+" -1");
			else {
				System.out.println("#"+test+" "+answer);
			}
		}

	}

}
