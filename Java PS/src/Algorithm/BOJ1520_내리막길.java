package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ1520_내리막길 {
	static int n, m;
	static int[][] arr;
	static int[][] dp;
	static int[] dy = { 0, 1, 0, -1 };
	static int[] dx = { 1, 0, -1, 0 };

	static int dfs(int y, int x) {
		if (dp[y][x] != -1)return dp[y][x];
		if (y == n - 1 && x == m - 1)return 1;
		dp[y][x]=0;
		for(int dir=0;dir<4;dir++) {
			int ny = dy[dir]+y;
			int nx = dx[dir]+x;
			if(ny<n && ny>=0 && nx<m && nx>=0 && (arr[ny][nx]<arr[y][x])) {
				dp[y][x]+=dfs(ny,nx);
			}
		}
		return dp[y][x];
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		dp = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = -1;
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				bw.write(dp[i][j]+" ");
//			}
//			bw.write("\n");
//		}
		bw.write(dfs(0,0)+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
