package Algorithm;

import java.util.Arrays;
import java.util.Scanner;
/**
 * 
 * 
 * 조합으로 풀어보기
 * @author zezs3535
 *
 */
public class SWEA5215_햄버거다이어트2 {
	static int n;
	static int limitCal;
	static int answer;
	static class Burger {
		int taste;
		int cal;

		Burger(int taste, int cal) {
			this.taste = taste;
			this.cal = cal;
		}
	}

	static void comb(Burger[] burger, int idx, int cnt, Burger[] sel) {
		if(cnt==sel.length) {
			int totalCal=0;
			int totalTaste=0;
			for(int i=0;i<sel.length;i++) {
				totalCal+=sel[i].cal;
				totalTaste+=sel[i].taste;
				if(totalCal>limitCal)return;
			}
			answer = Math.max(totalTaste, answer);
			return;
		}
		for(int i=idx;i<n;i++) {
			sel[cnt]=burger[i];
			comb(burger,i+1,cnt+1,sel);
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			answer=0;
			n = sc.nextInt();
			limitCal = sc.nextInt();
			Burger[] burger = new Burger[n];
			
			for (int i = 0; i < n; i++) {
				int q = sc.nextInt();
				int w = sc.nextInt();
				burger[i] = new Burger(q, w);
			}
			for(int i=1;i<=n;i++) {
				comb(burger,0,0,new Burger[i]);
			}
			System.out.println("#"+t+" "+answer);
		}
	}

}
