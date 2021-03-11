package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ16236_아기상어 {
	static int[][] arr;
	static int n;
	static int feed=0;
	static int ret=0;
	static Pos sharkPos;
	static int sharkSize=2;
	static int[] dy = {1,0,-1,0};
	static int[] dx = {0,1,0,-1};
	static ArrayList<Fish> fishPos = new ArrayList<>();
	static class Fish implements Comparable<Fish> {
		int y;
		int x;
		int dis;

		Fish() {

		}

		public Fish(int y, int x, int dis) {
			this.y = y;
			this.x = x;
			this.dis = dis;
		}
		
		@Override
		public int compareTo(Fish o2) {
			if (this.dis == o2.dis) {
				if (this.y == o2.y)return this.x - o2.x;
				return this.y - o2.y;
			}
			return this.dis - o2.dis;
		}
	}

	static class Pos {
		int y;
		int x;

		Pos() {

		}

		Pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
	static void canEatFish() {
		int cnt=0;
		int[][] visit = new int[n][n];
		int[][] distance = new int[n][n];
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(sharkPos.y,sharkPos.x));
		while(!q.isEmpty()) {
			Pos cur = q.poll();
			visit[cur.y][cur.x]=1;
			cnt++;
			for(int idx=0;idx<4;idx++) {
				int ny = dy[idx]+cur.y;
				int nx = dx[idx]+cur.x;
				if(ny>=n || nx>=n || ny<0 || nx<0 || visit[ny][nx]==1)continue;
				if(arr[ny][nx]>sharkSize)continue;
				if(arr[ny][nx]!=0&&arr[ny][nx]<sharkSize) {
					fishPos.add(new Fish(ny,nx,distance[cur.y][cur.x]+1));
				}
				q.add(new Pos(ny,nx));
				visit[ny][nx]=1;
				distance[ny][nx]=distance[cur.y][cur.x]+1;
			}
		}
	}
	static void eatFish() {
		while(true) {
			if(fishPos.isEmpty())break;
			Collections.sort(fishPos);
			ret+=fishPos.get(0).dis;
			feed++;
			arr[sharkPos.y][sharkPos.x]=0;
			arr[fishPos.get(0).y][fishPos.get(0).x]=0;
			sharkPos.y=fishPos.get(0).y;
			sharkPos.x=fishPos.get(0).x;
			if(sharkSize==feed) {
				feed=0;
				sharkSize++;
			}
			fishPos.clear();
			canEatFish();
		}
	}
	public static void main(String[] args) throws Exception {
		//System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 9) {
					sharkPos = new Pos(i, j);
				}
			}
		}
		canEatFish();
		eatFish();
		bw.write(ret + " ");
		br.close();
		bw.flush();
		bw.close();
	}
}
