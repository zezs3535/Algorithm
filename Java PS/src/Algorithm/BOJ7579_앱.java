package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ7579_앱 {
	static int[] m;
	static int[] c;
	static int[] dp;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		m = new int[N+1];
		c = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			m[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			c[i] = Integer.parseInt(st.nextToken());
		}
		int total = 0;
		for (int i = 0; i < N; i++) {
			total += c[i];
		}
		dp = new int[total+1];
		for (int i = 0; i < N; i++) {
			for (int j = total; j >= c[i]; j--) {
				dp[j] = Math.max(dp[j], dp[j-c[i]]+m[i]);
			}
		}
		int ans=0;
		for(int i=total;i>=0;i--) {
			if(dp[i]>=M)ans=i;
		}
		bw.write(ans+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
