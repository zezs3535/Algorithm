package Algorithm;

import java.util.Scanner;

public class SWEA1959_두개의숫자열 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int answer = 0;
			int[] arrA = new int[a];
			int[] arrB = new int[b];
			for (int i = 0; i < a; i++) {
				arrA[i] = sc.nextInt();
			}
			for (int i = 0; i < b; i++) {
				arrB[i] = sc.nextInt();
			}
			int big = Math.max(a, b);
			int small = Math.min(a, b);
			int[] arrBig = new int[big];
			int[] arrSmall = new int[small];
			for (int i = 0; i < big; i++) {
				if (a > b) {
					arrBig[i] = arrA[i];
				} else {
					arrBig[i] = arrB[i];
				}
			}
			for (int i = 0; i < small; i++) {
				if (a < b) {
					arrSmall[i] = arrA[i];
				} else {
					arrSmall[i] = arrB[i];
				}
			}
			for (int i = 0; i <= big - small; i++) {
				int sum = 0;
				for (int j = 0; j < small; j++) {
					sum += (arrBig[i + j] * arrSmall[j]);
					//System.out.println(arrBig[i + j] + " " + arrSmall[j]);
				}

				answer = Math.max(answer, sum);
			}
			System.out.println("#"+t+" "+answer);
		}
	}
}
