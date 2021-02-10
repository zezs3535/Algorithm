package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ16926_배열돌리기1 {
	static int[][] arr;
	static int n, m, r;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, 1, 0, -1 };

	static void rotate(int start) {
		for (int i = 0; i < start; i++) {
			int nextValue = arr[i][i];
			int y = i;
			int x = i;
			arr[i][i] = 0;
			int dir = 0;
			int tmp = 0;
			while (true) {
				if (dir == 0 && y == n - 1 - i && x == i) {
					dir = 1;
				} else if (dir == 1 && y == n - 1 - i && x == m - 1 - i) {
					dir = 2;
				} else if (dir == 2 && y == i && x == m - 1 - i) {
					dir = 3;
				} else if (dir == 3 && y == i && x == i) {
					dir = 0;
				}
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = tmp;
					break;
				}
				tmp = arr[ny][nx];
				arr[ny][nx] = nextValue;
				nextValue = tmp;
				y = ny;
				x = nx;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int k = 0; k < r; k++) {
			rotate(Math.min(n, m) / 2);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bw.write(arr[i][j] + " ");
			}
			bw.write("\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
