package Algorithm;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA1249_보급로 {
	static int n;
	static int[][] arr;
	static int[][] dp;
	static int[] dy = { 0, 1, 0, -1 };
	static int[] dx = { 1, 0, -1, 0 };
	static Queue<Pos> q = new LinkedList<Pos>();

	static class Pos {
		int y;
		int x;
		int value;
		int dir;

		public Pos(int y, int x, int value, int dir) {
			super();
			this.y = y;
			this.x = x;
			this.value = value;
			this.dir = dir;
		}

	}

	static void bfs() {
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			int cy = cur.y;
			int cx = cur.x;
			int cvalue = cur.value;
			int cdir = cur.dir;
			for (int idx = 0; idx < 4; idx++) {
				if ((idx + 2) % 4 == cdir)continue; // 반대방향이면 넘어감
				int ny = cy + dy[idx];
				int nx = cx + dx[idx];
				if(ny>=n || ny<0 || nx>=n || nx<0)continue;
				if(cvalue + arr[ny][nx] < dp[ny][nx]) { //현재 값이랑 다음 배열의 값이 DP배열의 값보다 작으면 갱신
					dp[ny][nx] = cvalue + arr[ny][nx];
					q.add(new Pos(ny,nx,dp[ny][nx],idx));
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for (int test = 1; test <= t; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			arr = new int[n][n];
			dp = new int[n][n];
			for (int i = 0; i < n; i++) {
				String s = br.readLine();
				for (int j = 0; j < n; j++) {
					arr[i][j] = s.charAt(j) - '0';
					dp[i][j] = Integer.MAX_VALUE;
				}
			}
			q.add(new Pos(0, 0, 0, -5));
			bfs();
			System.out.println("#" + test + " " + dp[n - 1][n - 1]);
		}
	}
}
