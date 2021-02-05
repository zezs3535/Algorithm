package Algorithm;

import java.util.Scanner;

public class SWEA1861_정사각형방 {
	static int maxDepth;
	static int maxIdx;
	static int n;
	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static class Pos{
		int depth;
		int start;
	}
	static void dfs(int[][] arr, Pos[][] cnt, int i, int j, int depth, int start) {
		for(int idx=0;idx<4;idx++) {
			int ny = i + dy[idx];
			int nx = j + dx[idx];
			if(ny>=n || nx>=n || ny<0 || nx<0)continue;
			if(arr[i][j] == arr[ny][nx]-1) {
				if(depth+1 > cnt[ny][nx].depth) {
					cnt[ny][nx].depth=depth+1;
					dfs(arr,cnt,ny,nx,depth+1,start);
					cnt[ny][nx].start=start;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			n = sc.nextInt();
			int[][] arr = new int[n][n];
			Pos[][] cnt = new Pos[n][n];
			maxDepth = 0;
			maxIdx = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = sc.nextInt();
					cnt[i][j] = new Pos();
					cnt[i][j].start=arr[i][j];
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dfs(arr, cnt, i, j, 0, arr[i][j]);
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(maxDepth<cnt[i][j].depth) {
						maxDepth=cnt[i][j].depth;
						maxIdx=cnt[i][j].start;
					}
					if(maxDepth==cnt[i][j].depth) {
						maxIdx=Math.min(cnt[i][j].start, maxIdx);
					}
				}
			}
			System.out.println("#" + t + " " + maxIdx + " " + (maxDepth+1));

		}

	}

}
