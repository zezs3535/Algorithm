package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA1868_파핑파핑지뢰찾기 {
	static int[][] arr;
	static int n;
	static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
	static int[] dx = { 1, 1, 0, -1, -1, -1, 0, 1 };

	static void print() {
		System.out.println();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			n = sc.nextInt();
			arr = new int[n][n];
			int ans = 0;
			for (int i = 0; i < n; i++) {
				String tmp = sc.next();
				for (int j = 0; j < n; j++) {
					if (tmp.charAt(j) == '*')
						arr[i][j] = 9;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] != 9)
						getNumber(i, j);
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 0) {
						ans++;
						popZero(i, j);
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if(arr[i][j]!=-1 && arr[i][j]!=9)ans++;
				}
			}
			System.out.println("#" + test+" "+ans);
		}
	}

	static void popZero(int i, int j) {
		arr[i][j] = -1;
		for (int idx = 0; idx < 8; idx++) {
			int ny = i + dy[idx];
			int nx = j + dx[idx];
			if (ny >= n || ny < 0 || nx >= n || nx < 0 || arr[ny][nx] == 9)
				continue;
			if (arr[ny][nx] == 0)
				popZero(ny, nx);
			arr[ny][nx] = -1;
		}
	}

	static void getNumber(int i, int j) {
		int cnt = 0;
		for (int idx = 0; idx < 8; idx++) {
			int ny = i + dy[idx];
			int nx = j + dx[idx];
			if (ny >= n || ny < 0 || nx >= n || nx < 0)
				continue;
			if (arr[ny][nx] == 9)
				cnt++;
		}
		arr[i][j] = cnt;
	}
}
