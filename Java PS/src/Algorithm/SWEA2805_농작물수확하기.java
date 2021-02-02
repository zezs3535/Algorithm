package Algorithm;

import java.util.Scanner;

public class SWEA2805_농작물수확하기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int n = sc.nextInt();
			int answer = 0;
			int[][] arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < n; j++) {
					arr[i][j] = s.charAt(j) - '0';
				}
			}
			for (int i = 0; i <= (n / 2); i++) {
				for (int j = (n / 2) - i; j <= (n / 2) + i; j++) {
					answer += arr[i][j];
				}
			}
			for (int i = (n / 2) - 1; i >= 0; i--) {
				for (int j = (n / 2) - i; j <= (n / 2) + i; j++) {
					answer += arr[n-1-i][j];
				}
			}
			System.out.println("#" + test + " " + answer);
		}
	}
}
