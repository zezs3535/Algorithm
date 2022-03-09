package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ2960_에라토스테네스의체 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();

		int cnt = 0;
		int ans = 0;
		boolean flag = false;

		int[] arr = new int[n + 1];
		for (int i = 2; i <= n; i++) {
			arr[i] = i;
		}

		for (int i = 2; i <= n; i++) {
			if (arr[i] != 0) {
				for (int j = 1; i * j <= n; j++) {
					if (arr[j * i] == 0)
						continue;
					arr[j * i] = 0;
					cnt++;
					if (k == cnt) {
						ans = j * i;
						flag = true;
						break;
					}
				}
				if(flag)break;
			}
		}
		System.out.println(ans);
	}
}
