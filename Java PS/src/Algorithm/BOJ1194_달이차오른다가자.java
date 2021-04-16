package Algorithm;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ1194_달이차오른다가자 {
	static char[][] arr;
	static int n, m;
	static int[] dy = {0,1,0,-1};
	static int[] dx = {1,0,-1,0};
	static int[][][] v;
	
	static Queue<Pos> q = new LinkedList<>();

	static class Pos {
		int y;
		int x;
		int dis;
		int key;

		public Pos(int y, int x, int dis, int key) {
			super();
			this.y = y;
			this.x = x;
			this.dis = dis;
			this.key = key;
		}

	}

	static void bfs() {
		while(!q.isEmpty()) {
			Pos cur = q.poll();
			int cy = cur.y;
			int cx = cur.x;
			int cdis = cur.dis;
			int ckey = cur.key;
			System.out.println(cy+" "+cx+" "+cdis+" "+ckey);
			for(int idx=0;idx<4;idx++) {
				int ny = cy+dy[idx];
				int nx = cx+dx[idx];
				if(ny>=n || ny<0 || nx>=m || nx<0 || arr[ny][nx]=='#' ||v[ckey][ny][nx]==1)continue;
				if(arr[ny][nx]=='1') { //탈출
					System.out.println(cdis+1);
					System.exit(0);
				}
				if(arr[ny][nx]>='a' && arr[ny][nx]<='f') { //key이면
					q.add(new Pos(ny,nx,cdis+1,ckey|(1<<arr[ny][nx]-'a')));
				}
				if(arr[ny][nx]>='A' && arr[ny][nx]<='F') { //door이면
					if((ckey&(1<<(arr[ny][nx]-'A')))==(1<<(arr[ny][nx]-'A'))) { //key가 있으면
						v[ckey][ny][nx]=1;
						q.add(new Pos(ny,nx,cdis+1,ckey));
					}
					else {
						continue;
					}
				}
				else {
					v[ckey][ny][nx]=1;
					q.add(new Pos(ny,nx,cdis+1,ckey));
				}
			}
		}
		System.out.println("-1");
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new char[n][m];
		v = new int[65][n][m];
		
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < m; j++) {
				arr[i][j] = s.charAt(j);
				if (arr[i][j] - '0' == 0)
					q.add(new Pos(i, j, 0, 0));
			}
		}
		bfs();
		br.close();
	}
}
