package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA1263_사람네트워크2 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int n = sc.nextInt();
			int[][] adj = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					adj[i][j] = sc.nextInt();
				}
			}
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j)
							continue;
						else if (adj[i][k] != 0 && adj[k][j] != 0) {
							if (adj[i][j] == 0)
								adj[i][j] = adj[i][k] + adj[k][j];
							else {
								adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
							}
						}
					}
				}
			}
			int answer = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				int cnt = 0;
				for (int j = 0; j < n; j++) {
					cnt += adj[i][j];
				}
				answer = Math.min(answer, cnt);
			}
			System.out.println("#" + test + " " + answer);
		}
	}
}
