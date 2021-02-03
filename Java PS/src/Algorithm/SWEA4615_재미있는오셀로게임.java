package Algorithm;

import java.util.Scanner;

public class SWEA4615_재미있는오셀로게임 {
	static int dx[] = {1,1,0,-1,-1,-1,0,1};
	static int dy[] = {0,1,1,1,0,-1,-1,-1};
	static int n;
	static int bl=0, wh=0;
	static void go(int[][] arr, int y, int x) {
		int curColor = arr[y][x];
		for(int idx=0;idx<8;idx++) {
			int cnt=1;
			boolean flag = false;
			while(true) {
				int ny = y + dy[idx] * cnt;
				int nx = x + dx[idx] * cnt;
				if(ny>=n || ny<0 || nx>=n || nx<0)break;
				if(arr[ny][nx]==0)break;
				if(arr[ny][nx]!=curColor)continue;
				cnt++;
				if(arr[ny][nx]==curColor) {
					flag=true;
					cnt--;
					break;
				}
			} 
			if(flag) {
				for(int i=1;i<=cnt;i++) {
					int ny = y + dy[idx] * cnt;
					int nx = x + dx[idx] * cnt;
					//System.out.println(ny + " " + nx);
					//System.out.println(arr[ny][nx]);
					arr[ny][nx] = curColor;
				}
			}
		}
	}
	
	static void count(int[][] arr) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(arr[i][j]==1)bl++;
				else if(arr[i][j]==2)wh++;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			n = sc.nextInt();
			int m = sc.nextInt();
			int[][] arr = new int[n][n];
			bl=0;
			wh=0;
			for(int i=0;i<m;i++) {
				int q = sc.nextInt();
				int w = sc.nextInt();
				arr[q-1][w-1] = sc.nextInt();
				if(arr[q-1][w-1]==0)continue;
				go(arr,q-1,w-1);
			}
			count(arr);
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					System.out.print(arr[i][j]);
				}
				System.out.println();
			}
			System.out.println("#" + test + " " + bl + " " + wh);
		}
	}
}
