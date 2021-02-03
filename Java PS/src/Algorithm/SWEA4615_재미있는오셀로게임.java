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
				if(arr[ny][nx]!=curColor) {
					cnt++;
					continue;
				}
				if(arr[ny][nx]==curColor) {
					flag=true;
					cnt--;
					break;
				}
			} 
			if(flag) {
				for(int i=1;i<=cnt;i++) {
					int ny = y + dy[idx] * i;
					int nx = x + dx[idx] * i;
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
			arr[(n-1)/2][(n-1)/2]=2;
			arr[n/2][n/2]=2;
			arr[(n-1)/2][n/2]=1;
			arr[n/2][(n-1)/2]=1;
			for(int i=0;i<m;i++) {
				int q = sc.nextInt();
				int w = sc.nextInt();
				arr[q-1][w-1] = sc.nextInt();
				if(arr[q-1][w-1]==0)continue;
				go(arr,q-1,w-1);
			}
			count(arr);
			System.out.println("#" + test + " " + bl + " " + wh);
		}
	}
}
