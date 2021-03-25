package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA3307_최장증가부분수열 {
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			int[] dp = new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
				dp[i]=1;
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<i;j++) {
					if(arr[i]>arr[j]) {
						dp[i]=Math.max(dp[i], dp[j]+1);
					}
				}
			}
			int answer=0;
			for(int i=0;i<n;i++) {
				answer=Math.max(answer, dp[i]);
			}
			System.out.println("#"+test+" "+answer);
		}
	}
}
