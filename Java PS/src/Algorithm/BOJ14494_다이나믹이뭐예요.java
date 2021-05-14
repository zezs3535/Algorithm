package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ14494_다이나믹이뭐예요 {
	static int[][] dp;
	static int MOD = (int)1e9+7;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		dp = new int[n][m];
		dp[0][0]=1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(i+1<n) {
					dp[i+1][j]=(dp[i+1][j]%MOD+dp[i][j]%MOD)%MOD;
				}
				if(j+1<m) {
					dp[i][j+1]=(dp[i][j+1]%MOD+dp[i][j]%MOD)%MOD;
				}
				if(i+1<n && j+1<m) {
					dp[i+1][j+1]=(dp[i+1][j+1]%MOD+dp[i][j]%MOD)%MOD;
				}
			}
		}
		bw.write(dp[n-1][m-1]+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
