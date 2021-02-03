package Algorithm;

import java.util.Scanner;

public class SWEA1247_최적경로 {
	static int n;
	static int[] arr;
	static int[] num;
	static int answer;
	static boolean[] v;

	static class Pos {
		int y;
		int x;

		Pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	static Pos home;
	static Pos company;

	static void permu(Pos[] customer, int k) {
		if (k == n) {
			int dis = 0;
			dis += (Math.abs(customer[arr[0]].y - company.y));
			dis += (Math.abs(customer[arr[0]].x - company.x));
			dis += (Math.abs(customer[arr[n - 1]].y - home.y));
			dis += (Math.abs(customer[arr[n - 1]].x - home.x));
			for (int i = 1; i < n; i++) {
				dis += (Math.abs(customer[arr[i]].y - customer[arr[i-1]].y));
				dis += (Math.abs(customer[arr[i]].x - customer[arr[i-1]].x));
			}
			answer = Math.min(dis, answer);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!v[i]) {
				v[i] = true;
				arr[k] = num[i];
				permu(customer, k + 1);
				v[i] = false;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			answer = 999999;
			n = sc.nextInt();
			arr = new int[n];
			num = new int[n];
			v = new boolean[n];
			for (int i = 0; i < n; i++) {
				num[i] = i;
			}
			home = new Pos(sc.nextInt(), sc.nextInt());
			company = new Pos(sc.nextInt(), sc.nextInt());
			Pos[] customer = new Pos[n];
			for (int i = 0; i < n; i++) {
				customer[i] = new Pos(sc.nextInt(), sc.nextInt());
			}
			permu(customer, 0);
			System.out.println("#"+test+" "+answer);
		}

	}

}
