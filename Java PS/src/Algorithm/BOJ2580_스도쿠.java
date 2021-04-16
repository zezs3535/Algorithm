package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ2580_스도쿠 {
	static int[][] arr;
	static int[][] rowcheck;
	static int[][] colcheck;
	static int[][] sqcheck;
	static ArrayList<int[]> pos = new ArrayList<>();
	
	static void dfs(int idx) throws Exception{
		if(idx == pos.size()){
			for(int i=1;i<=9;i++) {
				for(int j=1;j<=9;j++) {
					System.out.print(arr[i][j]+" ");
				}
				System.out.println();
			}
			System.exit(0);
		}
		int cy = pos.get(idx)[0];
		int cx = pos.get(idx)[1];
		for(int i=1;i<=9;i++) {
			if(chk(cy,cx,i)) {
				arr[cy][cx]=i;
				dfs(idx+1);
				arr[cy][cx]=0;
			}
		}
	}
	
	static boolean chk(int y, int x, int num) {
		for(int i=1;i<=9;i++) {
			if(arr[y][i]==num)return false;
			if(arr[i][x]==num)return false;
		}
		int r = ((y-1)/3)*3+1;
		int c = ((x-1)/3)*3+1;
		for(int ny=r;ny<r+3;ny++) {
			for(int nx=c;nx<c+3;nx++) {
				if(arr[ny][nx]==num)return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		arr = new int[10][10];

		for (int i = 1; i <= 9; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= 9; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j]==0)pos.add(new int[] {i,j});
			}
		}
		
		dfs(0);
		
		br.close();
	}
}
