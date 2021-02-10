package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ17406_배열돌리기4 {
	static int[][] arr;
	static int n, m, k;
	static Ins[] ins;
	static int[] sel;
	static boolean[] vis;
	static int answer = Integer.MAX_VALUE;
	static int[] dy = { 0, 1, 0, -1 };
	static int[] dx = { 1, 0, -1, 0 };

	static class Ins {
		int r;
		int c;
		int s;

		Ins() {

		}

		Ins(int r, int c, int s) {
			this.r = r;
			this.c = c;
			this.s = s;
		}
	}

	static void permu(int pick) {
		if (pick == k) { // 완성된 연산 순열을 넘긴다
			int sum = opIns(sel);
			answer = Math.min(answer, sum);
			return;
		}
		for (int i = 0; i < k; i++) {
			if (!vis[i]) {
				vis[i] = true;
				sel[pick] = i;
				permu(pick + 1);
				vis[i] = false;
			}
		}
	}

	static int opIns(int[] sel) { // 연산 순서를 넘김 ex) 0,1 or 1,0
		int sum = Integer.MAX_VALUE;
		int[][] tmp = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				tmp[i][j]=arr[i][j];
			}
		}
		for (int i = 0; i < k; i++) {
			rotate(ins[sel[i]], tmp);
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				cnt += tmp[i][j];
			}
			sum = Math.min(sum, cnt);
		}
		return sum;
	}

	static void rotate(Ins sel, int[][] tmp) {
		for (int i = 0; i < sel.s; i++) { // 시작이 r-s,c-s 끝이 r+s,c+s
			int starty = sel.r - sel.s + i;
			int startx = sel.c - sel.s + i;
			int endy = sel.r + sel.s - i;
			int endx = sel.c + sel.s - i;
			int nextValue = tmp[starty][startx];
			int y = starty;
			int x = startx;
			tmp[starty][startx] = 0;
			int dir = 0;
			int tmpnum = 0;
			while (true) {
				if (dir == 0 && y == starty && x == endx) {
					dir = 1;
				} else if (dir == 1 && y == endy && x == endx) {
					dir = 2;
				} else if (dir == 2 && y == endy && x == startx) {
					dir = 3;
				} else if (dir == 3 && y == starty && x == startx) {
					dir = 0;
				}
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (tmp[ny][nx] == 0) {
					tmp[ny][nx] = tmpnum;
					break;
				}
				tmpnum = tmp[ny][nx];
				tmp[ny][nx] = nextValue;
				nextValue = tmpnum;
				y = ny;
				x = nx;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		//System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		ins = new Ins[k];
		sel = new int[k];
		vis = new boolean[k];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int r, c, s;
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			ins[i] = new Ins(r - 1, c - 1, s);
		}
		permu(0);
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}

}
