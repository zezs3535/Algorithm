package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA5604_구간합 {

	static long[] score;
	static long a, b;

	static void calc(long num, long point) {
		while (num > 0) {
			score[(int) (num % 10)] += point;
			num /= 10;
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			score = new long[10];
			a = sc.nextLong();
			b = sc.nextLong();
			long point = 1;
			while (a <= b) {
				while (b % 10 != 9 && a <= b) {
					calc(b, point);
					b--;
				}
				if (a > b)
					break;
				while (a % 10 != 0 && a <= b) {
					calc(a, point);
					a++;
				}
				a /= 10;
				b /= 10;
				for (int i = 0; i < 10; i++) {
					score[i] += (b - a + 1) * point;
				}
				point *= 10;
			}
			long sum=0;
			for(int i=0;i<10;i++) {
				sum+=(score[i]*i);
			}
			System.out.println("#" + test+" "+sum);
		}
	}
}
