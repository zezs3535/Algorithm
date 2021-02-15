package Algorithm;

import java.util.Scanner;

public class BOJ3040_백설공주와일곱난쟁이 {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[9];
		int sum = 0;
		int fake1 = 0;
		int fake2 = 0;
		for (int i = 0; i < 9; i++) {
			arr[i] = sc.nextInt();
			sum += arr[i];
		}
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (sum - arr[i] - arr[j] == 100) {
					fake1 = i;
					fake2 = j;
					break;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			if (i == fake1 || i == fake2)continue;
			System.out.println(arr[i]);
		}
	}

}
