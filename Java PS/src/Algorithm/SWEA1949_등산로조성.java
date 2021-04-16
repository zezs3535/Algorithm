package Algorithm;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA1949_등산로조성 {
	static int[][] arr;
	static int n,k;
	static int ans;
	static int[] dy = {0,1,0,-1};
	static int[] dx = {1,0,-1,0};
	static class Pos{
		int y;
		int x;
		int dis;
		/**
		 * @param y
		 * @param x
		 * @param dis
		 */
		public Pos(int y, int x, int dis) {
			super();
			this.y = y;
			this.x = x;
			this.dis = dis;
		}
		
	}
	static void bfs(int y, int x) {
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(y,x,1));
		while(!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			int cdis = q.peek().dis;
			ans=Math.max(ans, cdis);
			q.poll();
			for(int idx=0;idx<4;idx++) {
				int ny = cy + dy[idx];
				int nx = cx + dx[idx];
				if(ny>=n || ny<0 || nx>=n || nx<0 || arr[ny][nx] >= arr[cy][cx])continue;
				q.add(new Pos(ny,nx,cdis+1));
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			ArrayList<int[]> q = new ArrayList<>();
			n = sc.nextInt();
			k = sc.nextInt();
			arr = new int[n][n];
			ans=0;
			int maxnum=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr[i][j]=sc.nextInt();
					maxnum=Math.max(maxnum, arr[i][j]);
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(arr[i][j]==maxnum)q.add(new int[] {i,j});
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					for(int h=0;h<k;h++) {
						arr[i][j]--;
						for(int idx=0;idx<q.size();idx++) {
							int cy = q.get(idx)[0];
							int cx = q.get(idx)[1];
							bfs(cy,cx);
						}
					}
					arr[i][j]+=k;
				}
			}
			System.out.println("#"+test+" "+ans);
		}
	}
}
