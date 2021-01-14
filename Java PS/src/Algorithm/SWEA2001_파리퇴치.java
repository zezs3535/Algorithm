package Algorithm;

import java.util.Scanner;

public class SWEA2001_파리퇴치 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 0; t < test; t++) {
			int answer = 0;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] arr = new int[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr[i][j]=sc.nextInt();
				}
			}
			for (int i = 0; i < n-(m-1); i++) {
				for (int j = 0; j < n-(m-1); j++) {
					answer = Math.max(answer, killBug(arr,i,j,m));
				}
			}
			System.out.println("#" + (t + 1) + " " + answer);
		}
	}
	
	static int killBug(int[][] arr, int y, int x, int size) {
		int killCnt=0;
		for(int i=y;i<size+y;i++) {
			for(int j=x;j<size+x;j++) {
				killCnt+=arr[i][j];
			}
		}
		return killCnt;
	}
}
