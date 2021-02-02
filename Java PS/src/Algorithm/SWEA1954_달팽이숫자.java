package Algorithm;

import java.util.Scanner;

public class SWEA1954_달팽이숫자 {
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static int t;
	static void snail(int[][] arr, int n, int y, int x, int dir, int cnt) {
		if(dir==0 && y==0 && x==n-1) {
			dir=1;
		}
		else if(dir==1 && y==n-1 && x==n-1) {
			dir=2;
		}
		else if(dir==2 && y==n-1 && x==0) {
			dir=3;
		}
		else if(dir==3 && y==0 && x==0) {
			dir=4;
		}
		arr[y][x]=cnt;
		if(cnt==n*n) {
			System.out.println("#"+t);
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					System.out.print(arr[i][j]+" ");
				}
				System.out.println();
			}
			return;
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(arr[ny][nx]!=0) {
			dir=(dir+1)%4;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}
		snail(arr,n,ny,nx,dir,cnt+1);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for(t=1;t<=test;t++) {
			int n = sc.nextInt();
			int[][] arr = new int[n][n];
			snail(arr, n, 0, 0, 0, 1);
		}
	}

}
