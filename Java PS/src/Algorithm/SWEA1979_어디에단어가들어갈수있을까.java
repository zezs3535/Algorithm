package Algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA1979_어디에단어가들어갈수있을까 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			int answer = 0;
			int[][] arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			for (int i = 0; i < n; i++) {
				int rowcnt=0;
				int colcnt=0;
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 1) {
						rowcnt++;
					}
					else {
						if(rowcnt==k)answer++;
						rowcnt=0;
					}
					if(arr[j][i]==1) {
						colcnt++;
					}
					else {
						if(colcnt==k)answer++;
						colcnt=0;
					}
				}
				if(rowcnt==k)answer++;
				if(colcnt==k)answer++;
				rowcnt=0;
				colcnt=0;
			}
			System.out.println("#" + t + " " + answer);
		}
	}
}
