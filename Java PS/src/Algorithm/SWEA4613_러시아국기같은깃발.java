package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA4613_러시아국기같은깃발 {

	static int getColor(int[][] arr, int start, int end, int curColor) {
		int cnt = 0;
		if (curColor == 0) { // white
			for (int i = 0; i < end; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					if (curColor != arr[i][j])
						cnt++;
				}
			}
		} else if (curColor == 1) { // blue
			for (int i = start; i <=end; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					if (curColor != arr[i][j])
						cnt++;
				}
			}
		} else { // red
			for (int i = start + 1; i < arr.length; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					if (curColor != arr[i][j])
						cnt++;
				}
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for (int test = 1; test <= t; test++) {
			int answer = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int[][] arr = new int[n][m];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				String s = st.nextToken();
				for (int j = 0; j < m; j++) { // 흰색 0 파란색 1 빨간색 2
					if (s.charAt(j) == 'W')
						arr[i][j] = 0;
					else if (s.charAt(j) == 'B')
						arr[i][j] = 1;
					else {
						arr[i][j] = 2;
					}
				}
			}
			for (int i = 1; i < n - 1; i++) {
				for (int j = i; j < n - 1; j++) {
					int cnt = 0;
					cnt += getColor(arr, 0, i, 0); // 0~i white
					cnt += getColor(arr, i, j, 1); // i blue
					cnt += getColor(arr, j, n, 2); // i+1~n
					answer = Math.min(answer, cnt);
				}
			}
			bw.write("#" + test + " " + answer + "\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
