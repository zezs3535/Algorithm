package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ2146_다리만들기 {
	static int n;
	static int[][] arr;
	static boolean[][] v;
	static int answer = Integer.MAX_VALUE;
	static int[] dy = { 0, 1, 0, -1 };
	static int[] dx = { 1, 0, -1, 0 };

	static class Pos {
		int y;
		int x;
		int cnt;
		Pos() {

		}

		public Pos(int y, int x, int cnt) {
			super();
			this.y = y;
			this.x = x;
			this.cnt = cnt;
		}

	}

	static void bfs(int y, int x) {
		Queue<Pos> q = new LinkedList<>();
		Queue<Pos> edge = new LinkedList<>();
		Queue<Pos> edgeBfs = new LinkedList<>();
		q.add(new Pos(y, x, 0));
		while (!q.isEmpty()) {
			Pos cpos = q.poll();
			for (int idx = 0; idx < 4; idx++) {
				int ny = dy[idx] + cpos.y;
				int nx = dx[idx] + cpos.x;
				if (ny >= n || nx >= n || ny < 0 || nx < 0)
					continue;
				if (v[ny][nx])
					continue;
				if (arr[ny][nx] == 0) {
					v[ny][nx] = true;
					edge.add(new Pos(ny, nx, 1));
					continue;
				}
				v[ny][nx] = true;
				q.add(new Pos(ny, nx, 0));
			}
		}
		while (!edge.isEmpty()) {
			edgeBfs.add(edge.poll());
			boolean[][] vv = new boolean[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					vv[i][j]=v[i][j];
				}
			}
			while (!edgeBfs.isEmpty()) {
				Pos cpos = edgeBfs.poll();
				for (int idx = 0; idx < 4; idx++) {
					int ny = dy[idx] + cpos.y;
					int nx = dx[idx] + cpos.x;
					if (ny >= n || nx >= n || ny < 0 || nx < 0)
						continue;
					if (vv[ny][nx])
						continue;
					if(arr[ny][nx]==1 && !vv[ny][nx]) {
						answer = Math.min(answer, cpos.cnt);
						while(!edgeBfs.isEmpty())edgeBfs.poll();
						break;
					}
					vv[ny][nx]=true;
					edgeBfs.add(new Pos(ny,nx,cpos.cnt+1));
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n][n];
		v = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && !v[i][j]) {
					v[i][j] = true;
					bfs(i, j);
				}
			}
		}
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
