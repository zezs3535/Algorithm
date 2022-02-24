package Algorithm;

import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class BOJ2294_동전2 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] coin = new int[n];
		int[] dp = new int[100001];
		Arrays.fill(dp, 999999999);
		for (int i = 0; i < n; i++) {
			coin[i] = sc.nextInt();
			dp[coin[i]] = 1;
		}
		
		for(int i=1;i<=k;i++) {
			for(int j=0;j<n;j++) {
				if(i-coin[j]>0) {
					dp[i] = Math.min(dp[i], dp[i-coin[j]]+1);
				}
			}
		}
		System.out.println(dp[k] == 999999999?-1:dp[k]);
	}
}
