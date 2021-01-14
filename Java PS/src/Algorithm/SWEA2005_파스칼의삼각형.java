package Algorithm;

import java.util.Scanner;

public class SWEA2005_파스칼의삼각형 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 0; test < t; test++) {
			int n = sc.nextInt();
			int[][] arr = new int[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<=i;j++) {
					if(j==0 || i==j)arr[i][j]=1;
					else {
						arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
					}
				}
			}
			System.out.println("#" + (test + 1));
			for(int i=0;i<n;i++) {
				for(int j=0;j<=i;j++) {
					System.out.print(arr[i][j]+" ");
				}
				System.out.println();
			}
		}
	}
}
