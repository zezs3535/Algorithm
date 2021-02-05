package Algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA5215_햄버거다이어트 {
	static int n;
	static int limitCal;
	static boolean[] isSelected;
	static int answer;
	static class Burger {
		int taste;
		int cal;

		Burger(int taste, int cal) {
			this.taste = taste;
			this.cal = cal;
		}
	}

	static void ps(Burger[] burger, int cnt) {
		if (cnt == n) {
			int trueCal = 0;
			int trueTaste = 0;
			int falseCal = 0;
			int falseTaste = 0;
			for (int i = 0; i < n; i++) {
				if (isSelected[i]) {
					trueCal += burger[i].cal;
					trueTaste += burger[i].taste;
				} else {
					falseCal += burger[i].cal;
					falseTaste += burger[i].taste;
				}
			}
			if(trueCal<=limitCal)answer = Math.max(trueTaste, answer);
			if(falseCal<=limitCal)answer = Math.max(falseTaste, answer);
			return;
		}
		isSelected[cnt] = true;
		ps(burger, cnt + 1);
		isSelected[cnt] = false;
		ps(burger, cnt + 1);
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			answer=0;
			n = sc.nextInt();
			limitCal = sc.nextInt();
			Burger[] burger = new Burger[n];
			isSelected = new boolean[n];
			for (int i = 0; i < n; i++) {
				int q = sc.nextInt();
				int w = sc.nextInt();
				burger[i] = new Burger(q, w);
			}
			ps(burger, 0);
			System.out.println("#"+t+" "+answer);
		}
	}

}
