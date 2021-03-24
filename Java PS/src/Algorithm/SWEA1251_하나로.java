package Algorithm;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class SWEA1251_하나로 {
	static class Pos{
		double y;
		double x;
		public Pos(double y, double x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	static class Edge implements Comparable<Edge>{
		int e;
		double w;
		
		public Edge(int e, double w) {
			super();
			this.e = e;
			this.w = w;
		}

		@Override
		public int compareTo(Edge o) {
			return Double.compare(this.w, o.w);
		}
	}
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int n =sc.nextInt();
			int[][] inputV = new int[2][n];
			Pos[] vertex = new Pos[n];
			double answer = 0;
			boolean[] visited = new boolean[n];
			ArrayList<Edge>[] edge = new ArrayList[n];
			PriorityQueue<Edge> pq = new PriorityQueue<>();
			for(int i=1;i>=0;i--) {
				for(int j=0;j<n;j++) {
					inputV[i][j]=sc.nextInt();
				}
			}
			double rate = sc.nextDouble();
			for(int i=0;i<n;i++) {
				edge[i] = new ArrayList<>();
				vertex[i] = new Pos(inputV[0][i],inputV[1][i]);
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(i==j)continue;
					edge[i].add(new Edge(j,Math.sqrt(Math.pow(vertex[i].y-vertex[j].y,2)+Math.pow(vertex[i].x-vertex[j].x,2))));
				}
			}
			visited[0]=true;
			for(Edge e : edge[0])pq.add(e);
			while(!pq.isEmpty()) {
				Edge cur = pq.poll();
				if(visited[cur.e])continue;
				visited[cur.e]=true;
				answer+=(cur.w*cur.w)*rate;
				
				for(Edge e : edge[cur.e])pq.add(e);
			}
			System.out.println("#"+test+" "+Math.round(answer));
		}
	}
}
