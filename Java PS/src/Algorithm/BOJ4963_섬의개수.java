package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ4963_섬의개수 {
	static int n;
	static int m;
	static int[][] arr;
	static boolean[][] v;
	static int[] dy = { 1, 1, 1, 0, -1, -1, -1, 0 };
	static int[] dx = { 1, 0, -1, -1, -1, 0, 1, 1 };

	static void dfs(int y, int x) {
		for(int idx=0;idx<8;idx++) {
			int ny = y + dy[idx];
			int nx = x + dx[idx];
			if(ny>=n || ny<0 || nx>=m || nx<0)continue;
			if(arr[ny][nx]==0 || v[ny][nx])continue;
			v[ny][nx]=true;
			dfs(ny,nx);
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		do {
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			int answer = 0;
			if (n == 0 && m == 0)
				break;
			arr = new int[n][m];
			v = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < m; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!v[i][j] && arr[i][j] == 1) {
						answer++;
						v[i][j] = true;
						dfs(i, j);
					}
				}
			}
			bw.write(answer + "\n");
		} while (true);

		br.close();
		bw.flush();
		bw.close();
	}
}
