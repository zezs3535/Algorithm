package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ1987_알파벳 {
	static int n, m;
	static int[][] arr;
	static int[] v = new int[26];
	static int answer = 1;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, 1, 0, -1 };

	static void dfs(int y, int x, int depth) {
		if(answer<depth)answer=depth;
		for(int idx=0; idx<4;idx++) {
			int ny = dy[idx] + y;
			int nx = dx[idx] + x;
			if(ny<0 || nx<0 || ny>=n || nx>=m)continue;
			if(v[arr[ny][nx]]==1)continue;
			v[arr[ny][nx]]=1;
			dfs(ny,nx,depth+1);
			v[arr[ny][nx]]=0;
		}
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
				arr[i][j] = tmp.charAt(j) - 65;
			}
		}
		v[arr[0][0]]=1;
		dfs(0, 0, 1);
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
