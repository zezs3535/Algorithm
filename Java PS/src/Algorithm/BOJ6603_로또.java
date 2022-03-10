package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ6603_로또 {

	static int[] num;
	static int[] pick;
	static boolean[] isPick;

	static void comb(int idx) {
		if (idx == 6) { // 출력조건
			for(int i=0;i<5;i++) {
				if(pick[i]>pick[i+1])return;
			}
			for (int i = 0; i < 6; i++) {
				System.out.print(pick[i]+" ");
			}
			System.out.println();
			return;
		}
		
		for(int i=0;i<num.length;i++) {
			if(!isPick[i]) { //안뽑았으면
				pick[idx] = num[i];
				isPick[i]=true;
				comb(idx+1);
				isPick[i]=false;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		while (true) {
			int k = sc.nextInt(); // k만큼의 수 중에 6개 선택
			if (k == 0)
				break; // 탈출조건
			num = new int[k];
			pick = new int[6];
			isPick = new boolean[k];
			for (int i = 0; i < k; i++) {
				num[i] = sc.nextInt();
			}
			comb(0);
			System.out.println();
		}
	}
}
