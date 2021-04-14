package Algorithm;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA5656_벽돌깨기 {
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	static int n,m,t;
	static int totalBrick=0;
	static int answer;
	static void shoot(int[][] arr, int shootCnt, int shootIdx, int brickCnt) {
		boolean[][] v = new boolean[n][m];
		int[][] tmp = new int[15][12];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				tmp[i][j]=arr[i][j];
			}
		}
		if(shootCnt==t || brickCnt==totalBrick) {
			answer = Math.min(answer, totalBrick-brickCnt);
			return;
		}
		Queue<int[]> q = new LinkedList<>();
		int[] cur = {0,shootIdx};
		int bCnt=0;
		while(true) {
			if(cur[0]>=n) {
				return;
			}
			if(tmp[cur[0]][cur[1]]!=0) {
				q.add(cur);
				break;
			}
			cur[0]+=1;
		}
		while(!q.isEmpty()) {
			cur = q.poll();
			int len = tmp[cur[0]][cur[1]];
			tmp[cur[0]][cur[1]]=0;
			bCnt++;
			v[cur[0]][cur[1]]=true;
			for(int idx=0;idx<4;idx++) {
				for(int i=1;i<len;i++) {
					int ny = cur[0]+dy[idx]*i;
					int nx=cur[1]+dx[idx]*i;
					if(ny>=n || ny <0 || nx>=m||nx<0)break;
					if(v[ny][nx])continue;
					if(tmp[ny][nx]==0)continue;
					if(tmp[ny][nx]!=0) {
						q.add(new int[] {ny,nx});
						v[ny][nx]=true;
					}
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				v[i][j]=false;
			}
		}
		Queue<Integer> g = new LinkedList<>();
		for(int j=0;j<m;j++) {
			for(int i=n-1;i>=0;i--) {
				if(tmp[i][j]!=0) {
					g.add(tmp[i][j]);
					tmp[i][j]=0;
				}
			}
			int idx=n-1;
			while(!g.isEmpty()) {
				tmp[idx][j]=g.peek();
				g.poll();
				idx--;
			}
		}
		for(int i=0;i<m;i++) {
			shoot(tmp,shootCnt+1,i,brickCnt+bCnt);
		}
	}
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int test = 1; test <= tc; test++) {
			totalBrick = 0;
			answer = Integer.MAX_VALUE;
			t=sc.nextInt();
			m=sc.nextInt();
			n=sc.nextInt();
			int[][] arr = new int[15][12];
			int[][] tmp = new int[15][12];
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					arr[i][j] = sc.nextInt();
					if(arr[i][j]!=0)totalBrick++;
				}
			}
			if(totalBrick==0) {
				System.out.println("#"+test+" 0");
				continue;
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					tmp[i][j]=arr[i][j];
				}
			}
			for(int j=0;j<m;j++)shoot(tmp,0,j,0);
			System.out.println("#"+test+" "+answer);
		}
	}
}
