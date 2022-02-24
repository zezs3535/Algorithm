package Algorithm;

import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class BOJ1106_호텔 {
	// dp[n] = 고객을 n명 늘릴때 드는 최소 비용

	static class Invest {
		int price = 0;
		int customer = 0;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // 몇명 늘릴건지?
		int t = sc.nextInt(); // 도시의 수
		int best = 0;
		int[] dp = new int[1110]; // 정답 저장할 배열
		Arrays.fill(dp, 999999999);
		Invest[] arr = new Invest[t]; // 홍보비용과 고객수 저장할 배열
		for (int i = 0; i < t; i++) {
			arr[i] = new Invest();
			int p = sc.nextInt(); // 비용
			int c = sc.nextInt(); // 늘어나는 고객 수
			arr[i].price = p;
			arr[i].customer = c;
			dp[c] = Math.min(dp[c], p);
			best = Math.max(best, c);
		}

		for (int i = 1; i <= n + best; i++) {
			for (int j = 0; j < t; j++) {
				if (i - arr[j].customer > 0) { // dp 조건
					dp[i] = Math.min(dp[i], dp[i-arr[j].customer]+arr[j].price);
				}
			}
		}
		
		for(int i=n;i<=n+best;i++) {
			dp[n] = Math.min(dp[n], dp[i]);
		}
		System.out.println(dp[n]);
//		for(int i=1;i<=n + best;i++) {
//			System.out.print(dp[i]+" ");
//		}
	}
}