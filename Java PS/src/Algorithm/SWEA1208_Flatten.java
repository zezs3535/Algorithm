package Algorithm;

import java.util.Scanner;

public class SWEA1208_Flatten {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= 10; t++) {
			int n = sc.nextInt(); // dump 횟수
			int width = 100;
			int maxIdx = 0;
			int minIdx = 0;
			int[] arr = new int[width];
			for (int i = 0; i < width; i++) {
				arr[i] = sc.nextInt();
			}
			for (int i = 0; i < n; i++) { // 평탄화
				maxIdx=0;
				minIdx=0;
				for (int j = 0; j < 100; j++) {
					if (arr[j] > arr[maxIdx]) {
						maxIdx = j;
					}
					if (arr[j] < arr[minIdx]) {
						minIdx = j;
					}
				}
				arr[maxIdx]--;
				arr[minIdx]++;
				if (arr[maxIdx] - arr[minIdx] <2) {
					break;
				}
			}
			maxIdx=0;
			minIdx=0;
			for(int i=0;i<100;i++) {
				if(arr[i]>arr[maxIdx])maxIdx=i;
				if(arr[i]<arr[minIdx])minIdx=i;
			}
			System.out.println("#" + t + " " + (arr[maxIdx] - arr[minIdx]));
		}
	}
}
