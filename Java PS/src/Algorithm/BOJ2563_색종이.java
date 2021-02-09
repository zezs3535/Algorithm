package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2563_색종이 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[][] arr = new int[101][101];
		int answer=0;
		int n = Integer.parseInt(st.nextToken());
		for(int t=0;t<n;t++) {
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			for(int i=y;i<y+10;i++) {
				for(int j=x;j<x+10;j++) {
					arr[i][j]=1;
				}
			}
		}
		for(int i=1;i<=100;i++) {
			for(int j=1;j<=100;j++) {
				answer+=arr[i][j];
			}
		}
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}

}
