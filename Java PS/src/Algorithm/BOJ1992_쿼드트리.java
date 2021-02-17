package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1992_쿼드트리 {
	static StringBuilder sb;
	static int[][] arr;
	static int n;

	static void go(int sy, int sx, int size) {

		int key = arr[sy][sx];
		boolean flag = true;
		for (int i = sy; i < sy + size; i++) {
			for (int j = sx; j < sx + size; j++) {
				if (key != arr[i][j]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			if (key == 1) {
				sb.append("1");
			} else {
				sb.append("0");
			}
		} else {
			sb.append("(");
			int half = size / 2;
			go(sy, sx, half);
			go(sy, sx + half, half);
			go(sy + half, sx, half);
			go(sy + half, sx + half, half);
			sb.append(")");
		}

	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		sb = new StringBuilder();

		n = Integer.parseInt(st.nextToken());
		arr = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			for (int j = 0; j < n; j++) {
				arr[i][j] = s.charAt(j) - '0';
			}
		}
		go(0, 0, n);
		bw.write(sb.toString());
		br.close();
		bw.flush();
		bw.close();
	}
}
