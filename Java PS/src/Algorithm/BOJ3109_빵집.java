package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ3109_빵집 {
	static int[][] arr;
	static int[] dy = { -1, 0, 1 };
	static int[] dx = { 1, 1, 1 };
	static int n;
	static int m;
	static int answer = 0;

	static boolean dfs(int i, int j) {
		arr[i][j] = 1;
		if (j == m - 1) {
			answer++;
			return true;
		}
		for (int idx = 0; idx < 3; idx++) { // 우상, 우, 우하로 파이프가 뻗어나감\
			int ny = dy[idx] + i;
			int nx = dx[idx] + j;
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || arr[ny][nx] != 0)
				continue; // 범위 아웃 continue
			
			if(dfs(ny, nx))return true;
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String tmp = st.nextToken();
			for (int j = 0; j < m; j++) {
				if (tmp.charAt(j) == '.')
					arr[i][j] = 0;
				else if (tmp.charAt(j) == 'x')
					arr[i][j] = 9;
			}
		}
		for (int i = 0; i < n; i++) {
			dfs(i, 0);
		}
		bw.write(answer + "");
		br.close();
		bw.flush();
		bw.close();
	}

}
