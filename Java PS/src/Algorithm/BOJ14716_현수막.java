package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ14716_현수막 {

	static int n;
	static int m;
	static int[][] arr;
	static int[] dy = {1,1,0,-1,-1,-1,0,1};
	static int[] dx = {0,-1,-1,-1,0,1,1,1};
	
	static void bfs(int y, int x) {
		for(int idx=0;idx<8;idx++) {
			int ny = y + dy[idx];
			int nx = x + dx[idx];
			if(ny>=n || ny<0 || nx>=m || nx<0 || arr[ny][nx]!=1)continue;
			arr[ny][nx]=2;
			bfs(ny,nx);
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		arr = new int[n][m];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(arr[i][j] == 1) {
					ans++;
					bfs(i,j);
				}
			}
		}
		System.out.println(ans);
	}
}
