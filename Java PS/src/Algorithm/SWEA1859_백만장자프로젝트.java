package Algorithm;

import java.util.Scanner;

public class SWEA1859_백만장자프로젝트 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			Long sum = 0L;
			int[] arr = new int[n];
			for(int j=0;j<n;j++) {
				arr[j]=sc.nextInt();
			}
			int len = arr.length;
			int key = arr[len - 1];
			for (int j = len - 2; j >= 0; j--) {
				if (arr[j] < key) {
					sum += (key - arr[j]);
				} else {
					key = arr[j];
				}
			}
			System.out.println("#" + (i + 1) + " " + sum);
		}
	}
}
