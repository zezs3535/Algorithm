package Algorithm;

import java.util.Scanner;

public class SWEA1961_숫자배열회전 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			int n = sc.nextInt();
			int[][] arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			System.out.println("#"+t);
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					System.out.print(arr[n-1-j][i]);
				}
				System.out.print(" ");
				for(int j=0;j<n;j++) {
					System.out.print(arr[n-1-i][n-1-j]);
				}
				System.out.print(" ");
				for(int j=0;j<n;j++) {
					System.out.print(arr[j][n-1-i]);
				}
				System.out.println();
			}
		}
	}
}
