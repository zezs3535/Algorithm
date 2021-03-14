package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ14502_연구소 {
	static int[] dy = { 0, 1, 0, -1 };
	static int[] dx = { 1, 0, -1, 0 };
	static int answer = 0;
	static int n, m;
	static int[][] arr;
	static Queue<Pos> virus = new LinkedList<>();

	static class Pos {
		int y;
		int x;

		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}

	}

	static int bfs(int[][] copyarr) {
		int cnt = 0;
		Queue<Pos> tmp = new LinkedList<>();
		Pos cur;
		for (int i = 0; i < virus.size(); i++) {
			cur = virus.poll();
			tmp.add(cur);
			virus.add(cur);
		}
		while (!tmp.isEmpty()) {
			cur = tmp.poll();
			for (int idx = 0; idx < 4; idx++) {
				int ny = cur.y + dy[idx];
				int nx = cur.x + dx[idx];
				if (ny >= n || nx >= m || ny < 0 || nx < 0 || copyarr[ny][nx] != 0)
					continue;
				tmp.add(new Pos(ny, nx));
				copyarr[ny][nx] = 2;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copyarr[i][j] == 0) {
					cnt++;
				}
			}
		}
		return cnt;
	}

	static void makeWall(int[][] copyarr, int wallcnt) {
		if (wallcnt == 3) {
			int[][] ccopyarr = new int[n][m];
			for(int i=0;i<n;i++)ccopyarr[i] = copyarr[i].clone();
			answer = Math.max(answer, bfs(ccopyarr));
			return;
		} else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (copyarr[i][j] == 0) {
						copyarr[i][j] = 1;
						makeWall(copyarr, wallcnt + 1);
						copyarr[i][j] = 0;
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		int[][] copyarr = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 2)
					virus.add(new Pos(i, j));
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				copyarr[i][j] = arr[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					copyarr[i][j] = 1;
					makeWall(copyarr, 1);
					copyarr[i][j] = 0;
				}
			}
		}
		bw.write(answer + "");
		br.close();
		bw.flush();
		bw.close();
	}
}
