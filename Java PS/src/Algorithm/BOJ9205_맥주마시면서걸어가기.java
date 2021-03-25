package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ9205_맥주마시면서걸어가기 {
	static class Node{
		int y;
		int x;
		public Node(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
		
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for (int test = 1; test <= t; test++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			n+=2;
			Node[] node = new Node[n];
			int[][] arr = new int[n][n];
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				node[i] = new Node(y,x);
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(i==j)continue;
					arr[i][j]=Math.abs(node[i].x-node[j].x)+Math.abs(node[i].y-node[j].y);
					if(arr[i][j]>1000)arr[i][j]=Integer.MAX_VALUE;
				}
			}
			for(int k=0;k<n;k++) {
				for(int i=0;i<n;i++) {
					for(int j=0;j<n;j++) {
						if(arr[i][k]==Integer.MAX_VALUE || arr[k][j]==Integer.MAX_VALUE)continue;
						arr[i][j]=Math.min(arr[i][j], arr[i][k]+arr[k][j]);
					}
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					bw.write(arr[i][j]+" ");
				}
				bw.write("\n");
			}
			if(arr[0][n-1]!=Integer.MAX_VALUE) {
				bw.write("happy");
				bw.write("\n");
			}
			else {
				bw.write("sad");
				bw.write("\n");
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}
}