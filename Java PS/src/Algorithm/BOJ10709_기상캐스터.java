package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ10709_기상캐스터 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			String tmp = sc.next();
			for (int j = 0; j < m; j++) {
				if (tmp.charAt(j) == 'c')
					arr[i][j] = 0;
				else {
					arr[i][j] = -1;
				}
			}
		}

		int cnt=0;
		
		for (int i = 0; i < n; i++) {
			cnt=0;
			for (int j = 0; j < m; j++) {
				if(arr[i][j]==0)cnt=1;
				if(arr[i][j]==-1 && cnt>0) {
					arr[i][j]=cnt;
					cnt++;
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}
}
